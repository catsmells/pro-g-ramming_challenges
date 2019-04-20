#include<stdio.h>
#define LL 13
int main(void){
    int c,e;
    while((c=getchar())!=EOF){
        if(c >='A' && c <='Z'){
            if((e=c+LL)<='Z')
                putchar(e);
            else{
                   e=c-LL;
                putchar(e);
            }
        }else if(c>='a'&&c<='z'){
            if((e=c+LL)<='z')
                putchar(e);
            else{
                e=c-LL;
                putchar(e);
            }
        }else
            putchar(c);
    }
return(0);
}
