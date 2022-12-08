data segment
	messg db 'Input string:$'
	endl db '',0Dh,0Ah,'$'
	input db 100,0,101 dup ('$')
	table_sym db 'A','a','E','e','I','i','O','o','Y','y','U','u', 12 dup (0)
	num db 0
	cursor dw ?
	messg2 db 'Result string: $'
	messg3 db 'Number of vowels in string: $'
	dash db ' - $'
	
data ends

stack segment
	db 256 dup(' ')
stack ends

code segment
	assume cs:code, ds:data, ss:stack
	begin:
	mov ax,data
	mov ds,ax
	
	mov ah,9h
	mov dx, offset messg
	int 21h
	
	call OutputEndl
	
	mov ah,0Ah
	lea dx, input
	int 21h
	
	call OutputEndl

	call OutputEndl
	
	mov si, 0
	xor cx,cx
	mov cl, input[si+1] ; num of cycle
	;mov num,cl
	mov di, 0
	
	; цикл замены гласных букв
	
	loop1:
	push cx
	mov bl, input[si+2]
	mov cx, 12 
		loop2:
		mov bh, table_sym[di]
		cmp bh,bl
		je replace	
		; else
		inc di
		loop loop2
		jmp end_loop1
		
			replace:	; метка замены символов
			add num, 1	; подсчет количества гласных
			mov input[si+2], '*'		
			add table_sym[di+12], 1		; подсчет количества символов по каждой букве
			jmp end_loop1
		
	end_loop1:
	mov di, 0
	inc si
	pop cx
	loop loop1
	
	mov ah,9h
	mov dx, offset messg2
	int 21h
	
	; подготовка регистров к следующей операции
	
	xor ax, ax
	xor bx, bx
	
	xor cx, cx
	mov si, 0
	mov cl, input[si+1]
	; вывод обработанной строки
	OutputStr:
	
	push cx
	mov ah,9h
	mov al, input[si+2]
	mov cx,1
	mov bh,0
	mov bl, 00000010b	; установка цвета - зеленый
	int 10h
	; записываем координаты курсора
	mov ah,3h
	mov bh,0
	int 10h
	; смещение курсора вправо
	mov ah, 2h
	mov bh, 0
	add dl, 1
	int 10h
	
	inc si
	pop cx
	loop OutputStr
	
	call OutputEndl
	
	; вывод информации о количестве гласных букв в строке
	mov dx, offset messg3
	int 21h
	
	xor ax,ax
	mov al, num
	push ax
	call OutputNumber
	pop ax
	
	call OutputEndl
	
	call OutputEndl

	; подготовка регистров к следующей операции
	mov si, 0
	xor cx, cx
	mov cx, 12
	mov di, 0
	lea di, dash
	; цикл для вывода количества встречающихся гласных букв в строке
	OutputTable:
	;push cx
	mov ah, 2h
	mov dl, table_sym[si]
	int 21h
	
	
	mov ah, 9h
	mov dx, offset dash
	int 21h
	
	xor ax,ax
	mov al, table_sym[si+12]
	push ax
	call OutputNumber
	pop ax
	
	;mov ah, 2h
	;mov dl, table_sym[si+12]
	;add dl, 30h
	;int 21h
	
	call OutputEndl
	
	inc si
	;pop cx
	loop OutputTable

	mov ah,4ch
	int 21h
	
	OutputEndl proc NEAR
	
	mov ah, 9h
	mov dx, offset endl
	int 21h
	
	ret
	endp OutputEndl
	
	OutputNumber proc NEAR
	
	push bp
	mov bp,sp
	mov bl, 10
	;xor ax,ax
	mov al, [bp+4]
	cmp al,9
	jbe LowNum
	div bl
	mov bh, ah
	
	mov ah, 2h
	add al, 30h
	mov dl, al
	int 21h
	
	mov ah, 2h
	add bh, 30h
	mov dl, bh
	int 21h
	jmp Next
	
	LowNum:
	
	mov ah, 2h
	add al,30h
	mov dl, al
	int 21h
	
	Next:
	
	mov sp,bp
	pop bp
	
	ret
	endp OutputNumber
	
code ends
end begin