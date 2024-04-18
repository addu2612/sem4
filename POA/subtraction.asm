org 100h       ; Set the origin address to 100h, indicating the start of the program
MOV AX,[1000h] ; Move the word (2 bytes) at memory address 1000h into AX
MOV BX,[1002h] ; Move the word at memory address 1002h into BX
MOV CL,00h     ; Move the value 0 into the CL register
SUB AX,BX      ; Subtract the value of BX from AX, storing the result in AX
MOV [1004h],AX ; Move the contents of AX into memory address 1004h
JNC jump       ; Jump to the label 'jump' if the Carry Flag is not set
INC CL         ; Increment the value in the CL register
;Performing 2s complement
NOT AX         ; Bitwise NOT operation on AX (complement each bit)
ADD AX,0001h   ; Add 1 to the value in AX
jump:          ; Label 'jump', the destination of the conditional jump instruction
MOV [1006h],AX ; Move the value in AX into memory address 1006h
HLT            ; Halt the processor
ret            ; Return instruction (not typically used at the end of a program)
