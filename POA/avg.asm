DATA SEGMENT
    ARR DB 1H,2H,3H,4H,5H,6H,7H,8H,9H
    LEN DW $-ARR
    SUM DW ?  
    AVG DW ?  
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
   
    MOV CX,LEN
    LEA SI,ARR
   
    MOV AX,0000H  
    MOV BX,0000H  
   
SUM_LOOP:    
    MOV BL,[SI]
    ADD AX,BX    
    INC SI
    DEC CX
    JNZ SUM_LOOP  
   
    MOV SUM,AX    
   
    MOV BX,0      
    MOV BX,LEN    
   
    MOV AX,SUM    
    DIV BL        
   
    MOV AVG,AX    
   
    MOV AH,4CH
    INT 21H
   
    CODE ENDS
END START