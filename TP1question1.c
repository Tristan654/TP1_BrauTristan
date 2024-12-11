#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define PROMPT "enseah %"



int main() {
    write(STDERR_FILENO,"Bienvenue dans le Shell ENSEA.\n",sizeof("Bienvenue dans le Shell ENSEA."));
    write(STDERR_FILENO,"Pour quitter, tapez 'exit'.\n",sizeof("Pour quitter, tapez 'exit'."));
    write(STDERR_FILENO, PROMPT, sizeof(PROMPT));


    return 0;
}