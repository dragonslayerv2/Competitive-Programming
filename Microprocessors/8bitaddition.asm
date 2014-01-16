.model small

.data
    D1 db "Enter the first number$"
    D2 db "Enter the second number$"
    DR db "The result is$"
    
.code
    MOV AX,@data    
    MOV DS, AX
    
    MOV DX, OFFSET D1
    MOV AH, 09H
    INT 21H
    MOV AH,01H
    INT 21H
    SUB AL,30H
    
    MOV BL,AL
    

    
    MOV DX, OFFSET D2
    MOV AH, 09H
    INT 21H
    MOV AH, 01H
    INT 21H
    SUB AL,30H
    MOV AH,00H
   
    ADD AL,BL
    
    AAA 
    
    ADD AX,3030H
    
    MOV BX, AX
    
    MOV DL,BH
    MOV AH, 02H
    INT 21H
    
    MOV DL,BL
    INT 21H     