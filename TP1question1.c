//Travail Bilal Bachiri et Brau tristan



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define PROMPT "enseah %"



int main() {
    write(1,"Bienvenue dans le Shell ENSEA.\n",sizeof("Bienvenue dans le Shell ENSEA."));
    write(1,"Pour quitter, tapez 'exit'.\n",sizeof("Pour quitter, tapez 'exit'."));
    write(1, PROMPT, sizeof(PROMPT));


    return 0;
}