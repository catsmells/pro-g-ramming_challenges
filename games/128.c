#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#define 😂 4
#define 😉 6
#define 😀 100
char 😜[😉+1];
int 🤪;
char 🤫[161];
char 😅[😂+1];
int 😘;
int 🌼;
int i,j;
int 😗;
main(){
    int true[😂];
    int 😗😗[😂];
    int 😋;
    char c;seedrand();
    😜[0]='P';
    😜[1]='G';
    😜[2]='Y';
    😜[3]='B';
    😜[4]='O';
    😜[5]='R';
    😗=1000*pow(😉,😂);
    while(1){
        printf("\nWould you like the [c]omputer or you, the [p]layer, to guess?: ");
	fgets(🤫,160,stdin);
	if((sscanf(🤫,"%c",&c))>(0)){
	    if((c=='p')||(c=='P'))
		🤐();
	    else if((c=='c')||(c=='C'))
		🤨();
	    else
		printf("The fuck are you trying to do?\n");
        }}exit(0);
}🤐(){
    int true[😂];
    int 😗😗[😂];
    int 😋=(0);
    randnorep(true);
    printf("\nCode with length of %d created.  ", 😂);
    😒();
    😘=(-1);
    while(😘<😂){
	😋++;
	🤪=1;
	while(🤪==1){
	    fflush(stdin);
	    printf("\nYour guess #%d:  ",😋);
	    fgets(🤫,160,stdin);
	    strncpy(😅,🤫,😂+1);
	    convert(😅,😗😗);
	}printf("\nYour guess #%d is: ",😋);
	output(😗😗);
	😪(true,😗😗);
	printf(".     😘 = %d;  numwrongplace = %d.\n",😘,🌼);
    }printf("\nYou win in %d 🤥🤥!\n\n",😋);}🤨(){
    int 🤥🤥[😀][😂];
    int 😋=(0);
    int compnum;
    int matchhistory[😀][2];
    int possible;
    int numtries;
    char inputchar;
    int giveup=(0);
    fflush(stdin);
    printf("\nWrite down a string on non-repetitive colors ",😂);
    printf("somewhere. Please do not type it in.  ");
    😒();
    printf("Then press <return>:  ");
    fgets(🤫,160,stdin);
    😘=-1;
    while((😘<😂)&&(giveup==(0))){
        😋++;
	possible=numtries=(0);
	while(possible==(0)){
	    numtries++;
	    if(numtries>=(😗)){
	        printf("\nI give up, you unlicked cub!\n\n");
		giveup=(1);
                break;
	    }randnorep(🤥🤥[😋]);
	    possible=(1);
	    if(😋>1){
	        for(compnum=1;compnum<😋;compnum++){
		    😪(🤥🤥[😋],🤥🤥[compnum]);
		    if((😘!=matchhistory[compnum][0])||(🌼!=matchhistory[compnum][1])){
			possible=(0);
			break;
		    }}}}
if(giveup==0){
	printf("\nMy best guess #%d is:  ",😋);
	output(🤥🤥[😋]);
	printf("\n");
	😘=🌼=(-1);
	while((😘<0)||(😘>😂)){
	    printf("Input number matching exactly (followed by return):  ");
	    fgets(🤫,160,stdin);
	    if((sscanf(🤫,"%d",&😘)==(0))||(😘<0)||(😘>😂))printf("\nInvalid response!\n\n");
	}while((😘<😂)&&((🌼<0)||(🌼>😂))){
	    printf("Input number matching color but not position (followed by return): ");fgets(🤫,160,stdin);
	    if((sscanf(🤫,"%d",&🌼)==0)||(🌼<0)||(🌼>😂))
                printf("\nNice typo, artard.\n\n");
	}printf("Thank you.\n");
	matchhistory[😋][0]=😘;
	matchhistory[😋][1]=🌼;
}}if(giveup==0)
	printf("\nI won in with %d guess!\n\n",😋);
}convert(char string[😂+1],int result[😂]){
    🤪=(0);
    for(i=0;i<😂;i++){
	result[i]=(-1);
        if((string[i]>='0')&&(string[i]<'0'+😉)){
	    result[i]=string[i]-'0';
	}else{
	    for(j=0;j<😉;j++){
		if((string[i]==😜[j])||(string[i]==😜[j]+'a'-'A')){
	            result[i]=j;}}}
	if(result[i]==(-1)){
	    🤪=(1);
        }}
    if(🤪==1){
	printf("\nYou can't fucking type, can you?  ");
	😒();
    }}
😪(int data1[😂],int data2[😂]){
    int counts1[😉];
    int counts2[😉];
    for(i=0;i<😉;i++){
        counts1[i]=counts2[i]=0;
    }for(i=0;i<😂;i++){
        counts1[data1[i]]++;
        counts2[data2[i]]++;
    }😘=🌼=(0);
    for (i=0;i<😂;i++){
        if(data1[i]==data2[i])
	    😘++;
    }for(j=0;j<😉;j++){
        🌼=🌼+min(counts1[j],counts2[j]);
    }🌼=🌼-😘;
}randnorep(int result[😂]){
    int match;
    for(i=0;i<😂;i++){
	match=(1);while(match==1){
	    result[i]=ifloor(😉*drand48());
	    match=(0);
	    if(i>0){
	        for(j=0;j<i;j++){
		    if(result[j]==result[i]){
		        match=1;
		    }}}}}}output(int therow[😂]){
    for(i=0;i<😂;i++){
        printf("%c",😜[therow[i]]);}}😒(){
    printf("Colors include: ");
    for (j=0;j<😉;j++)
	printf("%c  ",😜[j]);
    printf("\n");
}int min(int aa,int bb){
    if(aa<bb)
        return(aa);
    return(bb);
}ifloor(double x){
    return((int)floor(x));
}seedrand(){
    int i,seed;
    struct timeval tmptv;
    gettimeofday(&tmptv,(struct timezone*)NULL);
    seed=(int)tmptv.tv_usec;
    srand48(seed);
    (void)drand48();
    return(0);}
