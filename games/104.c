#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define XR "\033["
typedef unsigned char ppp;
int rpt[]={-2,-2,-1,1,2,2,1,-1};
int pey[]={-1,1,2,2,1,-1,-2,-2};
void erd(int w,int h,ppp **a,ppp **b){
	int i,j,k,x,y,p=w+4,q=h+4;
	a[0]=(ppp*)(a+q);
	b[0]=a[0]+2;
	for(i=1;i<q;i++){
		a[i]=a[i-1]+p;
		b[i]=a[i]+2;
	}
	memset(a[0],255,p*q);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			for(k=0;k<8;k++){
				x=j+rpt[k],y=i+pey[k];
				if(b[i+2][j]==255)b[i+2][j]=0;
				b[i+2][j]+=x>=0&&x<w&&y>=0&&y<h;
			}
		}
	}
}
int frz(int w,int h,int x,int y,ppp **b){
	int i,nx,ny,least;
	int steps=0;
	printf(XR"H"XR"J"XR"%d;%dH"XR"32m♞"XR"m",y+1,1+2*x);
	while(1){
		b[y][x]=255;
		for(i=0;i<8;i++)
			b[y+pey[i]][x+rpt[i]]--;
		least=255;
		for(i=0;i<8;i++){
			if(b[y+pey[i]][x+rpt[i]]<least){
				nx=x+rpt[i];
				ny=y+pey[i];
				least=b[ny][nx];
			}
		}
		if(least>7){
			printf(XR"%dH",h+2);
			return(steps==w*h-1);
		}
		if(steps++)printf(XR"%d;%dH♞",y+1,1+2*x);
		x=nx,y=ny;
		printf(XR"%d;%dH"XR"31m♞"XR"m",y+1,1+2*x);
		fflush(stdout);
		usleep(300000);
	}
}
int wtv(int w,int h){
	int x=0,y=0;
	ppp **a,**b;
	a=malloc((w+4)*(h+4)+sizeof(ppp*)*(h+4));
	b=malloc((h+4)*sizeof(ppp*)); 
	while(1){
		erd(w,h,a,b);
		if(frz(w,h,x,y,b+2)){
			printf("Solved.\n");
			return(1);
		}
		if(++x>=w)x=0,y++;
		if(y>=h){
			printf("Not even Blue can solve this one.\n");
			return(0);
		}
		printf("Press a key, retard\n");
		getchar();
	}
}
int main(int c,char **v){
	int w,h;
	if(c<2||(w=atoi(v[1]))<=0)w=8;
	if(c<3||(h=atoi(v[2]))<=0)h=w;
	wtv(w,h);
	return(0);
}
