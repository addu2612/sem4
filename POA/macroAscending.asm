sort MACRO
    MOV CH, 04H                ; Initialize outer loop counter to 4 (number of pairs)
UP2:
    MOV CL, 04H                ; Initialize inner loop counter to 4 (number of elements in a pair)
    LEA SI, STRING1            ; Load effective address of STRING1 into SI (pointer to the array)
UP1: 
    MOV AL, [SI]               ; Move first byte of the pair into AL
    MOV BL, [SI + 1]           ; Move second byte of the pair into BL
    CMP AL, BL                 ; Compare bytes to check if they are in ascending order
    JC DOWN                    ; Jump to DOWN if AL < BL (carry flag is set)
    MOV DL, [SI + 1]           ; Move second byte into DL
    XCHG [SI], DL              ; Swap the bytes
    MOV [SI + 1], DL           ; Move swapped byte back
DOWN:
    INC SI                     ; Move to the next pair
    DEC CL                     ; Decrement inner loop counter
    JNZ UP1                    ; Jump to UP1 if CL is not zero (repeat inner loop)
    DEC CH                     ; Decrement outer loop counter
    JNZ UP2                    ; Jump to UP2 if CH is not zero (repeat outer loop)
ENDM                           ; End of macro definition

DATA SEGMENT
    STRING1 DB 99H, 12H, 56H, 45H, 36H   ; Define the array STRING1 with the data to be sorted
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA          ; Move address of DATA segment into AX
    MOV DS, AX            ; Set DS to point to DATA segment
    sort                ; Invoke sort macro to sort the array
CODE ENDS
END START
