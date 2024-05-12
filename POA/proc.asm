ASSUME CS:CODE, DS:DATA, SS:STACK_SEG  ; Assumptions about segment registers

DATA SEGMENT  ; Start of the DATA segment

NUM1 DB 50H  ; Declaring NUM1 variable with initial value 50H
NUM2 DB 20H  ; Declaring NUM2 variable with initial value 20H
ADD_RES DB ?  ; Declaring ADD_RES variable to store addition result
SUB_RES DB ?  ; Declaring SUB_RES variable to store subtraction result

DATA ENDS  ; End of the DATA segment

CODE SEGMENT  ; Start of the CODE segment

START: MOV AX, DATA  ; Move the address of DATA segment to AX register
MOV DS, AX  ; Initialize the data segment by moving the address in AX to DS

CALL ADDITION  ; Call the ADDITION procedure
CALL SUBTRACTION  ; Call the SUBTRACTION procedure

MOV AH, 4CH  ; Move the exit code 4CH (indicating successful termination) to AH register
INT 21H  ; Generate software interrupt to terminate the program

ADDITION PROC NEAR  ; Start of the ADDITION procedure
MOV AL, NUM1  ; Move the value of NUM1 to AL register
MOV BL, NUM2  ; Move the value of NUM2 to BL register
ADD AL, BL  ; Add the value of BL to AL
MOV ADD_RES, AL  ; Move the result of addition to ADD_RES variable
RET  ; Return from the procedure
ADDITION ENDP  ; End of the ADDITION procedure

SUBTRACTION PROC  ; Start of the SUBTRACTION procedure
MOV AL, NUM1  ; Move the value of NUM1 to AL register
MOV BL, NUM2  ; Move the value of NUM2 to BL register
SUB AL, BL  ; Subtract the value of BL from AL
MOV SUB_RES, AL  ; Move the result of subtraction to SUB_RES variable
RET  ; Return from the procedure
SUBTRACTION ENDP  ; End of the SUBTRACTION procedure

CODE ENDS  ; End of the CODE segment

END START  ; End of the program with START as the entry point
