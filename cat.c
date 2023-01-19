#include <stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>

void cat(char file_name[]){

    FILE *fptr;

    char c;

    // Open file
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("This file hasn't existed\n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
    printf ("%c", c);
    c = fgetc(fptr);
    }

    fclose(fptr);

}

int main() {

    char file_name[100];

    scanf("%s", file_name);

    cat(file_name);

}

