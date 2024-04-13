DATA SEGMENT
ARR DB 5,3,7,1,9,2,6,8,4  ; Array containing data
LEN DW $-ARR             ; Calculate the length of the array
MIN DB ?                  ; Variable to store the minimum value
MAX DB ?                  ; Variable to store the maximum value
DATA ENDS

CODE SEGMENT
ASSUME DS:DATA,CS:CODE
START:
    MOV AX, DATA   ; Move the address of the DATA segment into AX
    MOV DS, AX     ; Set DS to point to the DATA segment

    LEA SI, ARR    ; Load effective address of ARR into SI
    MOV AL, ARR[SI] ; Move the first byte of ARR into AL
    MOV MIN, AL    ; Initialize MIN with the first byte of ARR
    MOV MAX, AL    ; Initialize MAX with the first byte of ARR

    MOV CX, LEN    ; Load the length of the array into CX
REPEAT:
    MOV AL, ARR[SI] ; Move the byte at the memory location pointed to by SI into AL
    CMP MIN, AL    ; Compare MIN with AL
    JL CHECKMAX    ; Jump to CHECKMAX if AL is less than MIN

    MOV MIN, AL    ; Update MIN if AL is smaller

CHECKMAX:
    CMP MAX, AL    ; Compare MAX with AL
    JG DONE        ; Jump to DONE if AL is greater than MAX

    MOV MAX, AL    ; Update MAX if AL is greater

DONE:
    INC SI         ; Increment SI to point to the next element of the array
    LOOP REPEAT    ; Loop until CX becomes zero

    MOV AH, 4CH    ; Set up the DOS function to terminate the program
    INT 21H        ; Call interrupt 21H to terminate the program

CODE ENDS
END START
