DATA SEGMENT
SEG1 DB 1H,2H,3H
ENDS

EXTRA SEGMENT
SEG2 DB 3 DUP (?) ; Allocate space for 3 bytes in SEG2
ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; Move the address of the DATA segment to AX
    MOV DS, AX      ; Set the Data Segment (DS) register to the DATA segment

    MOV AX, EXTRA   ; Move the address of the EXTRA segment to AX
    MOV ES, AX      ; Set the Extra Segment (ES) register to the EXTRA segment

    LEA SI, SEG1    ; Load the effective address of SEG1 into SI
    LEA DI, SEG2    ; Load the effective address of SEG2 into DI

    MOV CX, 03H     ; Set the loop counter CX to 3 (number of bytes to copy)

X:
    MOV AH, DS:[SI]
    MOV ES:[DI], AH


    INC SI          ; Increment SI to point to the next byte in SEG1
    INC DI          ; Increment DI to point to the next byte in SEG2

    DEC CX          ; Decrement the loop counter
    JNZ X           ; Jump to label X if CX is not zero (repeat the loop)

    INT 3           ; This interrupts the program, often used for debugging

ENDS
END START
