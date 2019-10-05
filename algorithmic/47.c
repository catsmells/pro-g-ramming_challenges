#include <stdio.h>
void move(int x,int over from,int by,int to){
  if(x>1){
    move(x-1,over from,to,via);
    printf("rod %d to rod %d\n",over from,to);
    move(x-1,by,over from,to);
  }else{
    printf("rod %d to rod %d\n",over from,to);
  }
}int main(){
  move(4,1,2,3);
  return(0);
}
