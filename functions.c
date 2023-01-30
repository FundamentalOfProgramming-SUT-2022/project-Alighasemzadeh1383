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
int wanted_depth=1;

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
        fread(strrr,1000,1,ptr);
        fclose(ptr);
        //printf("%s",strrr);
        char temp[100]="p";

        strcat(temp,file_name);
        FILE* fptr;
        fptr=fopen(temp,"w");

        //printf("%s\n",temp);
        //fwrite(strrr,1,strlen(strrr),fptr);
        fputs(strrr,fptr);
        fclose(fptr);

        SetFileAttributes(temp,FILE_ATTRIBUTE_NORMAL);
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
                            printf("The line hasn't any other characters");
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
        for(int m=0;m<str_insert[m]!=NULL;m++){
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

        char strrr[1000];
        fread(strrr,1000,1,ptr);
        fclose(ptr);
        //printf("%s",strrr);
        char temp[100]="p";
        strcat(temp,file_name);
        FILE* fptr;
        fptr=fopen(temp,"w");
        //printf("%s\n",temp);
        fputs(strrr,fptr);
        fclose(fptr);

        SetFileAttributes(temp,FILE_ATTRIBUTE_HIDDEN);
        ptr=fopen(file_name,"r");
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
    char str1[100000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
	}

	else{
        fread(str1,100000,1,ptr);
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
    char str1[100000];
    int counter=0;
    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
	}

	else{
        fread(str1,10000,1,ptr);
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
            printf("-1");
            return -1;
        }
    }
}

void find_at(char file_name[],char wanted_word[],int number){
    FILE* ptr;
    char str1[100000];
    int counter=0;
    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
	}

	else{
        fread(str1,10000,1,ptr);
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
    char str1[100000];
    int counter=0;
    int counters[10000];
    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
	}

	else{
        fread(str1,10000,1,ptr);
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
                counters[counter]=i-l_wanted_word;
                counter++;
            }
            else{
                i++;
            }
        }
        if(counter>=1){
            int m;
            for(m=0;m<counters[m+1]!=NULL;m++){
                printf("%d, ",counters[m]);
            }
            printf("%d",counters[m]);
        }
        else{
            printf("-1");
            return -1;
        }
    }

}

void find_byword(char file_name[],char wanted_word[]){
    FILE* ptr;
    char str1[100000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
		return;
	}

    fread(str1,100000,1,ptr);
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
            printf("%d",word_number);
            return;
            //space_counter1+=space_counter2;
            //count_word++;
            return;
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
        printf("-1");
        return;

}

void find_byword_at(char file_name[],char wanted_word[],int at){
    int goh=0;
    FILE* ptr;
    char str1[100000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
		return;
	}

    fread(str1,100000,1,ptr);
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
                printf("%d",word_number);
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
        printf("-1");
        return;

}

void find_byword_all(char file_name[],char wanted_word[]){
    int goh=0;
    char keke[1000];
    FILE* ptr;
    char str1[1000];

    ptr = fopen(file_name, "r");

    if (NULL == ptr) {
		printf("This file hasn't existed yet \n");
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
        printf("%d",keke[i]);
        return;
    }
    //printf("%d",strlen(word_number));
        printf("-1");
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
}

void replace(char file_name[],char *oldsub,char *newsub){

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
}

void grep(char file_name[],char patern[]){

    FILE*ptr=fopen(file_name,"r");

    if(ptr==NULL){
    printf("The program hasn't existed yet\n");
    printf("-1\n");
    return;
    }
    char line[1000];

    while(fscanf(ptr,"%999[^\n]",line)!=EOF){
        if(strstr(line,patern)!=NULL){
        printf("%s: %s\n",file_name,line);
    }
    fscanf(ptr,"\n",line);

    }

        fclose(ptr);
}

void grep_C(char file_name[],char patern[]){

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
            printf("%d\n",counter);
        }
}

void grep_I(char file_name[],char patern[]){

    FILE*ptr=fopen(file_name,"r");

    int counter=0;

    if(ptr==NULL){
    printf("The program hasn't existed yet\n");
    exit(-1);
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
            printf("%s\n",file_name);
        }
}

void undo(char file_name[]){
    char strrr[1000];
    char t[1000];
    char temp[]="p";
    strcat(temp,file_name);

    SetFileAttributes(temp,FILE_ATTRIBUTE_NORMAL);
    FILE*fptr;
    fptr=fopen(temp,"r");
    if(fptr==NULL){
        printf("No change exists");
        return;
    }

    fread(strrr,1000,1,fptr);
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
            s[j]='\0';
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
            int counter=i;
            int space=0;
            while(str[i-1]==' '){
                i--;
                space++;
            }

            i=counter;
            j-=space;
            s[j]='\n';
            j++;

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
                s[j]='\0';
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

   ptr=fopen(file_name,"w");
   fputs(s,ptr);
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

void tree(char *file_name,int start,int depth){
    int i;
    char path[1000];
    struct dirent *directory;
    DIR *dir = opendir(file_name);

    if (!dir){
        return;
    }

    while ((directory = readdir(dir)) != NULL){
        if (strcmp(directory->d_name,".")!= 0 && strcmp(directory->d_name, "..") != 0 && directory->d_name[0]!='.' && directory->d_name[0]!='0'){
            for (i=0; i<start; i++){

                if (i%2 ==0 && i!=0){
                    printf("%c", 179);
                }
                else{
                    if(i!=0){
                       // printf(" ");
                    }
                }
            }
            if(i>0)
            printf("%c%c%c%c%c",195,196,196,196,196);
            printf("%s\n",directory->d_name);
            strcpy(path, file_name);
            strcat(path, "/");
            strcat(path, directory->d_name);
            if(counter<wanted_depth){
                counter++;
                tree(path, start + 2,depth+1);
            }
        }
    }

    counter--;
    closedir(dir);
}



