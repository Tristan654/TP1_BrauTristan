//travail Bilal Bachiri et Brau Tristan


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define Max_size_command 1024
#define PROMPT "enseah %"


void loop(void){
  // size max of the command
  char command[Max_size_command];
  
    do{
    write(STDERR_FILENO, PROMPT, sizeof(PROMPT));

    // write a command
    if (fgets(command, sizeof(command), stdin) == NULL) { // like gets allow to read a line write from the keyboard(stdin) until you reach the size given.
        break; 
    }

    // leave if the command is "exit"
    if (strcmp(command, "exit\n") == 0) { // strcmp allow to compare  command and the word exit if there are equal you do the condition 
        write(STDERR_FILENO,"Au revoir\n", sizeof("Au revoir"));
        break;
    }

}while(1);}




int main(int argc, char *argv) {
    write(1,"Bienvenue dans le Shell ENSEA.\n",sizeof("Bienvenue dans le Shell ENSEA."));
    write(1,"Pour quitter, tapez 'exit'.\n",sizeof("Pour quitter, tapez 'exit'."));


    // run function loop.
    loop();

    return 0;
}