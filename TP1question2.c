#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

int main() {
display_welcome_message();


while (1) {
    char command[MSG_MAX_LENGTH];

    display_prompt();

    ssize_t entry_bytes = read_command(command); 

}

return 0;
}