#include <stdio.h>
#include <math.h>
#include <unistd.h>
const char *shades=".:!<8e&#%@";
double light[3]={-50,0,50};
void normalize(double*v){
	double len=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
	v[0]/=len;v[1]/=len;v[2]/=len;
}double dot(double *x,double *y){
	double d=x[0]*y[0]+x[1]*y[1]+x[2]*y[2];
	return(d<0?-d:0);
}typedef struct{double cx,cy,cz,r;}sphere_t;
sphere_t pos={20,20,0,20},neg={1,1,-6,20};
int hit_sphere(sphere_t*sph,double x,double y,double *z1,double *z2){
	double zsq;
	x-=sph->cx;
	y-=sph->cy;
	zsq=sph->r*sph->r-(x*x+y*y);
	if(zsq<0)return(0);
	zsq=sqrt(zsq);
	*z1=sph->cz-zsq;
	*z2=sph->cz+zsq;
	return(1);
}void draw_sphere(double k,double ambient){
	int i,j,intensity,hit_result;
	double b;
	double vec[3],x,y,zb1,zb2,zs1,zs2;
	for(i=floor(pos.cy-pos.r);i<=ceil(pos.cy+pos.r);i++){
		y=i+.5;
		for(j=floor(pos.cx-2*pos.r);j<=ceil(pos.cx+2*pos.r);j++){
			x=(j-pos.cx)/2.+.5+pos.cx;
			if(!hit_sphere(&pos,x,y,&zb1,&zb2))
				hit_result=0;
			else if(!hit_sphere(&neg,x,y,&zs1,&zs2))
				hit_result=1;
			else if(zs1>zb1)hit_result=1;
			else if(zs2>zb2)hit_result=0;
			else if (zs2>zb1)hit_result=2;
			else hit_result=1;
			switch(hit_result){
			case 0:
				putchar('+');
				continue;
			case 1:
				vec[0]=x-pos.cx;
				vec[1]=y-pos.cy;
				vec[2]=zb1-pos.cz;
				break;
			default:
				vec[0]=neg.cx-x;
				vec[1]=neg.cy-y;
				vec[2]=neg.cz-zs2;
			}normalize(vec);
			b=pow(dot(light,vec),k)+ambient; //it was at this moment he realized: why didn't i do this in haskell?
			intensity=(1-b)*(sizeof(shades)-1);
			if(intensity<0)intensity=0;
			if(intensity>=sizeof(shades)-1)
				intensity=sizeof(shades)-2;
			putchar(shades[intensity]);
		}putchar('\n');
	}
}int main(){
	double ang=0;
	while(1){
		printf("\033[H");
		light[1]=cos(ang*2);
		light[2]=cos(ang);
		light[0]=sin(ang);
		normalize(light);
		ang+=.05;
		draw_sphere(2,.3);
		usleep(100000);
	}return(0);
}
