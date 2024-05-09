;A program in assembly language to calculate the average of numbers in an array.
DATA SEGMENT
     ARRAY DB 1,4,2,3,8,6,7,5,9
     AVG DB ?
     MSG DB "AVERAGE = $"
ENDS

CODE SEGMENT 
    ASSUME DS:DATA CS:CODE
START:
      MOV AX,DATA
      MOV DS,AX

      LEA SI,ARRAY 
      LEA DX,MSG
      MOV AH,9
      INT 21H

      MOV AX,00
      MOV BL,9

      MOV CX,9 
      LOOP1:
           ADD AL,ARRAY[SI]
           INC SI
      LOOP LOOP1

      DIV BL

      ADD AL,30H

      MOV DL,AL
      MOV AH,2
      INT 21H

      MOV AH,4CH
      INT 21H     
ENDS
END START