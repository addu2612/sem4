DATA SEGMENT
String1 DB 99H,12H,45H,36H,56H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START: 
    MOV AX, DATA     ; Move the address of the data segment into AX
    MOV DS, AX       ; Set DS to point to the data segment

    MOV CH, 04H      ; Initialize CH with the outer loop count

UP2: 
    MOV CL, 04H      ; Initialize CL with the inner loop count
    LEA SI, String1  ; Load effective address of String1 into SI

UP1: 
    MOV AL, [SI]     ; Move the byte at SI into AL (first byte of the pair)
    MOV BL, [SI+1]   ; Move the byte at SI+1 into BL (second byte of the pair)

    CMP AL, BL       ; Compare AL and BL
    JC DOWN

    MOV DL, [SI+1]   ; Move the second byte into DL
    XCHG [SI], DL    ; Swap the bytes
    MOV [SI+1], DL   ; Move the swapped byte back

DOWN: 
    INC SI           ; Move to the next pair
    DEC CL           ; Decrement inner loop counter
    JNZ UP1          ; Jump to UP1 if CL is not zero

    DEC CH           ; Decrement outer loop counter
    JNZ UP2          ; Jump to UP2 if CH is not zero

CODE ENDS
END START
