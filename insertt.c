#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>


int main(){

	FILE* ptr;
	char ch;
    char str_copy1[1000000];
    char str_copy2[1000000];
    char str_insert[1000000];
    char file_name[100];
    int entered_line,entered_character;
    scanf("%s",file_name);

    scanf("%d %d",&entered_line,&entered_character);

    int h=0;

    getchar();

    while(1){
        scanf("%c",&ch);

        if(ch=='\n'){
            break;
        }

        else{
            str_insert[h]=ch;
            h++;
        }

    }

	ptr = fopen(file_name, "r");

	if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
	}

    else{

	    int line_number=1;
        int char_number=0;
        int i=0;
        int j=0;
        while (!feof(ptr)) {

            if(line_number<entered_line){
                while(1){
                    str_copy1[i] = fgetc(ptr);
                    if(str_copy1[i]=='\n'){
                        line_number++;
                        i++;
                        break;
                    }
                    i++;
                }
            }

            else if(line_number==entered_line){
                while(1){
                    if(char_number<entered_character){
                        str_copy1[i]=fgetc(ptr);
                        char_number++;
                    }
                    else{
                        str_copy2[j]=fgetc(ptr);
                        j++;
                        break;
                    }
                    i++;
                }
            }

           // printf("#");

          //  ch = fgetc(ptr);
      //  printf("%c", ch);
        }
        str_copy2[j]='\0';
        str_copy2[j - 1]='\0';

        fclose(ptr);

         //   printf("%s  ",str_copy1);

         //   printf("%s",str_copy2);

        ptr=fopen(file_name,"w");
        fclose(ptr);
        ptr=fopen(file_name,"w+");
        fputs(str_copy1,ptr);
        //fputs(str_insert,ptr);
        for(int m=0;m<strlen(str_insert);m++){
            if(!(str_insert[m] =='\\' && str_insert[m + 1] == 'n')){

                fputc(str_insert[m],ptr);
            }
            else{
                //printf("asdfsfad1");

                if(m>0 && str_insert[m-1]!='\\'){
                    fprintf(ptr,"\n");
                    m++;
                }
                else{
                fputc(str_insert[m],ptr);
                }
            }
        }
        fputs(str_copy2,ptr);
    }

    return 0;
}


