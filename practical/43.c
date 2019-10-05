#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#define texWidth 256
#define texHeight 256
#define screenWidth 400
#define screenHeight 300
int texture[texWidth][texHeight];
int distanceTable[2*screenWidth][2*screenHeight];
int angleTable[2*screenWidth][2*screenHeight];
int buffer[screenWidth][screenHeight];
int main(int argc,char *argv[]){
  screen(screenWidth,screenHeight,0,"jack");
  loadBMP("http://clipart-library.com/images/pTo5B6o9c.png",texture[0],texWidth,texHeight);
  for(int y=0;y<h*2;y++)
  for(int x=0;x<w*2;x++){
    int angle,distance;
    float ratio=32.0;
    distance=int(ratio*texHeight/sqrt(float((x-w)*(x-w)+(y-h)*(y-h))))%texHeight;
    angle=(unsigned int)(0.5*texWidth*atan2(float(y-h),float(x-w))/3.1416);
    distanceTable[y][x]=distance;
    angleTable[y][x]=angle;
  }float animation;
  while(!done()){
    animation=getTime()/1000.0;
    int shiftX=int(texWidth*1.0*animation);
    int shiftY=int(texHeight*0.25*animation);
    int shiftLookX=w/2+int(w/2*sin(animation));
    int shiftLookY=h/2+int(h/2*sin(animation*2.0));
    for(int y=0;y<h;y++)
    for(int x=0;x<w;x++){
      int color=texture[(unsigned int)(distanceTable[x+shiftLookX][y+shiftLookY]+shiftX)%texWidth]
                 [(unsigned int)(angleTable[x+shiftLookX][y+shiftLookY]+shiftY%texHeight];
      buffer[y][x]=color;
    }drawBuffer(buffer[0]);
    redraw();
  }return(0);
}
