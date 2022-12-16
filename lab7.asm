data SEGMENT
	string db "({(})$"
	result db 0
	arrOfElem db '(','[','{',')',']','}'
	outRes db "Result code: $"
data ends
stack SEGMENT
	dw 20 dup($)
stack ends
code SEGMENT
	begin:
	ASSUME ds:data, cs:code, ss:stack
	
	mov ax, data
	mov ds, ax
	xor ax, ax	
	
	mov result, 0
	
	Loop1:
	mov cl, string[si]
	cmp cl, '$'
	je outLoop
		
	mov al, string[si]
	
	push di
	cmp al, arrOfElem[di]
	je PushElem
	inc di
	cmp al, arrOfElem[di]
	je PushElem
	inc di
	cmp al, arrOfElem[di]
	je PushElem
	pop di
	
	;add di, 3
	cmp al, arrOfElem[di+3]
	je PopElem
	cmp al, arrOfElem[di+4]
	je PopElem
	cmp al, arrOfElem[di+5]
	je PopElem
	jmp NextSymbStr
	
	PushElem:
	pop di
	;inc di
	inc ah
	mov dl, arrOfElem[di+3]
	push dx
	;dec di
	jmp NextSymbStr
	
	PopElem:
	pop dx
	cmp al, dl
	jne Result1
	mov dl, 0
	dec ah
	
	NextSymbStr:
	inc si
	
	jmp Loop1
	outLoop:
	
	cmp ah, 0
	jne Result2
	
	
	cmp sp,bp
	jne Result3
	jmp break
	
	
	Result2:	; не все скобки закрыты
	mov result, 2
	jmp break
	
	Result3:	; лишние скобки
	mov result, 3
	jmp break
	
	Result1: ; не соответствуют скобки
	mov result, 1
	
	break:
	xor ax,ax
	xor dx,dx
	xor bx,bx
	xor cx,cx
	
	mov ah,9h
	mov dx, offset outRes
	int 21h
	
	mov al, result
	add al, 30h
	mov ah, 2h
	mov dl, al
	int 21h
	
	mov ah, 4ch
	int 21h
	
	
code ends	
end begin