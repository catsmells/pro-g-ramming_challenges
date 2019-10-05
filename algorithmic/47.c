#include <stdio.h>
void move(int x,int from,int via,int to){
  if(x>1){
    move(x-1,from,to,via);
    printf("rod %d to rod %d\n",from,to);
    move(x-1,via,from,to);
  }else{
    printf("rod %d to rod %d\n", from, to);
  }
}int main(){
  move(4,1,2,3);
  return(0);
}
