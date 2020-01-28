#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
int main(void){
    system("clear");
    Image cellular=GenImageCellular(screenWidth,screenHeight,32);
    Texture2D textures[NUM_TEXTURES]={0};
    UnloadImage(cellular);
    return(1);
}
