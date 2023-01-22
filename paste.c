#include<stdio.h>
#include<Stdlib.h>

char clipboard[1000000];

void insert(char file_name[],int entered_line,int entered_character,char str_insert[]){
	FILE* ptr;
    char str_copy1[100000];
    char str_copy2[100000];

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
                        if(str_copy1[i]=='\n'){
                            printf("goh moft nakhor dige khat edame nadareh");
                            return 0;
                        }
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
    fclose(ptr);
}

void copy(char c,char file_name[],int entered_line,int entered_start,int entered_size){

    FILE* ptr;
	char ch;
    char str_copy1[1000000];
    char str_copy2[1000000];

    ptr = fopen(file_name, "r");

	if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
	}

    else{

	    int line_number=1;
        int start_number=0;
        int size_number=0;
        int i=0;
        int j=0;
        //char c;
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
                    if(start_number<entered_start){
                        str_copy1[i]=fgetc(ptr);
                        start_number++;
                    }
                    else{
                        //if(size_number<entered_size){
                           // c=fgetc(ptr);
                         //   size_number++;
                        //}
                        //else{
                            str_copy2[j]=fgetc(ptr);
                            j++;
                       // }

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
        str_copy2[j-1]='\0';

        fclose(ptr);
        //ptr=fopen(file_name,"w");
        //fclose(ptr);
        //ptr=fopen(file_name,"w+");
        if(c=='b'){
            int n;

            for(n=i-entered_size;n<i-1;n++){
                clipboard[n-(i-entered_size)]=str_copy1[n];
            }
            clipboard[n]='\0';
        }
        else{
                int n;

                for(n=0;n<entered_size;n++){

                clipboard[n]=str_copy2[n];
            }
            clipboard[n]='\0';
        }

    }
    printf("%s",clipboard);
    fclose(ptr);
}

void removee(char c,char file_name[],int entered_line,int entered_start,int entered_size){

    FILE* ptr;
	char ch;
    char str_copy1[1000000];
    char str_copy2[1000000];

    ptr = fopen(file_name, "r");

	if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
	}

    else{

	    int line_number=1;
        int start_number=0;
        int size_number=0;
        int i=0;
        int j=0;
        //char c;
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
                    if(start_number<entered_start){
                        str_copy1[i]=fgetc(ptr);
                        start_number++;
                    }
                    else{
                        //if(size_number<entered_size){
                           // c=fgetc(ptr);
                         //   size_number++;
                        //}
                        //else{
                            str_copy2[j]=fgetc(ptr);
                            j++;
                       // }

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
        str_copy2[j-1]='\0';

        fclose(ptr);
        ptr=fopen(file_name,"w");
        fclose(ptr);
        ptr=fopen(file_name,"w+");
        if(c=='b'){
            for(int n=0;n<i-entered_size;n++){
            fputc(str_copy1[n],ptr);
            }
            fputs(str_copy2,ptr);
            //printf("+++");
        }
        else{
            fputs(str_copy1,ptr);
                for(int n=entered_size;str_copy2[n]!='\0';n++){
                fputc(str_copy2[n],ptr);
            }
        }
        //fputs(str_copy2,ptr);
    }
    fclose(ptr);
}

void cut(char c,char file_name[],int entered_line,int entered_start,int entered_size){

copy(c,file_name,entered_line,entered_start,entered_size);

removee(c,file_name,entered_line,entered_start,entered_size);

}

void paste(char file_name[],int entered_line,int entered_start){

    insert(file_name,entered_line,entered_start,clipboard);
}

int main(){

    char file_name[100];
    int entered_line,entered_start,entered_size;

    scanf("%s",file_name);
    scanf("%d %d %d",&entered_line,&entered_start,&entered_size);

    cut('f',file_name,entered_line,entered_start,entered_size);
    paste(file_name,2,0);
    //insert(file_name,entered_line,entered_start,clipboard);
}
