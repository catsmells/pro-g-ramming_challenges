#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[]){
  system("clear");
  FILE *zz;
  char input[255];
  char yy;
  infile=fopen("list.txt","r");
  if(infile==NULL){
    printf("List file is either missing or corrupted.\n");
}
  else{
        yy=fgets(input,sizeof(input),infile);
        if(yy!=0){
        printf("\aTodo: %s\n\n",input);
    }
  }
  fclose(infile);
  return(0);
}
