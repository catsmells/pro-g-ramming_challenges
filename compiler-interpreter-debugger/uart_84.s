 ; an extremely low-effort esoteric "game" for UART chips.
 ; the objective is to run the program. if it runs correctly, you win. if it doesn't, your system halts.
 ; designed with students of university of arizona in mind, since they're fucking idiots
 .equ __30F4013A, 1

 config  __FOSC, CSW_FSCM_OFF & FRC    
 config  __FWDT, WDT_OFF
 config  __FBORPOR, PBOR_ON & BORV_27 & PWRT_16 & MCLR_EN
 config  __FGS, CODE_PROT_OFF
  
 .equ  baudrate, 24                 

 .global  __reset                        
 .global     _rs232_init
 .global     _rs232_tx
 .global     _rs232_game

 .section .data
 
 .section .text
 __reset:
     MOV  #__SP_init, W15            
     MOV  #__SPLIM_init, W0      
     MOV  W0, SPLIM
     NOP                            
     CALL    _rs232_init        
  
 start:
     CALL    _rs232_game
     
     GOTO start

 _rs232_init:
     MOV     #baudrate, W0        
     MOV     W0, U1BRG
     BSET    IPC2, #U1TXIP2          
     BCLR    IPC2, #U1TXIP1          
     BCLR    IPC2, #U1TXIP0          
     BSET    IPC2, #U1RXIP2         
     BCLR    IPC2, #U1RXIP1          
     BCLR    IPC2, #U1RXIP0          
     CLR     U1STA
     MOV     #0x8800, W0             
                                       
     MOV     W0, U1MODE              
     BSET    U1STA, #UTXEN         
     BSET    IEC0, #U1TXIE           
     BCLR    IEC0, #U1RXIE          
     RETURN

 _rs232_tx:
     MOV     W0, U1TXREG
     RETURN

 _rs232_game:
     MOV     #'W', W0
     CALL    _rs232_tx  
     MOV     #'o', W0
     CALL    _rs232_tx
     MOV     #'w', W0
     CALL    _rs232_tx
     MOV     #'!', W0
     CALL    _rs232_tx
     MOV     #' ', W0
     CALL    _rs232_tx
     MOV     #'Y', W0
     CALL    _rs232_tx
     MOV     #'o', W0
     CALL    _rs232_tx
     MOV     #'u', W0
     CALL    _rs232_tx
     MOV     #' ', W0
     CALL    _rs232_tx
     MOV     #'W', W0
     CALL    _rs232_tx
     MOV     #'i', W0
     CALL    _rs232_tx
     MOV     #'n', W0
     CALL    _rs232_tx
     RETURN
  
 .end
