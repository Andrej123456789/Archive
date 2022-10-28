/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: atomic, atomic chess in terminal
 * LICENSE: ringwormGO General License 1.0 | (RGL) 2022
 * DESCRIPTION: main.c, entry point for the program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* logo_row1 = "       _                  _       \n";
const char* logo_row2 = "      | |                (_)      \n";
const char* logo_row3 = "  __ _| |_ ___  _ __ ___  _  ___  \n";
const char* logo_row4 = " / _` | __/ _ \\| '_ ` _ \\| |/ __| \n";
const char* logo_row5 = "| (_| | || (_) | | | | | | | (__  \n";
const char* logo_row6 = " \\__,_|\\__\\___/|_| |_| |_|_|\\___| \n";
const char* logo_row7 = "                                  \n";

char logo[1];

int main()
{
    strcat(logo, logo_row1);
    strcat(logo, logo_row2);
    strcat(logo, logo_row3);
    strcat(logo, logo_row4);
    strcat(logo, logo_row5);
    strcat(logo, logo_row6);
    strcat(logo, logo_row7);
    printf("%s\n", logo);
    printf("Welcome to atomic chess implementation in terminal!\n");

    return 0;
}
