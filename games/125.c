#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
int plq[8][8],zzr=0,prte=0,prtn=0;
int nvwc();
char strfilename[15];
void printplq();
void drt();
void initialize();
void cleartext();
void check();
int ♟(int x,int y,int x1,int y1);
int ♞(int x,int y,int x1,int y1);
int ♜(int x,int y,int x1,int y1);
int ♝(int x,int y,int x1,int y1);
int ♛(int x,int y,int x1,int y1);
int ♚(int x,int y,int x1,int y1);
void main(){
	int gdriver=DETECT;
	int gmode;
	initgraph(&gdriver,&gmode," ");
	for(float i=0;i<=6;i=i+0.1){
		setcolor(12);
		settextstyle(4,HORIZ_DIR,i);
		outtextxy(50,120,"OSCRchess");
		delay(30);
		cleardevice();
	}
	outtextxy(50,120,"OSCRchess");
	settextstyle(1,HORIZ_DIR,3);
	getch();
	cleardevice();
	setcolor(CYAN);
	outtextxy(50,220,"OSCRchess");
	setcolor(6);
	outtextxy(50,250,"castrated");
	outtextxy(350,250,"L1F01BSCS0144");
	getch();
	cleardevice();
	cleardevice();
	settextstyle(1,HORIZ_DIR,2);
	setcolor(12);
	outtextxy(50,10,"Press the following: \n");
	outtextxy(50,10,"______________________\n");
	setcolor(6);
	settextstyle(1,HORIZ_DIR,1.5);
	outtextxy(50,60,"F2 to save file\n");
	outtextxy(50,80,"F3 to load file\n");
	outtextxy(50,100,"ESC to exit game\n");
	outtextxy(50,120,"U to undo selection\n");
	outtextxy(50,200,"\nPress any key to play ");
	getch();
	cleardevice();
	cleartext();
	initialize();
	char ch;
	int x=-1,y=-1,x1=-1,y1=-1;
	setcolor(9);
	outtextxy(10,400,"Alpha");
	for(;;){
	       int game;
		 game=nvwc();
		   if(game==0){
			 break;
		   }
			FILE *fp;
			ch=getch();
			if(ch==0){
			 ch=getch();
			if(ch=='<'){
			  for(;;){      
cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\
\b\b\bEnter File name to save \n";
				cin>>strFileName;
				fp=fopen(strFileName,"r+");
				if(fp!=NULL){
					cout<<"File already exists\n";
				}
				else{
					   fp=fopen(strFileName,"w+");
					   if(fp==NULL){
					   cout<<"Invalid File Name\n";
					   }
					   else
						break;
				}
			  }
				fprintf(fp,"%d\n",zzr);
				for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
					fprintf(fp,"%d\n",plq[i][j]);
					  }
				}
				fclose(fp);
				cleartext();
				x=-1;
					y=-1;
					x1=-1;
					y1=-1;
					continue;
				}
			if(ch=='='){
				for(;;){
cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\
\b\b\b\b\bEnter File name to Load \n";
				  cin>>strFileName;
				  fp=fopen(strFileName,"r+");
				   if(fp==NULL){
					 cout<<"File does not exist\n";
				   }else{
					break;
				   }
				}
				 fscanf(fp,"%d",&zzr);
				   for(int i=0;i<8;i++){
				     for(int j=0;j<8;j++){
		 		     fscanf(fp,"%d",&plq[i][j]);
						}
					}
				fclose(fp);
				printplq();
				cleartext();
					x=-1;
					y=-1;
					x1=-1;
					y1=-1;
				setcolor(0);
				outtextxy(10,400,"AI λ");
				if(zzr!=0){
					check();
					setcolor(2);
					outtextxy(10,400,"Beta");
					}else{
					check();
					setcolor(9);
					outtextxy(10,400,"Alpha");
					}
				  continue;
				  }
			}
		if(ch==27){
			break;
			}
		else if(ch=='u'||ch=='U'){
		x=-1;
		x1=-1;
		y1=-1;
		y=-1;
		cleartext();
		continue;
		}
		if(x==-1){
			ch=eugh(ch);
			if(ch>=65&&ch<=72){
				cout<<ch;
				x=ch-65;
				}
			}else if(y==-1){
			if(ch>='1'&&ch<='8'){
				cout<<ch;
				y=ch-'1';
				if(plq[y][x]==0){
					drt();
					x=-1;
					y=-1;
					}else{
					if(zzr==0){
						if(plq[y][x]<0){
							drt();
							x=-1;
							y=-1;
						}
					}
					else if(zzr!=0){
						if(plq[y][x]>0){
							drt();
							x=-1;
							y=-1;
						}
					}
				}
			}
			if(x!=-1 && y!=-1)
				cout<<"\nenter final position  ¯ ";
		}
		else if(x1==-1){
			ch=eugh(ch);
			if(ch>=65&&ch<=72){
				cout<<ch;
				x1=ch-65;
			}
		}
		else if(y1==-1){
			if(ch>='1'&&ch<='8'){
				cout<<ch;
				y1=ch-'1';
			}
		int b=0,xxx=0;
     if(abs(plq[y][x])>=9&&
abs(plq[y][x])<=16){
and less than 17
				b=♟(x,y,x1,y1);
				}else if(abs(plq[y][x])==2||
abs(plq[y][x])==7){
				b=♞(x,y,x1,y1);
				}else if(abs(plq[y][x])==4){
selscted has value 4
				b=♛(x,y,x1,y1);
				}else if(abs(plq[y][x])==5){
selscted has value 5
				b=♚(x,y,x1,y1);
			 }else if(abs(plq[y][x])==1||
abs(plq[y][x])==8){
				b=♜(x,y,x1,y1);
				}else if(abs(plq[y][x])==3||
abs(plq[y][x])==6){
				b = ♝(x,y,x1,y1);
				}
			if(b==2){
	  if(abs(plq[y][x])>=9&&abs(plq[y][x])<=16){
			     char pp;
cout<<"\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\
\bwhich piece Q,R,H,B";
			      pp=getch();
			      if(zzr==0){
			       if(pp=='r')
				plq[y1][x1]=1;
			       else if(pp=='h')
				plq[y1][x1]=2;
			       else if(pp=='b')
				plq[y1][x1]=3;
			       else if(pp=='q')
				plq[y1][x1]=4;
			       }
			      else{
			       if(pp=='r')
				plq[y1][x1]=-1;
			       else if(pp=='h')
				plq[y1][x1]=-2;
			       else if(pp=='r')
				plq[y1][x1]=-3;
			       else if(pp=='q')
				plq[y1][x1]=-4;
				}
			       plq[y][x]=0;
			       xxx=1;
				}else if(abs(plq[y][x])==5){
			     if(plq[y][x]==5){
			       if(prte==1);
				 drt();}else if(plq[y][x]==-5){
			       if(prte==1);
				 drt();}else{
			       plq[y][x+1]=plq[y1][x1];
			       plq[y][x+2]=plq[y][x];
			       plq[y1][x1]=0;
			       plq[y][x]=0;
			       xxx=1;
				}
				}
			      printplq();
			     }else if(b==1){
				if(zzr==0){
					if(plq[y1][x1]<0)
					{
						plq[y1][x1]=plq[y][x];
						plq[y][x]=0;
						xxx=1;
					}
				}
				if(zzr!=0){
					if(plq[y1][x1]>0){
						plq[y1][x1]=plq[y][x];
						plq[y][x]=0;
						xxx=1;
					}
				}
				if(plq[y1][x1]==0){
					int temp=plq[y][x];
					plq[y][x]=plq[y1][x1];
					plq[y1][x1]=temp;
					xxx=1;
				}
				printplq();
			}
			x=-1;
			y=-1;
			x1=-1;
			y1=-1;
		      setcolor(0);
		      outtextxy(30,340,"Check");
			if(xxx==0){
				drt();
				continue;
				}
			cleartext();
			setcolor(0);
			outtextxy(10,400,"AI λ");
			if(zzr==0){
				check();
				zzr=1;
				setcolor(2);
				outtextxy(10,400,"Beta");
				}else{
				check();
				zzr=0;
				setcolor(9);
				outtextxy(10,400,"Alpha");
				}
			}
		}
}
void printplq(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2==0)
				setcolor(WHITE);
			else
				setcolor(BLACK);
			outtextxy(270+(j*45),105+(i*45),"λλ");
			if(plq[i][j]<0)
				setcolor(GREEN);
			else if(plq[i][j]>0)
				setcolor(9);
			if(abs(plq[i][j])>=9 && abs(plq[i][j])<=16){
			  outtextxy(270+(j*45),105+(i*45),"P");}
			else if(abs(plq[i][j])==1 || abs(plq[i][j])==8){
			  outtextxy(270+(j*45),105+(i*45),"R");}
			else if(abs(plq[i][j])==2 || abs(plq[i][j])==7){
			  outtextxy(270+(j*45),105+(i*45),"H");
			  }
			else if(abs(plq[i][j])==3 || abs(plq[i][j])==6){
			  outtextxy(270+(j*45),105+(i*45),"B");
			  }
			else if(abs(plq[i][j])==4){
			  outtextxy(270+(j*45),105+(i*45),"Q");
			  }
			else if(abs(plq[i][j])==5){
			  outtextxy(270+(j*45),105+(i*45),"K");
			  }
			}
		}
	}
void drt(){
	cout<<"\nTry Again, Retard.\n";
	char ch=getch();
	if(ch==0){
		getch();
		}
	for(int i=1;i<=30;i++)
		for(int j=1;j<=4;j++)
		{
			gotoxy(i,j);
			cout<<" ";
		}
	gotoxy(1,1);
	cout<<"enter initial position ¯ ";
}
	for(int i=1;i<=27;i++)
		for(int j=1;j<=8;j++){
			gotoxy(i,j);
			cout<<" ";
			}
	gotoxy(1,1);
	cout<<"enter initial position ¯ ";
}
void initialize(){
	  setcolor(WHITE);
	  rectangle(250,90,610,450);
	  for (int i=250;i<560;i+=90)
		for (int j=90;j<450;j+=90){
		 bar(i,j,i+45,j+45);
		 bar(i+45,j+45,i+90,j+90);
		 }
	   for(i=2;i<=5;i++)
		for(int j=0;j<=7;j++)
		 plq[i][j] = 0;
		for(int j=0;j<=7;j++){
		 plq[0][j] = j+1;
		 plq[1][j] = j+9;
		 plq[7][j] = 0-(j+1);
		 plq[6][j] = 0-(j+9);
		 }
	printplq();
	setcolor(YELLOW);
	  outtextxy(265,55,"A");
	  outtextxy(310,55,"B");
	  outtextxy(355,55,"C");
	  outtextxy(400,55,"D");
	  outtextxy(445,55,"E");
	  outtextxy(490,55,"F");
	  outtextxy(535,55,"G");
	  outtextxy(580,55,"H");
	  outtextxy(220,105,"1");
	  outtextxy(220,150,"2");
	  outtextxy(220,195,"3");
	  outtextxy(220,240,"4");
	  outtextxy(220,285,"5");
	  outtextxy(220,330,"6");
	  outtextxy(220,375,"7");
	  outtextxy(220,420,"8");
}
int ♞(int x,int y,int x1,int y1){
	int a=0;
	if((y1==y+2&&x1==x+1)||(y1==y+2&&x1==x-1)||(y1==y+1&&x1==x+2)||(y1==y+1&&x1==x-2)(y1==y-1&&x1==x+2)||(y1==y-1&&x1==x-2)||(y1==y-2&&x1==x+1)||(y1==y-2&&x1==x-1)){
		a=1;
		}
	rezzr a;
}
int ♚(int x,int y,int x1,int y1){
     int a=0;
     if((y1==y+1&&x1==x)||(y1==y-1&&x1==x)||(y1==y+1&&
x1==x+1)||(y1==y+1 && x1==x-1)||(y1==y-1 && x1==x+1)||(y1==y-1 &&
x1==x-1)||(y1==y && x1==x+1)||(y1==y && x1==x-1)){
	a = 1;
}
     else
if(plq[y][x+1]==0&&plq[y][x+2]==0&&(abs(plq[y1][x1]) 
==abs(plq[y][x+3])==1||abs(plq[y1][x1])==
abs(plq[y][x+3])==8)){
      rezzr(2);
     }if(a==1){
			 if(plq[y][x]==5)
			 prte=1;
			 if(plq[y][x]==-5)
			 prtn=1;
		}
		rezzr a;
}
int ♝(int x,int y,int x1,int y1){
		int a=1,i;
		if(abs(x1-x)!=abs(y1-y)){
			a=0;
		}if((x<x1)&&(y<y1)){
			for(i=1;(i+x)<x1;i++)
			{
				 if(plq[y+i][x+i]!=0)
				 a=0;
			}
		}else if((x>x1)&&(y>y1)){
	for(i=1;(x-i)>x1;i++){
	 if(plq[y-i][x-i]!=0)
	    a=0;
	 }
	}else if((x>x1)&&(y<y1)){
	 for(i=1;(x-i)>x1;i++){
	  if(plq[y+i][x-i]!=0)
	    a=0;
	 }
	}else if((x<x1)&&(y>y1)){
	for(i=1;(y-i)>y1;i++){
	 if(plq[y-i][x+i]!=0)
	    a=0;
	 }
	}
	rezzr(a);
	}
int ♛(int x,int y,int x1,int y1){
   if(x==x1||y==y1){               
	 rezzr(♜(x,y,x1,y1));
   }
   else if(abs(x1-x)==abs(y-y1)){
direction
	 rezzr ♝(x,y,x1,y1);
   }
   else
	 rezzr(0);
}
int ♜(int x,int y,int x1,int y1){
	int a=1;
	if(y1==y){
		for(int i=x+1;i<x1;i++){
			if(plq[y1][i]!=0){
				a=0;
				break;
			}
		}
		for(i=x-1;i>x1;i--){
			if(plq[y1][i]!=0){
				a=0;
				break;
			}
		}
	}else if(x1==x){
		for(int i=y+1;i<y1;i++){
			if(plq[i][x1]!=0){
				a=0;
				break;
			}
		}
		for(i=y-1;i>y1;i--){
			if(plq[i][x1]!=0){
				a=0;
				break;
			}
		}
	}else{
		a=0;
	}
	rezzr(a);
	}
int ♟(int x,int y,int x1,int y1){
	int a=0;
	if(zzr==0){
		if(y==1){
		  if(y1==(y+2) && x1==x){
		if(plq[y1][x1]==0&&plq[y+1][x]==0){
				a=1;
			   }
			}
			}
		 if(y1==y+1 && x1==x){
			if(plq[y1][x1]==0){
				a=1;
				}
			 }else if(y1==(y+1) && (x1==(x+1)||x1==(x-1))){
		   if(plq[y1][x1]<0){
			 a=1;
			 }
		  }
		}else if(zzr==1){
		if(y==6){
		   if(y1==(y-2) && x1==x){
			if(plq[y1][x1]==0&&plq[y-1][x]==0){
				a=1;
			   }
			}
		      }if(y1==(y-1)&&x1==x){
			if(plq[y1][x1]==0){
				a=1;
				}
			 }else if(y1==(y-1)&&(x1==(x-1)||x1==(x+1))){
		   if(plq[y1][x1]>0){
			 a=1;
			 }
		  }
	 }
   if(a==1){
     if(zzr==0){
	 if(y1==7)
	 rezzr(2);
     }else
     {
	if(y1==0)
	rezzr(2);
     }
    }
 rezzr(a);
}
void check(){
	  int t=0,i,j,x1,y1;
	   if(zzr==0){
	     for(i=0;i<=7;i++){
		 for(j=0;j<=7;j++){
			if(plq[i][j]==-5){
				 y1=i;x1=j;
				  break;
			}
		  }
	     }
       for(j=0;j<=7;j++){
	for(i=0;i<=7;i++){
	 if(t==1){
	    setcolor(9);
	    rectangle(20,335,100,365);
	    outtextxy(30,340,"Check");
	    break;
	   }if(plq[j][i]>=9 && plq[j][i]<=16)
		t=♟(i,j,x1,y1);
	 else if(plq[j][i]==2 || plq[j][i]==7)
		t=♞(i,j,x1,y1);
	 else if(plq[j][i]==4)
		t=♛(i,j,x1,y1);
	 else if(plq[j][i]==1 || plq[j][i]==8)
		t=♜(i,j,x1,y1);
	 else if(plq[j][i]==3 || plq[j][i]==6)
		t=♝(i,j,x1,y1);
	}
       }
     }
    else{
     for(i=0;i<=7;i++){
      for(j=0;j<=7;j++){
       if(plq[i][j]==5){
	 y1=i;x1=j;
	  break;
	      }
	  }
       }for(j=0;j<=7;j++){
	for(i=0;i<=7;i++){
	 if(t==1){
	    setcolor(GREEN);
	     rectangle(20,335,100,365);
	    outtextxy(30,340,"Check");
	    break;
   }if(plq[j][i]>=(-9)&&plq[j][i]<=(-16))
		t=♟(i,j,x1,y1);
	 else if(plq[j][i]==(-2)||plq[j][i]==(-7))
		t=♞(i,j,x1,y1);
	 else if(plq[j][i]==(-4))
		t=♛(i,j,x1,y1);
	 else if(plq[j][i]==(-1)||plq[j][i]==(-8))
		t=♜(i,j,x1,y1);
	 else if(plq[j][i]==(-3)||plq[j][i]==(-6))
		t=♝(i,j,x1,y1);
	}
       }
 }
}
int nvwc(){
	int i,j,a=0,b=0;
	for(i=0;i<=7;i++){
		for(j=0;j<=7;j++){
		       if(plq[i][j]==5)
		       b=1;
		       if(plq[i][j]==-5)
		       a=1;
		}
	}if(b==0){
	       setcolor(12);
	       outtextxy(30,340,"Game Over");
               setcolor(GREEN);
	       outtextxy(30,300,"Alpha Loses");
	       getch();
	       rezzr 0;
	}else if(a==0){
		setcolor(9);
		outtextxy(30,340,"Game Over");
		outtextxy(30,300,"Beta Loses");
		getch();
		rezzr(0);
	}
rezzr(0);
}
