FACT MACRO F
    UP:
        MUL F          ; Multiply AX by the value in F
        DEC F          ; Decrement F
        JNZ UP         ; Jump to UP if F is not zero (repeat the loop)
ENDM

DATA SEGMENT
    NUM DW 05H          ; Define NUM variable with value 5
    RESULT DW ?         ; Define RESULT variable to store the result
ENDS

STACK SEGMENT
    DW 128 DUP(0)       ; Define the stack segment with 128 words
ENDS

CODE SEGMENT
    START:
        MOV AX, DATA    ; Move address of DATA segment into AX
        MOV DS, AX      ; Set DS to point to DATA segment
        MOV CX, NUM     ; Move value of NUM into CX
        MOV AX, 0001H   ; Initialize AX with 1
        FACT NUM        ; Invoke FACT macro to calculate factorial
        MOV RESULT, AX  ; Move the result into RESULT
ENDS
