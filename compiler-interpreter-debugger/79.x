asm{
  "[bits 16]",
  "[org 0x7c00]"
}char pchar;pchar=0; 
char x_pos,y_pos;
x_pos=0;y_pos=0;
char enter_key;enter_key=0x1c;
char vbuffer[32];
void start(){
  char ch;
  clear_screen();
  for(ch='A';ch<='Z';ch++){
    pchar=ch;
    print_char();
  }goto_newline();
  vbuffer[0]='r';
  vbuffer[1]='t';
  vbuffer[2]='r';
  vbuffer[3]='n';
  vbuffer[4]=':';
  vbuffer[5]=0;
  print_array();
  goto_newline();goto_newline();
  input_test();
}void print_array(){char i;
  for(i=0;i<32;i++){
    pchar=vbuffer[i];
    if(pchar==0){
      break;
    }else{
      print_char();
    }}}void input_test(){
  short key;
  char key_code;
  while(1){
    key=read_key();
    pchar=(char)key;
    key=key & 240;
    key_code=key;if(key_code==enter_key){
      goto_newline();
    }else{
      print_char();
    }}}void goto_newline(){
  y_pos++;
  x_pos=0;
  gotoxy();
}short read_key(){asm{
    "\tmov ax,0x00",
    "\tint 0x16"
  }}void gotoxy(){asm{"\tmov ah, 0x02",
    "\tmov bh,0x00",
    "\tmov dl,%"["=m"(x_pos):],
    "\tmov dh,%"["=m"(y_pos):],
    "\tint 0x10"}}void print_char(){asm{
    "\txor bx,bx",
    "\tmov bl,10",
    "\tmov al,%"["=m"(pchar):],
    "\tmov ah,0x0E",
    "\tint 0x10"}}void clear_screen(){
  asm{
      "\tmov al, 2",
      "\tmov ah, 0",
      "\tint 0x10"
  }}asm{
  "times(510-($-$$))db 0x00",
  "dw 0xAA55"}
