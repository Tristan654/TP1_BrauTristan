#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define Max_size_command 1024
#define Prompt "enseah %"


void loop(void){
  // size max of the command
  char message[Max_size_command];
  
    do{
    write(1, Prompt, sizeof(Prompt));

    // write a command
    if (fgets(message, sizeof(message), stdin) == NULL) { // like gets allow to read a line write from the keyboard(stdin) until you reach the size given.
        break; 
    }


}while(1);}




int main() {
    write(1,"Bienvenue dans le Shell ENSEA.\n",sizeof("Bienvenue dans le Shell ENSEA."));
    write(1,"Pour quitter, tapez 'exit'.\n",sizeof("Pour quitter, tapez 'exit'."));


    // run function loop.
    loop();

    return 0;
}