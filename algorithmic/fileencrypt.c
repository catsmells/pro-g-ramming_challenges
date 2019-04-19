#include <stdio.h>
#include <string.h>
void encrypt(FILE *);
void decrypt (FILE *);
void xx (FILE *);
int main(int argc, char *argv[]){
    FILE *fp;
    int i;
    char buffer[BUFSIZ];
    char *find
    if((fp=fopen(argv[1],"w+"))==NULL){
        perror("Error");
        getchar();
        return 1;
    }
    fputs("Please enter text. ",stdout);
    fputs("Press {Return} twice to complete. ",stdout);
    putchar('\n');
    while((fgets(buffer,BUFSIZ,stdin))!=NULL&&buffer[0]!='\n'){
      if((find=strchr(buffer,'\n'))!=NULL)
        *find='\0'; 
        fputs(buffer,fp);
    }   
    puts("Press {Return} to encrypt file ");
    getchar();
    encrypt(fp);
    puts("Result: ");
    xx(fp);
    puts("Press {Return} to decrypt the file ");
    getchar();
    decrypt(fp);
    puts("This is the file decrypted: ");
    xx(fp);
    puts("Press {Return} when ready to close file. ");
    getchar();
    if((fclose(fp))!=0)
       perror("Error");
    puts("File closed!");
    getchar();
    return 0;
}  
void encrypt(FILE *file){
    rewind(file);
    int i;
    while((i=fgetc(file))!=EOF){
        i=i+1;
        fseek(file,-1,SEEK_CUR);
        fputc(i,file);
        fseek(file,0,SEEK_CUR);
    }
}
void decrypt(FILE *file){
    rewind(file);
    rewind(file);
    int i;
    while((i=fgetc(file))!=EOF){
        i=i-1;
        fseek(file,-1,SEEK_CUR);
        fputc(i,file);
        fseek(file,0,SEEK_CUR);
    }
}     
void xx (FILE *file){
    rewind(file);
    fprintf(stdout,"*******\n");
    int i;
    while((i=fgetc(file))!=EOF)
        fputc(i,stdout);
    putchar('\n'); 
}  
