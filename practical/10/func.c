#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
  system("clear");
  int i=0,sum=0,n=0,avg=0;
	FILE *lmao;
	lmao=fopen("data.txt","r");
	while(fscanf(lmao,"%d",&n)!=EOF){
		sum+=n;
		i++;
		avg=(sum/i);
	}
	printf("averaging at %d minutes.\a\n");
	fclose(lmao);
	return(0);
}
