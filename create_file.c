#include <stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>

void create_directory(char directory_name[]){
    mkdir(directory_name,0777);

}

void create_file(char string[]){
    FILE *fptr = NULL;

    fptr=fopen(string,"r");

    if(fptr!=NULL){
        perror("Error");
    }
    else{
        fptr=fopen(string,"w");
        fclose(string);
    }
}

int main() {

char dir[100];
scanf("%s",dir);
create_directory(dir);
}
