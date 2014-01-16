.model small
.data
    string db "\nSHOBHIT$"
    fnd db "FOUND$"
    ntfnd db "NOT FOUND$"
.code      

    mov AX,@data
    mov DS,AX
    
    MOV AH,01h
    INT 21h
    
    MOV SI,offset string
    
    l:
        mov bl,[SI]
        cmp bl,'$'
        jz notfound 
        
        cmp AL,bl
        jz found
        
        inc SI
        
    jmp l

    found:  
        mov DX,offset fnd
        mov AH, 09h
        int 21h
        
        jmp endprog
    
    notfound:
        mov DX,offset ntfnd
        mov AH, 09h
        int 21h
    endprog:
    