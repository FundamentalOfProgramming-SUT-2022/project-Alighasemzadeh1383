#include <stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>
#include<conio.h>
#include<fileapi.h>
#include <sys/types.h>
#include <dirent.h>

char clipboard[1000];
int counter=0;
int state=0;
int depth=0;
int D=0;


void creatfile_input(char input[]){
    int i=0;
    int slash=0;
    int index=0;
    char *directory_name;
    char directory_nam[100]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    while(input[i]!='\0'){
        if(input[i]=='/'){
            slash++;
        }
        if(input[i]=='"'){
            index=1;
        }
        i++;
    }
    int number_of_folders=slash-2;
    i=24+index;
    int j=0;
    int folder_counter=0;

    while(folder_counter<number_of_folders){
        while(input[i]!='/' && input[i]!='\0'){
            if(input[i]=='"' && input[i-1]!='\\'){
                i++;
                break;
            }
            else{
                directory_name[j]=input[i];
                i++;
                j++;
            }
        }
            directory_name[j]='\0';
            strcat(directory_nam,directory_name);
            create_directory(directory_nam);
            //free(directory_name);
            folder_counter++;
            strcat(directory_nam,"\\");
            j=0;
            i++;

    }
    char file_name[100];
    while(input[i]!='\0'){
        if(input[i]=='\\' && input[i+1]=='"'){
            file_name[j]='"';
            i++;
            i++;
            j++;
        }
        else if(input[i]!='\\' && input[i+1]=='"'){
            break;
        }
        else{
            file_name[j]=input[i];
            i++;
            j++;
        }
    }
    file_name[j]='\0';
    strcat(directory_nam,file_name);
    create_file(directory_nam);
    if(state==1){
        printf("The address of file was wrong\n");
        state=0;
    }
}

void insert_input(char input[]){
    int i=23;
    char file_name[100];
    int j=0;
    int line_number=0;
    int char_number=0;
    while(1){
        if(input[i]==' ' && input[i+1] =='-' && input[i+2]=='-' &&input[i+3]=='s' && input[i+4]=='t' && input[i+5]=='r'){
            break;
        }
        else if(input[i]=='"'){
            i++;
        }
        else{
            if(input[i]!='/'){
                file_name[j]=input[i];
                i++;
                j++;
            }
            else{
                file_name[j]='\\';
                j++;
                i++;
            }
        }
        //printf("goh");
    }
    i+=7;
    if(input[i]=='"'){
        i++;
    }
    char string[1000];
    int k=0;
    int show=0;
    while(input[i]!='\0'){

        if(input[i]==' ' && input[i+1]=='-' && input[i+2]=='-' && input[i+3]=='p' && input[i+4]=='o' && input[i+5]=='s'){
            if(input[i-1]=='"'){
                show=1;
            }
            break;
        }

        else{
            string[k]=input[i];
            k++;
            i++;
        }
       // printf("goh");

    }
    i+=7;
    string[k-show]='\0';
    //printf("%c",input[i]);

    while(input[i]!=':'){
        line_number=10*line_number+(input[i]-'0');
        i++;
    }
    i++;

    while(input[i]!='\0'){
        char_number=10*char_number+(input[i]-'0');
        i++;
    }
        //printf("keke");

    char file_nam[100]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);
    //puts(file_nam);
    //puts(string);
    //printf("L:%d C:%d",line_number,char_number);
    insert(file_nam,line_number,char_number,string);
    //printf("goh to in zendegi");
}

void cat_input(char input[]){
    char file_name[100];
    int i=17,j=0;
    while(input[i]!='\0'){
        if(input[i]=='"'){
            i++;
        }
        else{
            file_name[j]=input[i];
            i++;
            j++;
        }
    }
    char file_nam[100]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);
    //puts(file_nam);
    cat(file_nam);
}

void remove_input(char input[]){
    int i=23;
    char file_name[100];
    int j=0;
    int line_number=0;
    int char_number=0;
    while(1){
        if(input[i]==' ' && input[i+1] =='-' && input[i+2]=='-' &&input[i+3]=='p' && input[i+4]=='o' && input[i+5]=='s'){
            break;
        }
        else{
            if(input[i]!='/'){
                file_name[j]=input[i];
                i++;
                j++;
            }
            else{
                file_name[j]='\\';
                j++;
                i++;
            }
        }
    }
    file_name[j]='\0';
    i+=7;
    while(input[i]!=':'){
        line_number=line_number*10+(input[i]-'0');
        i++;
    }
    //printf("L:%d ",line_number);
    //printf("second loop is okay");
    i++;
    while(input[i]!=' '){
        char_number=char_number*10+(input[i]-'0');
        i++;
    }
    //printf("C:%d ",char_number);
    //printf("third loop is okay");
    i+=7;
    int size=0;
    while(input[i]!=' '){
        size=size*10+(input[i]-'0');
        i++;
    }
    //printf("S:%d",size);

    //printf("forth loop is okay");
    i+=2;
    char ch=input[i];
    char file_nam[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);
    //puts(file_nam);
    removee(ch,file_nam,line_number,char_number,size);
}

void copy_input(char input[]){
    int i=21;
    char file_name[100];
    int j=0;
    int line_number;
    int char_number;
    while(1){
        if(input[i]==' ' && input[i+1] =='-' && input[i+2]=='-' &&input[i+3]=='p' && input[i+4]=='o' && input[i+5]=='s'){
            break;
        }
        else if(input[i]=='"'){
            i++;
        }
        else{
            if(input[i]!='/'){
                file_name[j]=input[i];
                i++;
                j++;
            }
            else{
                file_name[j]='\\';
                j++;
                i++;
            }
        }
    }
    file_name[j]='\0';
    i+=7;
    //printf("goooooooooo");
    while(input[i]!=':'){
        line_number=line_number*10+(input[i]-'0');
        i++;
    }
    //printf("p");
    //printf("L:%d ",line_number);
    //printf("second loop is okay");
    i++;
    while(input[i]!=' '){
        char_number=char_number*10+(input[i]-'0');
        i++;
    }
    //printf("C:%d ",char_number);
    //printf("third loop is okay");
    i+=7;
    int size=0;
    while(input[i]!=' '){
        size=size*10+(input[i]-'0');
        i++;
    }
    //printf("S:%d",size);

    //printf("forth loop is okay");
    i+=2;
    char ch=input[i];
    char file_nam[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);
    //puts(file_nam);
    copy(ch,file_nam,line_number,char_number,size);
}

void cut_input(char input[]){
    int i=20;
    char file_name[100];
    int j=0;
    int line_number;
    int char_number;
    while(1){
        if(input[i]==' ' && input[i+1] =='-' && input[i+2]=='-' &&input[i+3]=='p' && input[i+4]=='o' && input[i+5]=='s'){
            break;
        }
        else if(input[i]=='"'){
            i++;
        }
        else{
            if(input[i]!='/'){
                file_name[j]=input[i];
                i++;
                j++;
            }
            else{
                file_name[j]='\\';
                j++;
                i++;
            }
        }
    }
    file_name[j]='\0';
    i+=7;
    //printf("goooooooooo");
    while(input[i]!=':'){
        line_number=line_number*10+(input[i]-'0');
        i++;
    }
    //printf("p");
    //printf("L:%d ",line_number);
    //printf("second loop is okay");
    i++;
    while(input[i]!=' '){
        char_number=char_number*10+(input[i]-'0');
        i++;
    }
    //printf("C:%d ",char_number);
    //printf("third loop is okay");
    i+=7;
    int size=0;
    while(input[i]!=' '){
        size=size*10+(input[i]-'0');
        i++;
    }
    //printf("S:%d",size);

    //printf("forth loop is okay");
    i+=2;

    char ch=input[i];
    char file_nam[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);
    //puts(file_nam);
    cut(ch,file_nam,line_number,char_number,size);
}

void paste_input(char input[]){
    int i=22;
    char file_name[100];
    int j=0;
    int line_number;
    int char_number;
    while(1){
        if(input[i]==' ' && input[i+1] =='-' && input[i+2]=='-' &&input[i+3]=='p' && input[i+4]=='o' && input[i+5]=='s'){
            break;
        }
        else if(input[i]=='"'){
            i++;
        }
        else{
            if(input[i]!='/'){
                file_name[j]=input[i];
                i++;
                j++;
            }
            else{
                file_name[j]='\\';
                j++;
                i++;
            }
        }
    }
     file_name[j]='\0';
    i+=7;
    //printf("goooooooooo");
    while(input[i]!=':'){
        line_number=line_number*10+(input[i]-'0');
        i++;
    }
    //printf("p");
    //printf("L:%d ",line_number);
    //printf("second loop is okay");
    i++;
    while(input[i]!='\0'){
        char_number=char_number*10+(input[i]-'0');
        i++;
    }
    //printf("C:%d ",char_number);
    //printf("third loop is okay");

    //printf("forth loop is okay");
    char file_nam[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);
   // puts(file_nam);
    paste(file_nam,line_number,char_number);
}

void find_input(char input[]){
    int i=12,j=0;
    char str[1000];
    char file_name[100];
    int flag=0;

    while(1){
        if(input[i]=='"'&& input[i+1]==' ' && input[i+2]=='-' && input[i+3]=='-' && input[i+4]=='f' && input[i+5]=='i' && input[i+6]=='l' && input[i+7]=='e'){
            str[j]='\0';
            //printf("p");
            //puts(str);
            break;
        }
        else{

            if(input[i]=='\\' && input[i+1]=='"'){
                i++;
                str[j]=input[i];
                j++;
                i++;
            }
            else if(str[i]=='\\' && str[i+1]=='*'){
                i++;
                str[j]=str[i];
                j++;
                i++;
            }
            //}
        //}
         else{
            str[j]=input[i];
            j++;
            i++;
            //printf("%c",input[i]);
         }
    }
}        //printf("pp");

  //  puts(input);
    i+=9;
    int k=0;
  //  printf("%d",i);
    while(input[i]!=' ' && input[i]!='\0'){
        file_name[k]=input[i];
        i++;
        k++;
        //printf("%c",file_name[k]);
    }
    //find --str "goh" --file ali.txtputs(file_name);
    int t=0;
    if(input[i]=='\0'){
        t=1;
    }
    char file_nam[100]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);
    //char state[100];
 /*   i++;
    if(input[i]=='\0'){
        if(flag==-1 || flag==0){
            if(str[strlen(str)]=='*'){
                find(file_nam,str);
            }
            //////////////////////////
            //else{

            //}
        }

        else{
            //
            printf("not supported");
        }
    }
*/
  //  else{
        if(t){
            find(file_nam,str);
            return;
        }
        i++;
        i++;
        int num=0;
        if(input[i]=='c' && input[i+1]=='o' && input[i+2]=='u' && input[i+3]=='n' && input[i+4]=='t' && input[i+5]=='\0'){
            find_count(file_nam,str);
            return;
        }
        if(input[i]=='b' && input[i+1]=='y' && input[i+2]=='w' && input[i+3]=='o' && input[i+4]=='r' && input[i+5]=='d' && input[i+6]=='\0'){
            find_byword(file_nam,str);
            return;
        }
        if(input[i]=='a' && input[i+1]=='l' && input[i+2]=='l' && input[i+3]=='\0'){
            find_all(file_nam,str);
            return;
        }
        //////////////////////////////////////////////////////////////////////////////////////////////

        if(input[i]=='a' && input[i+1]=='t' && input[i+2]==' ' && (input[i+3]>='0' && input[i+3]<='9')){
           int pk=0;
           int num=0;
           //printf("p");
            while(input[i+3]<='9' && input[i+3]>='0'){
                num=num*10+(input[i+3]-'0');
                i++;
            }
            //pk=-1;
            //printf("p");
            //puts(file_nam);
            if(input[i+3]==' '&& input[i+4]=='-' && input[i+5]=='b' && input[i+6]=='y' && input[i+7]=='w' && input[i+8]=='o' && input[i+9]=='r' && input[i+10]=='d'){
                find_byword_at(file_nam,str,num);
            }
            else if(input[i+4]=='\0'){
                find_at(file_nam,str,num);
               // printf("goh");
            }

            return;

        }
        num=0;

        if(input[i]=='b' && input[i+1]=='y' && input[i+2]=='w' && input[i+3]=='o' && input[i+4]=='r' && input[i+5]=='d' && input[i+6]==' ' && input[i+7]=='-' && input[i+8]=='a' && input[i+9]=='l' && input[i+10]=='l' &&str[i+11]=='\0'){
            find_byword_all(file_nam,str);
            return;
        }
        if(input[i]=='a' && input[i+1]=='l' && input[i+2]=='l' && input[i+3]==' ' && input[i+4]=='-' && input[i+5]=='b' && input[i+6]=='y' && input[i+7]=='w' && input[i+8]=='o' && input[i+9]=='r' && input[i+10]=='d' && str[i+11]=='\0'){
            find_byword_all(file_nam,str);
            return;
        }
        if(input[i]=='b' && input[i+1]=='y' && input[i+2]=='w' && input[i+3]=='o' && input[i+4]=='r' && input[i+5]=='d' && input[i+6]==' ' && input[i+7]=='-' && input[i+8]=='a' && input[i+9]=='t'){

            while(input[i+11]<='9' && input[i+11]>='0'){
                num=num*10+(input[i+11]-'0');
                i++;
               // printf("tape");

            }
            //printf("%d ",num);
            find_byword_at(file_nam,str,num);
            return;
        }

        else{
            printf("Invalid command\n");
        }
}

void replace_input(char input[]){
    int i=15;
    char str1[1000];
    char str2[1000];
    char file_name[100];
    int j=0;
    while(1){
        if(input[i]=='"' && input[i-1]!='\\'){
            i++;
        }
        else if(input[i]=='\\' && input[i+1]=='"'){
            str1[j]='"';
            j++;
            i++;
            i++;
        }
        else if(input[i]=='\\' && input[i+1]=='*'){
            str1[j]='*';
            j++;
            i++;
            i++;
        }
        if(input[i]==' ' && input[i+1]=='-' && input[i+2]=='-' && input[i+3]=='s' && input[i+4]=='t' && input[i+5]=='r' && input[i+6]=='2'){
                break;

        }
        str1[j]=input[i];
        i++;
        j++;
   // printf("goh");
    }
    //printf("goh");
    i+=8;
    int k=0;
    while(1){
        if(input[i]=='"' && input[i-1]!='\\'){
            i++;
        }
        if(input[i]==' ' && input[i+1]=='-' && input[i+2]=='-' && input[i+3]=='f' && input[i+4]=='i' && input[i+5]=='l' && input[i+6]=='e'){
                break;

        }
        str2[k]=input[i];
        i++;
        k++;
    //printf("goh");
    }
    //str2[k]='\0';
    //printf("goh");
    i+=8;
    int h=0;
    while(input[i]!=' ' && input[i]!='\0'){
        file_name[h]=input[i];
        i++;
        h++;
     //   printf("goh");
    }
    int p=0;
    if(input[i]=='\0'){
        p=1;
    }
    //printf("goh");
    i++;
    i++;
    //puts(file_name);
   // puts(input);
   //puts(str2);
    if(input[i]=='a' && input[i+1]=='l' && input[i+2]=='l' && input[i+3]=='\0'){
      //puts(file_name);
        replace_all(file_name,str1,str2);
    }
    if(input[i]=='a' && input[i+1]=='t' && input[i+2]==' ' && (input[i+3]>='0' || input[i+3]<='9')){
        //printf("keke");
        int num=0;
        while((input[i+3]>='0' || input[i+3]<='9') && input[i+3]!='\0'){
            num=num*10+(input[i+3]-'0');
            i++;
          //  printf("gooh");
        }
       // printf("%d",num);
       // if(input[i]=='\0'){
            replace_at(file_name,str1,str2,num);
        //}
        //else{
          //  printf("Invalid command");
        //}
    }
    if(p){
        //puts("keke");
        replace(file_name,str1,str2);
    }


}

void grep_input(char input[]){
    int C=0;

    if(input[5]=='-' && (input[6]=='c' || input[6]=='l')){
        int i=14;
        char file_name[100];
        char string[1000];
        int j=0;
        while(1){
            if(input[i]==' ' && input[i+1]=='-' && input[i+2]=='-' && input[i+3]=='f' && input[i+4]=='i' && input[i+5]=='l' && input[i+6]=='e' && input[i+7]=='s'){
                break;
            }
            else{
                if(input[i]=='"' && input[i-1]!='\\'){
                    i++;
                }
                else{
                    string[j]=input[i];
                    i++;
                    j++;
                }
            }
        }
        //printf("goh");
        i+=9;
        int m=0;
        while(input[i]!='\0'){
            while(input[i]!=' ' && input[i]!='\0'){
                file_name[m]=input[i];
                m++;
                i++;
            }


            char file_nam[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
            file_name[m]='\0';
            strcat(file_nam,file_name);
            //puts(file_nam);
            if(input[6]=='c'){
                C+=grep_C(file_nam,string,file_name);
                i++;
                //pri
                //free(file_name);
             //   printf("%d ",C);
            }
            else{
                grep_I(file_nam,string,file_name);
                i++;
                //free(file_name);
            }
            m=0;
        }
    }

    else{
        int i=11;
        char file_name[100];
        char string[1000];
        int j=0;
        while(1){
            if(input[i]==' ' && input[i+1]=='-' && input[i+2]=='-' && input[i+3]=='f' && input[i+4]=='i' && input[i+5]=='l' && input[i+6]=='e'){
                break;
            }
            else{
                if(input[i]=='"' && input[i-1]!='\\'){
                    i++;
                }
                else{
                    string[j]=input[i];
                    i++;
                    j++;
                }
            }
        }

        i+=9;
        int m=0;
        while(input[i]!='\0'){
           // if(input[i]!=' '){
                while(input[i]!=' ' && input[i]!='\0'){
                    file_name[m]=input[i];
                    m++;
                    i++;
             //   printf("%c ",file_name[m]);
                //    printf("%c ",input[i]);
               // printf("%d ",m);
                }
          //  }
            //else{
                char file_nam[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
               // printf("%d\n",m);
                file_name[m]='\0';
                //printf("%d\n",m);
                //puts(file_name);
                strcat(file_nam,file_name);
                grep(file_nam,string,file_name);
                //puts(file_name);
                //free(file_name);
                //puts(file_nam);
                //printf("%c",input[i+1]);
                //if(input[i]=='\0'){
                //    return;
              //  }
                m=0;
                i++;
                //puts(file_nam);
            //}
        }

    }

    if(input[6]=='c'){
        printf("%d\n",C);
    }
}

void undo_input(char input[]){
    char file_name[100];
    int i=12,j=0;
    while(input[i]!='\0'){
        if(input[i]=='"'){
            i++;
        }
        else{
            file_name[j]=input[i];
            i++;
            j++;
        }
    }
    file_name[j]='\0';
     char file_nam[100]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
     strcat(file_nam,file_name);
     //puts(file_nam);
     undo(file_name);
}

void auto_indent_input(char input[]){
    char file_name[100];
    int i=12;
    int j=0;
    while(input[i]!='\0'){
        if(input[i]=='"'){
            i++;
        }
        else{
            file_name[j]=input[i];
            i++;
            j++;
        }
    }
    char file_nam[100]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam,file_name);

    auto_indent(file_nam);
}

void compare_input(char input[]){
    char file_name1[100];
    char file_name2[100];
    int i=8,j=0,k=0;
    int space=0;

    while(input[i]!='\0'){
        while(input[i]!=' '){
            file_name1[j]=input[i];
            i++;
            j++;
        }
        i++;
        while(input[i]!='\0'){
            file_name2[k]=input[i];
            i++;
            k++;
        }

    }
    char file_nam1[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam1,file_name1);
    char file_nam2[]="C:\\Users\\SHAYAN SYSTEM\\Desktop\\root\\";
    strcat(file_nam2,file_name2);
    //puts(file_nam1);
    //puts(file_nam2);
    compare(file_nam1,file_nam2);
}

void tree_input(char input[]){
   // int depth=0;
    int i=5;
    int flag=1;
    while(input[i]!='\0'){

        if(input[i]=='-'){
            flag=-1;
            i++;
            //printf("goh");
        }
        if(input[i]>='0' && input[i]<='9'){

            depth=+depth*10+flag*(input[i]-'0');
           // printf("%c",input[i]);
        }
        i++;

    }
   // printf("%d",depth);

    if(depth<-1){
     printf("Invalid depth\n");
     depth=0;
     counter=0;
     return;
    }

    if(depth==-1){
        tree_minus(".",0);
    }
    else{
        tree(".",0);
      //  printf("%d",depth);

    }
    depth=0;
    counter=0;
}

void create_directory(char directory_name[]){
    //struct dirent *directory;
    //DIR *dir = opendir(directory_name);

    //if(!dir){
      //  printf("The address of file is wrong\n");
        //state=1;
   // }
    mkdir(directory_name);

}

void create_file(char string[]){
    FILE *fptr = NULL;

    fptr=fopen(string,"r");

    if(fptr!=NULL){
        printf("The file has existed\n");
    }
    else{
        fptr=fopen(string,"w");
        fclose(fptr);
    }
}

void cat(char file_name[]){

    FILE *fptr;

    char c;
    fptr = fopen(file_name, "r");
    if (fptr == NULL){
        printf("This file hasn't existed\n");
        return;
    }

    c = fgetc(fptr);
    while (c != EOF)
    {
    printf ("%c", c);
    c = fgetc(fptr);
    }

    fclose(fptr);

    puts("");
}

void insert(char file_name[],int entered_line,int entered_character,char str_insert[]){

	FILE* ptr;

    char str_copy1[1000];
    char str_copy2[1000];

	ptr = fopen(file_name,"r");

	if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
		//fclose(ptr);
		return;
	}

        char strrr[1000];
        fread(strrr,1,1000,ptr);
        fclose(ptr);
        //printf("%s",strrr);
        char temp[100]=".";

        strcat(temp,file_name);
        FILE* fptr;
        fptr=fopen(temp,"w");

        //printf("%s\n",temp);
        //fwrite(strrr,1,strlen(strrr),fptr);
        fputs(strrr,fptr);
        fclose(fptr);

        SetFileAttributes(temp,FILE_ATTRIBUTE_HIDDEN);
        ptr = fopen(file_name, "r");

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
                            printf("The line hasn't any other characters\n");
                            return;
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
        str_copy1[j]='\0';
        str_copy1[j - 1]='\0';
        str_copy2[j]='\0';
        str_copy2[j-1]='\0';
        fclose(ptr);

         //   printf("%s  ",str_copy1);

         //   printf("%s",str_copy2);

        ptr=fopen(file_name,"w");
        //fclose(ptr);
        //ptr=fopen(file_name,"w+");
        int n=0;
       // while(str_copy1[n]!=NULL){
         //   fputc(str_copy1[n],ptr);
           // n++;
        //}
        fputs(str_copy1,ptr);
        //fputs(str_insert,ptr);
        for(int m=0;m<str_insert[m]!='\0';m++){
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
    printf("goh");
    fclose(ptr);
}

void copy(char c,char file_name[],int entered_line,int entered_start,int entered_size){

    FILE* ptr;
	char ch;
    char str_copy1[1000];
    char str_copy2[1000];

    ptr = fopen(file_name,"r");

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

            for(n=i-entered_size;n<i;n++){
                clipboard[n-(i-entered_size)]=str_copy1[n];
            }
            clipboard[n-(i-entered_size)]='\0';
        }
        else{
                int n;

                for(n=0;n<entered_size;n++){

                clipboard[n]=str_copy2[n];
            }
            clipboard[n]='\0';
        }

    }
    //printf("%s",clipboard);
    fclose(ptr);
}

void removee(char c,char file_name[],int entered_line,int entered_start,int entered_size){

    FILE* ptr;
	char ch;
    char str_copy1[1000];
    char str_copy2[1000];

    ptr = fopen(file_name,"r");

	if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
        return;
	}
        //printf("goh");
        char strrr[1000];
        fread(strrr,1,1000,ptr);
        fclose(ptr);
        //printf("%s",strrr);
        char temp[100]=".";
        strcat(temp,file_name);
        FILE* fptr;
        fptr=fopen(temp,"w");
        //printf("%s\n",temp);
        fputs(strrr,fptr);
        fclose(fptr);
//removestr --file /root/ali.txt --pos 2:1 -size 3 -b
        SetFileAttributes(temp,FILE_ATTRIBUTE_HIDDEN);
        ptr=fopen(file_name,"r");

	    int line_number=1;
        int start_number=0;
        int size_number=0;
        int i=0;
        int j=0;
        //char c;
        //printf("goh");
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

    fclose(ptr);
}

void cut(char c,char file_name[],int entered_line,int entered_start,int entered_size){

copy(c,file_name,entered_line,entered_start,entered_size);

removee(c,file_name,entered_line,entered_start,entered_size);

}

void paste(char file_name[],int entered_line,int entered_start){

    insert(file_name,entered_line,entered_start,clipboard);
}

void find(char file_name[],char wanted_word[]){
    FILE* ptr;
    char str1[1000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet\n");
	}

	else{
        fread(str1,1000,1,ptr);
        fclose(ptr);

        int file_name=strlen(str1);
        int l_wanted_word=strlen(wanted_word);
        int j=0,count=0;
        for(int i=0;i<file_name;){
            j=0;
            count=0;

            while(str1[i]==wanted_word[j] && str1[i]!=EOF){
                i++;
                j++;
                count++;
            }
            if(count==l_wanted_word){
                printf("%d\n",i-l_wanted_word);
                return;
            }
            else{
                i++;
            }
        }
        printf("-1\n");
        return;
    }
}

void find_count(char file_name[],char wanted_word[]){
    FILE* ptr;
    char str1[1000];
    int counter=0;
    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet\n");
	}

	else{
        fread(str1,1,1000,ptr);
        fclose(ptr);

        int file_name=strlen(str1);
        int l_wanted_word=strlen(wanted_word);
        int j=0,count=0;
        for(int i=0;i<file_name;){
            j=0;
            count=0;

            while(str1[i]==wanted_word[j] && str1[i]!=EOF){
                i++;
                j++;
                count++;
            }
            if(count==l_wanted_word ){
                //printf("%d",i-l_wanted_word);
                counter++;
            }
            else{
                i++;
            }
        }
        if(counter>=1){
            printf("%d\n",counter);
            return 0;
        }
        else{
            printf("0\n");
            return -1;
        }
    }
}

void find_at(char file_name[],char wanted_word[],int number){
    FILE* ptr;
    char str1[1000];
    int counter=0;
    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet\n");
	}

	else{
        fread(str1,1,1000,ptr);
        fclose(ptr);

        int file_name=strlen(str1);
        int l_wanted_word=strlen(wanted_word);
        int j=0,count=0,i;

        for(i=0;i<file_name;){
            j=0;
            count=0;

            while(str1[i]==wanted_word[j] && str1[i]!=EOF){
                i++;
                j++;
                count++;
            }
            if(count==l_wanted_word ){
                //printf("%d",i-l_wanted_word);

                if(counter==number-1){

                        printf("%d\n",i-l_wanted_word);
                        return;

                }

                counter++;
            }
            else{
                i++;
            }
        }

        if(counter==number){
            printf("%d\n",i-l_wanted_word);
            return;
        }
        else{
            printf("-1\n");
            return;
        }
    }
}

void find_all(char file_name[],char wanted_word[]){

    FILE* ptr;
    char str1[1000];
    int counter=0;
    int counters[1000];
    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet\n");
	}

	else{
        fread(str1,1,1000,ptr);
        fclose(ptr);

        int file_name=strlen(str1);
        int l_wanted_word=strlen(wanted_word);
        int j=0,count=0;
        for(int i=0;i<file_name;){
            j=0;
            count=0;

            while(str1[i]==wanted_word[j] && str1[i]!='\0'){
                i++;
                j++;
                count++;
            }
            if(count==l_wanted_word ){
                //printf("%d",i-l_wanted_word);
                counters[counter]=i-l_wanted_word;
                counter++;
            }
            else{
                i++;
            }
        }
        if(counter>=1){
            int m;
            for(m=0;m<counters[m+1]!='\0';m++){
                printf("%d, ",counters[m]);
            }
            printf("%d",counters[m]);
            puts("");
        }
        else{
            printf("-1\n");
            return -1;
        }
    }

}

void find_byword(char file_name[],char wanted_word[]){
   //printf("goh");
    FILE* ptr;
    char str1[1000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet\n");
		return;
	}

    fread(str1,1,1000,ptr);
    fclose(ptr);

	int l_file=strlen(str1);
	int l_wanted_word=strlen(wanted_word);
	int j=0,count=0;
	//The number of space shows the number of words - 1
	int space_counter1=0;
	int space_counter2=0;
	int word_number;
	//printf("goh");
    for(int i=0;i<l_file;){
        j=0;
        count=0;
        space_counter2=0;

        while(str1[i]==wanted_word[j] && str1[i]!='\0'){
            if(str1[i]==' '){
                space_counter2++;
            }
            i++;
            j++;
            count++;
        }
        if(count==l_wanted_word){
            word_number=space_counter1+1;
            printf("%d\n",word_number);
            return;
            //space_counter1+=space_counter2;
            //count_word++;
           // return;
        }
        else{

            if(str1[i]==' ' || str1[i]=='\n'){
                space_counter1++;
            }
            space_counter1+=space_counter2;
            i++;
        }
    }
    //printf("%d",strlen(word_number));
        printf("-1\n");
        return;

}

void find_byword_at(char file_name[],char wanted_word[],int at){
    int goh=0;
    FILE* ptr;
    char str1[1000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
		return;
	}

    fread(str1,1,1000,ptr);
    fclose(ptr);
	int l_file=strlen(str1);
	int l_wanted_word=strlen(wanted_word);
	int j=0,count=0;
	//The number of space shows the number of words - 1
	int space_counter1=0;
	int space_counter2=0;
	int word_number;
    for(int i=0;i<l_file;){
        j=0;
        count=0;
        space_counter2=0;
        while(str1[i]==wanted_word[j] && str1[i]!=EOF){
            if(str1[i]==' '){
                space_counter2++;
            }
            i++;
            j++;
            count++;
        }
        if(count==l_wanted_word){
            goh++;
            word_number=space_counter1+1;
            if(goh==at){
                printf("%d\n",word_number);
                return;
            }
            space_counter1++;
            i+=l_wanted_word;
            //space_counter1+=space_counter2;
            //count_word++;
        }
        else{

            if(str1[i]==' ' || str1[i]=='\n'){
                space_counter1++;
            }
            space_counter1+=space_counter2;
            i++;
        }
    }
    //printf("%d",strlen(word_number));
        printf("-1\n");
        return;

}

void find_byword_all(char file_name[],char wanted_word[]){
    int goh=0;
    char keke[1000];
    FILE* ptr;
    char str1[1000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet\n");
		return;
	}

    fread(str1,1000,1,ptr);
    fclose(ptr);
	int l_file=strlen(str1);
	int l_wanted_word=strlen(wanted_word);
	int j=0,count=0;
	//The number of space shows the number of words - 1
	int space_counter1=0;
	int space_counter2=0;
	int word_number;
    for(int i=0;i<l_file;){
        j=0;
        count=0;
        space_counter2=0;
        while(str1[i]==wanted_word[j] && str1[i]!=EOF){
            if(str1[i]==' '){
                space_counter2++;
            }
            i++;
            j++;
            count++;
        }
        if(count==l_wanted_word){

            word_number=space_counter1+1;
                //printf("%d",word_number);
            keke[goh]=word_number;

            space_counter1++;
            i+=l_wanted_word;
            //space_counter1+=space_counter2;
            //count_word++;
            goh++;
        }
        else{

            if(str1[i]==' ' || str1[i]=='\n'){
                space_counter1++;
            }
            space_counter1+=space_counter2;
            i++;
        }
    }
    if(keke[0]!=NULL){
        int i;
        for(i=0;keke[i+1]!=NULL;i++){
            printf("%d, ",keke[i]);
        }
        printf("%d\n",keke[i]);
        return;
    }
    //printf("%d",strlen(word_number));
        printf("-1\n");
        return;

}

void replace_all(char file_name[],char *oldsub,char *newsub){

    char before[1000];
    FILE *ptr;
    ptr=fopen(file_name,"r");
    fread(before,1000,1,ptr);
    fclose(ptr);

    int old_length=strlen(oldsub);

    int new_length=strlen(newsub);

    int before_length=strlen(before);

    char *after;

    if(old_length==new_length){
        after=malloc((before_length+1)*sizeof(char));

    }

    else{
        int occurrences=0;
        int i=0;
        while(i<before_length){
            if(strstr(&before[i],oldsub)==&before[i]){
                occurrences++;
                i+=old_length;
            }
            else{
                i++;
            }
        }
        if(occurrences==0){
            printf("Failure\n");
            return;
        }
        int sub_differences=new_length-old_length;
        int after_length=before_length;
        after_length+=occurrences*sub_differences;

        after=malloc((after_length+1)*sizeof(char));

    }
    int i=0;
    int j=0;

    while(i<strlen(before)){
        if(strstr(&before[i],oldsub)==&before[i]){
            strcpy(&after[j],newsub);
            i+=old_length;
            j+=new_length;
        }
        else{
            after[j]=before[i];
            i++;
            j++;
        }

    }
    after[j]='\0';

    ptr=fopen(file_name,"w");
    fputs(after,ptr);
    fclose(ptr);
    printf("Success\n");
}

void replace(char file_name[],char *oldsub,char *newsub){

    char before[1000];
    FILE *ptr;
    ptr=fopen(file_name,"r");
    fread(before,1,1000,ptr);
    fclose(ptr);

    int old_length=strlen(oldsub);

    int new_length=strlen(newsub);

    int before_length=strlen(before);

    char *after;

    if(old_length==new_length){
        after=malloc((before_length+1)*sizeof(char));

    }

    else{
        int occurrences=0;
        int i=0;
        while(i<before_length){
            if(strstr(&before[i],oldsub)==&before[i]){
                occurrences++;
                i+=old_length;
            }
            else{
                i++;
            }
        }
        if(occurrences==0){
            printf("Failure\n");
            return;
        }

        int sub_differences=new_length-old_length;
        int after_length=before_length;
        after_length+=occurrences*sub_differences;

        after=malloc((after_length+1)*sizeof(char));

    }
    int i=0;
    int j=0;

    while(i<strlen(before)){
        if(strstr(&before[i],oldsub)==&before[i]){
            strcpy(&after[j],newsub);
            i+=old_length;
            j+=new_length;
            strcpy(&after[j],&before[i]);
            break;
        }
        else{
            after[j]=before[i];
            i++;
            j++;
        }

    }
   // after[j]='\0';

    ptr=fopen(file_name,"w");
    fputs(after,ptr);
    fclose(ptr);
    printf("Success\n");
}

void replace_at(char file_name[],char *oldsub,char *newsub,int at){
    int goh=0;
    char before[1000];
    FILE *ptr;
    ptr=fopen(file_name,"r");
    fread(before,1000,1,ptr);
    fclose(ptr);

    int old_length=strlen(oldsub);

    int new_length=strlen(newsub);

    int before_length=strlen(before);

    char *after;

    if(old_length==new_length){
        after=malloc((before_length+1)*sizeof(char));

    }

    else{
        int occurrences=0;
        int i=0;
        while(i<before_length){
            if(strstr(&before[i],oldsub)==&before[i]){
                occurrences++;
                i+=old_length;
            }
            else{
                i++;
            }
        }
        if(occurrences==0){
            printf("Failure\n");
            return;
        }

        int sub_differences=new_length-old_length;
        int after_length=before_length;
        after_length+=occurrences*sub_differences;

        after=malloc((after_length+1)*sizeof(char));

    }
    int i=0;
    int j=0;

    while(i<strlen(before)){
        if(strstr(&before[i],oldsub)==&before[i]){
            goh++;
            if(goh==at){
                strcpy(&after[j],newsub);
            }
            else{
                strcpy(&after[j],oldsub);
            }

            i+=old_length;
            if(goh==at){
                j+=new_length;
            }
            else{
                j+=old_length;
            }

            if(goh==at){
                strcpy(&after[j],&before[i]);
                break;
            }
        }
        else{
            after[j]=before[i];
            i++;
            j++;
        }

    }
   // after[j]='\0';

    ptr=fopen(file_name,"w");
    fputs(after,ptr);
    fclose(ptr);
    printf("Success\n");
}

void grep(char file_name[],char patern[],char just_file_name[]){

    FILE*ptr=fopen(file_name,"r");

    if(ptr==NULL){
        printf("The program hasn't existed yet\n");
        printf("-1\n");
        return;
    }
    char line[1000];

    while(fscanf(ptr,"%999[^\n]",line)!=EOF){
        if(strstr(line,patern)!=NULL){
        printf("%s: %s\n",just_file_name,line);
    }
    fscanf(ptr,"\n",line);

    }

        fclose(ptr);
}

int grep_C(char file_name[],char patern[]){

    FILE*ptr=fopen(file_name,"r");

    int counter=0;

    if(ptr==NULL){
        printf("The program hasn't existed yet\n");
        printf("-1\n");
        return;
    }
    char line[1000];

    while(fscanf(ptr,"%999[^\n]",line)!=EOF){
        if(strstr(line,patern)!=NULL){
        //printf("%s: %s\n",file_name,line);
        counter++;
    }
    fscanf(ptr,"\n",line);

    }
        fclose(ptr);
        if(counter==0){
            printf("This string hasn't existed in the file\n");
        }
        else{
            //printf("%d\n",counter);
            return counter;
        }
}

void grep_I(char file_name[],char patern[],char just_file_name[]){

    FILE*ptr=fopen(file_name,"r");

    int counter=0;

    if(ptr==NULL){
    printf("The program hasn't existed yet\n");
    return;
    }
    char line[1000];

    while(fscanf(ptr,"%999[^\n]",line)!=EOF){
        if(strstr(line,patern)!=NULL){
        //printf("%s: %s\n",file_name,line);
        counter=1;
    }
    fscanf(ptr,"\n",line);

    }
        fclose(ptr);
        if(counter==0){
            printf("This string hasn't existed in the file\n");
        }
        else{
            printf("%s\n",just_file_name);
        }
}

void undo(char file_name[]){
    char strrr[1000];
    char t[1000];
    char temp[]=".";
    strcat(temp,file_name);
    puts(temp);
    SetFileAttributes(temp,FILE_ATTRIBUTE_NORMAL);
    FILE*fptr;
    fptr=fopen(temp,"r");
    if(fptr==NULL){
        printf("No change exists\n");
        return;
    }

    fread(strrr,1,1000,fptr);
    fclose(fptr);
    FILE* ptr;
    ptr=fopen(file_name,"w");
    fputs(strrr,ptr);
    fclose(ptr);
    SetFileAttributes(temp,FILE_ATTRIBUTE_HIDDEN);
}

void auto_indent(char file_name[]){
    char str[1000];
    char s[1000];

   FILE*ptr;
   ptr=fopen(file_name,"r");

   fread(str,1,1000,ptr);
   fclose(ptr);

   int l=strlen(str);
   int j=0;
   int tab=0;

   int keke=0;
   for(int m=0;m<l;m++){
    if(str[m]=='}'){
        keke++;
    }
   }
   int goh=0;

   int flag=1;
   if(str[0]=='{'){
    flag=0;
   }

   for(int i=0;i<l;){

        s[j]=str[i];

    if((str[i]=='{' || str[i]=='}')&&str[i]!=NULL){
        if(str[i]=='{'){
            tab++;
            s[j]='\n';
            //if(flag==0){
            //s[0]='{';
            //s[1]='\n';
            //j++;
            //}
            //printf("%c",s[0]);
            int counter=i+1;
            int space=0;
            while(str[i-1]==' '){
                i--;
                space++;
            }

            i=counter;
            j-=space;
            if(flag){
                s[j]=' ';
                j++;
            }

            s[j]='{';
            j++;
            s[j]='\n';
            j++;

            for(int k=0;k<4*tab;k++){
                s[j]=' ';
                j++;
            }

            while(str[i]==' '){
                i++;
            }

        }

        else{
            goh++;
            tab--;
            //s[j]==NULL;
            int counter=i+1;
            int space=0;
            while(str[i-1]==' '){
                i--;
                space++;
            }

            i=counter;
            j-=space;
            //printf("%d ",j);
            //printf("s:%c t",s[j-1]);
            if(s[j-1]!='\n'){
                s[j]='\n';
                j++;
            }

            for(int k=0;k<4*tab;k++){
                s[j]=' ';
                j++;
            }

            s[j]='}';
            j++;

            if(goh<keke){

            s[j]='\n';
            j++;
            for(int k=0;k<4*tab;k++){
                s[j]=' ';
                j++;
            }

            }
            else{
                s[j]='\n';
                break;
            }


            while(str[i]==' '){
                i++;
            }

        }

    }

    else{
        j++;
        i++;
    }
        if(goh==keke){
            break;
        }

   }

   char string[1000];
   int a=0;
   int b=0;
   while(s[a]!='\0'){
      if(s[a]=='\n'){
        int c=a+1;
        while(s[c]==' '){
            c++;
        }
        if(s[c]=='\n'){
            a=c;
        }
        string[b]=s[a];
        b++;
        a++;

      }
      else{
        string[b]=s[a];
        a++;
        b++;
      }
   }

   ptr=fopen(file_name,"w");
   fputs(string,ptr);
   fclose(ptr);
}

void compare(char file_name1[],char file_name2[]){

FILE*fptr1;
FILE*fptr2;
char str1[1000];
char str2[1000];
int counter=0;
int flag1=1;
int flag2=1;
int counter1=0;
int counter2=0;

char str3[1000];
char str4[1000];

    fptr1=fopen(file_name1,"r");
    fread(str3,1000,1,fptr1);
    fptr2=fopen(file_name2,"r");
    fread(str4,1000,1,fptr2);
    fclose(fptr1);
    fclose(fptr2);

    for(int i=0;str3[i]>0;i++){
        if(str3[i]=='\n'){
            counter1++;
        }
    }
    for(int i=0;str4[i]>0;i++){
        if(str4[i]=='\n'){
            counter2++;
        }
    }

    fptr1=fopen(file_name1,"r");
    fptr2=fopen(file_name2,"r");

    while(1){
        counter++;
        if(flag1==1){
            if(fgets(str1,999,fptr1)=='\0')
            flag1=0;
        }
        if(flag2==1){
            if(fgets(str2,999,fptr2)=='\0')
            flag2=0;
        }

        if(flag1==0 && flag2!=0){
            printf(">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>\n",counter,counter2+1);
            printf("%s\n",str2);
            while(fgets(str2,999,fptr2)!='\0'){
                printf("%s\n",str2);
            }
            return;
        }

        else if(flag1!=0 && flag2==0){
            printf(">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>\n",counter,counter1+1);
            printf("%s\n",str1);
            while(fgets(str1,999,fptr1)!='\0'){
                printf("%s\n",str1);
            }
            return;
        }
        else if(flag1==0 && flag2==0){
            return;
        }
        else if(!strcmp(str1,str2)){
            continue;
        }
        else{
            printf("============ #%d ============\n",counter);
            printf("%s\n",str1);
            printf("%s\n",str2);
        }

    }


}

void tree(char *basePath, const int root){{
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && dp->d_name[0]!='.' && dp->d_name[0]!='0'){
            for (i=0; i<root; i++){
                if (i%2 == 0 || i == 0)
                    printf("|");
                else
                    printf("   ");

            }

            printf("|___%s\n",dp->d_name);
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            if(counter<depth){
                counter++;
                tree(path,root+2);
                counter--;
            }
        }
    }

    closedir(dir);
}
}

void tree_minus(char *basePath, const int root){
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && dp->d_name[0]!='.' && dp->d_name[0]!='0')
        {
            for (i=0; i<root; i++)
            {
                if (i%2 == 0 || i == 0)
                    printf("|");
                else
                    printf("   ");

            }

            printf("|___%s\n",dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree_minus(path, root + 2);
        }
    }

    closedir(dir);
}

int main(){
    char input[1000];
    //create_directory("C:\\Users\\SHAYAN SYSTEM\\Desktop\\root");
    //insertstr --file /root/ali.txt --str Salam -pos 2:5
    while(1){
        gets(input);

        if(!strncmp(input,"createfile",10)){
            //printf("goh");
            creatfile_input(input);
        }
        else if(!strncmp(input,"insertstr",9)){
            insert_input(input);
        }
        else if(!strncmp(input,"cat",3)){
            cat_input(input);
        }
        else if(!strncmp(input,"removestr",9)){
            remove_input(input);
        }
        else if(!strncmp(input,"copystr",7)){
            copy_input(input);
        }
        else if(!strncmp(input,"cutstr",6)){
            cut_input(input);
        }
        else if(!strncmp(input,"pastestr",8)){
            paste_input(input);
        }
        else if(!strncmp(input,"find",4)){
            find_input(input);
        }
        else if(!strncmp(input,"replace",7)){
            replace_input(input);
        }
        else if(!strncmp(input,"grep",4)){
            grep_input(input);
        }
        else if(!strncmp(input,"undo",4)){
            undo_input(input);
        }
        else if(!strncmp(input,"auto-indent",11)){
            auto_indent_input(input);
        }
        else if(!strncmp(input,"compare",7)){
            compare_input(input);
        }
        else if(!strncmp(input,"tree",4)){
            tree_input(input);
        }
        else if(strstr(input,"=D")){
            printf("I can't do it\n");
        }
        else if(!strcmp(input,"exit")){
            return 0;
        }
        else{
            printf("Invalid command\n");
        }
    }

}
