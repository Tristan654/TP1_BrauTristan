//travail Bilal Bachiri et Brau Tristan


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>

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

        char *args[] = {"/bin/sh", "-c", (char *)command, NULL};// this line allow to execute the command in the shell
        
        //before execv the child process execute the code
        execv(args[0], args); //after execv the child process execute the shell 
        

    } else if (ret > 0) {
        //parent process
        int Statu_process;
        waitpid(ret, &Statu_process, 0); // wait for the child process to finish

        if (WIFEXITED(Statu_process)) {//verify if the child process is finished normally 
            int exit_code = WEXITSTATUS(Statu_process);//return code
            char exit_message[50];
            snprintf(exit_message, sizeof(exit_message), "[exit:%d] ", exit_code);//use a buffer to format the message [exit:%d] without outstrip the lenght  
            write(STDOUT_FILENO, exit_message, strlen(exit_message));
        } else if (WIFSIGNALED(Statu_process)) {
            int signal_num = WTERMSIG(Statu_process);
            char signal_message[50];
            snprintf(signal_message, sizeof(signal_message), "[sign:%d] ", signal_num);
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