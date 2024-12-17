//travail Bilal Bachiri et Brau Tristan


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <time.h>

#define MSG_MAX_LENGTH 256

// display the welcome message without printf
void display_welcome_message() {
    const char *welcome_message = "$ ./enseash\nWelcome to ENSEA Tiny Shell.\nType 'exit' to quit.\n";
    write(STDOUT_FILENO, welcome_message, strlen(welcome_message));
}

// display the prompt to indicate to the user that he can enter a command
void display_prompt() {
    write(STDOUT_FILENO, "enseash % ", 10);
    
}

// read the user's command
ssize_t read_command(char *command) {
    
    return read(STDIN_FILENO, command, MSG_MAX_LENGTH - 1);
    
}


void process_command(const char *command) {

    //// we verify if user type exit
    if (strcmp(command, "exit") == 0) {
        write(STDOUT_FILENO, "Ciao...\n", 8);
        exit(0);
    }



    //display the return code
    pid_t ret = fork(); 

    if (ret == 0) {
        //if ret == 0 we recognize the command and we go in the child process we allow to execute the command in parallel and once the commmand is finish 
        //we go back in the parent processus

        
        
        //before execlp the child process execute the code
        execlp(command ,command,(char*)NULL); //after execlp the child process execute the shell 
        perror("execlp error");
        exit(1);

    } else if (ret > 0) {
                // This is the parent process
        int Statu_process;
        struct timespec start, end;

        clock_gettime( CLOCK_MONOTONIC, &start); // Start timer
        waitpid(ret, &Statu_process, 0); // wait for the child process to finish
        clock_gettime(CLOCK_MONOTONIC, &end); // End timer

        //calculated the time for the command to be execute
        long elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

        if (WIFEXITED(Statu_process)) {
            int exit_code = WEXITSTATUS(Statu_process);
            char exit_message[50];
            snprintf(exit_message, sizeof(exit_message),"[exit:%d|%ldms] ", exit_code, elapsed_ms);
            write(STDOUT_FILENO, exit_message, strlen(exit_message));
        } else if (WIFSIGNALED(Statu_process)) {
            int signal_num = WTERMSIG(Statu_process);
            char signal_message[50];
            snprintf(signal_message, sizeof(signal_message), "[sign:%d|%ldms] ", signal_num, elapsed_ms);
            write(STDOUT_FILENO, signal_message, strlen(signal_message));
        }

    } else {
        // Fork failed
        perror("fork failed");
    }
}

int main() {
display_welcome_message();

while (1) {
    char command[MSG_MAX_LENGTH];

    display_prompt();
   

    ssize_t entry_bytes = read_command(command); 
    
    

    if (entry_bytes <= 0) { // if the user press ctrl + D, entry_bytes = 0 so we exit
        write(STDOUT_FILENO, "Ciao...\n", 8);
        break;
    }

    command[strcspn(command, "\n")] = 0;//allow to remove the last caracter that create a new line.

    process_command(command); }
    
return 0;
}