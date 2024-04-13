DATA SEGMENT
    A DB 5           ; Define variable A with value 5
    FACT DB ?        ; Define variable FACT to store the factorial result
DATA ENDS

CODE SEGMENT
    ASSUME DS:DATA, CS:CODE
START:
    MOV AX, DATA     ; Move address of DATA segment into AX
    MOV DS, AX       ; Set DS to point to DATA segment
    MOV AH, 00       ; Clear AH register
    MOV AL, A        ; Move the value of A into AL

L1:
    DEC A            ; Decrement the value of A
    MUL A            ; Multiply AL by the value in A
    MOV CL, A        ; Move the value of A into CL
    CMP CL, 01       ; Compare CL with 1
    JNZ L1           ; Jump to L1 if CL is not 1 (repeat the loop)
    MOV FACT, AL     ; Move the result in AL to FACT
CODE ENDS
END START
