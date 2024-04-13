DATA SEGMENT
    MSG DB "ENTER A CHARACTER :$"  ; Define a string message
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA   ; Assume CS to be CODE segment and DS to be DATA segment
START:
    MOV AX, DATA              ; Move the address of DATA segment into AX
    MOV DS, AX                ; Set DS to point to DATA segment

    LEA DX, MSG               ; Load the effective address of MSG into DX (DX points to the message)
    MOV AH, 09H               ; Set AH to 09H for "print string" DOS interrupt
    INT 21H                   ; Print the string

    MOV AH, 01                ; Set AH to 01H for "read character" DOS interrupt
    INT 21H                   ; Read a character and store it in AL

    MOV DL, AL                ; Move the character read into DL (to print it later)
    MOV AH, 02H               ; Set AH to 02H for "print character" DOS interrupt
    INT 21H                   ; Print the character

    MOV AH, 02H               ; Set AH to 02H again for "print character" DOS interrupt
    INT 21H                   ; Print the character again (for newline)

    MOV AH, 4CH               ; Set AH to 4CH for "terminate program" DOS interrupt
    INT 21H                   ; Terminate the program

CODE ENDS
END START
