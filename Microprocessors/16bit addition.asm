.model small

.data
    D1 db "Enter the first number$"
    D2 db "Enter the second number$"
    DR db "The result is$"
    
.code
    MOV AX,@data    
    MOV DS, AX
   ;--------------------------------- 
    MOV DX, OFFSET D1
    MOV AH, 09H
    INT 21H
    MOV AH,01H
    INT 21H
    SUB AL,30H
    
    MOV BH,AL
   
    MOV AH,01H
    INT 21H
    SUB AL,30H
    
    MOV BL,AL
    MOV AX,BX
    AAD   
    MOV CX,AX
   ;----------------------------------
    
    MOV DX, OFFSET D2
    MOV AH, 09H
    INT 21H
    MOV AH,01H
    INT 21H
    SUB AL,30H
    
    MOV BH,AL
   
    MOV AH,01H
    INT 21H
    SUB AL,30H
    
    MOV BL,AL
    MOV AX,BX
    AAD   
    MOV BX,AX
   ;----------------------------------
    
    ADD BX,CX   
    MOV AX,BX
    OUT 199,AX
    
    AAA    
    AAA
   ; OUT 199,AX
    
    
    MOV BL,AL
    
    ADD BL,30H
    
    MOV AL,AH
    MOV AH,00H
    AAA
    ADD AX, 3030H
    
    MOV CX, AX
    
    MOV DL,CH
    MOV AH, 02H
    INT 21H
    
    MOV DL,CL
    INT 21H  
    MOV DL,BL
    INT 21H     