#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define xx for(int x=0;x<lol;x++)
#define yy for(int y=0;y<lole;y++)
#define zzz xx yy
void qw(void *u,int lol,int lole){
	int(*univ)[lol]=u;
	printf("\033[H");
	yy{
		xx printf(univ[y][x]?"\033[07m  \033[m":"  ");
		printf("\033[E");
	}
	fflush(stdout);
}void rpdx(void *u,int lol,int lole){
	unsigned(*univ)[lol]=u;
	unsigned new[lole][lol];
	yy xx{
		int n=0;
		for(int y1=y-1;y1<=y+1;y1++)
			for(int x1=x-1;x1<=x+1;x1++)
				if(univ[(y1+lole)%lole][(x1+lol)%lol])
					n++;
		if(univ[y][x])n--;
		new[y][x]=(n==3||(n==2&&univ[y][x]));
	}
	yy xx univ[y][x]=new[y][x];
}void vite(int lol, int lole){
	unsigned univ[lole][lol];
	zzz univ[y][x]=rand()<RAND_MAX/10?1:0;
	while(1){
		qw(univ,lol,lole);
		rpdx(univ,lol,lole);
		usleep(200000);
	}
}int main(int c,char **v){
	int lol=0,lole=0;
	if(c>1)lol=atoi(v[1]);
	if(c>2)lole=atoi(v[2]);
	if(lol<=0)lol=30;
	if(lole<=0)lole=30;
	vite(lol,lole);
}
