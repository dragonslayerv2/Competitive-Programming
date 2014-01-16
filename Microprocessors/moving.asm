.model small
.data
    
.code      
start:
    mov AX,@data
    mov DS,AX
    ;------------------------------------------------
    mov AL,'S'
    mov [2000h],AL
    mov AL,'H'
    mov [2001h],AL
    mov AL,'O'
    mov [2002h],AL
    mov AL,'B'
    mov [2003h],AL
    mov AL,'$'
    mov [2004h],AL
    
    
    
    ;-------------------------------------------------
    
    
    mov cl,06h
    
    MOV BX, 0h
    
    MOV DX, 3000h
    
    l:
        mov AX,BX[2000h]
        mov BX[3000h],AX
        inc BX
    loop l
        mov DX,3000h
        mov AH, 09h
        int 21h
        
end start