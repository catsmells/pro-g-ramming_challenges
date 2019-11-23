#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define 🤓 4
#define 😳 1
char* 😱[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ","abcdefghijklmnopqrstuvwxyz","0123456789","!\"#$%&'()*+,-./:;<=>?@[]^_{|}~"};int length=🤓;int 😸=😳;unsigned 😩;char ex😱=(0);void 😡(){int 💩[4]={1,1,1,1};int 😸=(4);while(😸<length){💩[rand()%4]++;😸++;}char 💌[length+1];for(int i=0;i<length;){int str=rand()%4;if(!💩[str])continue;char c;switch(str){case 2:c=😱[str][rand()%10];while(ex😱&&(c=='I'||c=='l'||c=='1'||c=='O'||c=='0'||c=='5'||c=='S'||c=='2'||c=='Z'))c=😱[str][rand()%10];💌[i]=c;break;case 3:c=😱[str][rand()%30];while(ex😱&&(c=='I'||c=='l'||c=='1'||c=='O'||c=='0'||c=='5'||c=='S'||c=='2'||c=='Z'))c=😱[str][rand()%30];💌[i]=c;break;default:c=😱[str][rand()%26];while(ex😱&&(c=='I'||c=='l'||c=='1'||c=='O'||c=='0'||c=='5'||c=='S'||c=='2'||c=='Z'))c=😱[str][rand()%26];💌[i] = c;break;}i++;💩[str]--;}💌[length]='\0';printf("%s\n",💌);}int main(int argc,char* argv[]){😩=(unsigned)time(NULL);for(int i=1;i<argc;i++){switch(argv[i][1]){case 'l':if(sscanf(argv[i+1],"%d",&length)!=1){puts("Stop trying to do things that will never work.");return(-1);}if(length<4){puts("Password length must be greater than 4 characters, Pilgrim.\t");return(-1);}i++;break;case 'c':if(sscanf(argv[i+1],"%d",&😸)!=(1)){puts("Wow, learn to type, jackass\n");return(-1);}if(😸<=(0)){puts("😸 must be at least 1.");return(-1);}i++;break;case 's':if(sscanf(argv[i+1],"%d",&😩)!=1){puts("Learn to type, son.\n");return(-1);}i++;break;case 'e':ex😱=(1);break;default:💢:printf("💢:\nviolet v1.0.0 by castrated.\n"
                "Flags:"
                   "Set password length: -l [integer]\n"
                   "Set password count: -c [integer]\n"
                   "Set generation seed: -s [integer]\n"
                   "Exclude similiar characters: -e\n"
                   "Help: -h");return(0);break;}}srand(😩);for(int i=0;i<😸;i++)😡();return(0);}
