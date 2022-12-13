pacient struc
	cardNum dw 0
	gender db ?
	birthYear dw 0
	enterDate db 8 dup(?)
	dischargeDate db 8 dup (?)
pacient ends
data SEGMENT
	compareDate db '01/01/22'
	DischDate db '06/04/22'
	compNumCard db 2
	compBirthYear dw 2001
	pac1 pacient<1,'M',2001,'01/01/22','10/01/22'>
	pac2 pacient<2,'F',2001,'25/03/22','06/04/22'>
	pac3 pacient<3,'F',1995,'01/01/22','10/01/22'>
	NumOfPac db ?
	message1 db "Number of pacient for Enter date: $"
	message2 db "Number of Female pacient for Discharge date: $"
	message3 db "Birth year of pacient is: $"
	message4 db "Number of Male pacient with concrete BirthYear: $"
	endl db '',0Dh,0Ah,'$'
data ends
stack SEGMENT
	db 20 dup ('')
stack ends
code SEGMENT
	ASSUME ds:data, cs:code, ss:stack
	begin:
	mov ax, data
	mov ds, ax 
	xor ax,ax
	
	; подсчет количества пациентов по заданной
	; дате поступления
	
	lea di, pac1
	mov cx,3
	
	MainLoop1:
	push cx
	mov cx, 8
	lea si, compareDate
	push si
	lea si, [di].enterDate
	
		loop1:
		lodsb
		mov dl, al
		mov bp, si
		pop si
		lodsb
		push si
		mov si, bp
		cmp dl, al
		jne next_elem1
		inc bl
		next_elem1:
		loop loop1
	
	cmp bl, 8
	jne next_pac1
	add NumOfPac, 1
	
	next_pac1:
	add di, type pacient
	pop si
	pop cx
	xor bl,bl
	loop MainLoop1
	
	; очистка регистров
	
	mov si,0
	mov di,0
	xor ax,ax
	xor dx,dx
	
	; вывод числа пациентов, совпадающих с датой поступления
	
	mov ah, 9h
	mov dx, offset message1
	int 21h
	
	mov bh, NumOfPac
	mov ah, 2h
	add bh, 30h
	mov dl, bh
	int 21h
	
	mov ah, 9h
	mov dx, offset endl
	int 21h
	
	; вывод информации о количестве женщин с заданной датой выписки
	
	mov NumOfPac, 0
	lea di, pac1
	mov cx,3

	MainLoop2:
	push cx
	mov cx, 8
	lea si, DischDate
	push si
	lea si, [di].dischargeDate
	
		loop2:
		lodsb
		mov dl, al
		mov bp, si
		pop si
		lodsb
		push si
		mov si, bp
		cmp dl, al
		jne next_elem2
		inc bl
		next_elem2:
		loop loop2
	
	cmp bl, 8
	jne next_pac2
	
	; если даты совпали, идет проверка на пол
	
	push di
	lea si, [di].gender
	mov bh, 'F'
	lodsb
	pop di
	cmp bh, al
	jne next_pac2
	
	; если пол совпал
	
	inc NumOfPac
	
	next_pac2:
	add di, type pacient
	
	pop si
	pop cx
	xor bl,bl
	loop MainLoop2
	
	; вывод числа женщин-пациентов
	
	mov ah, 9h
	mov dx, offset message2
	int 21h
	
	mov bh, NumOfPac
	mov ah, 2h
	add bh, 30h
	mov dl, bh
	int 21h
	
	mov ah, 9h
	mov dx, offset endl
	int 21h
	
	; очистка регистров
	
	mov si,0
	mov di,0
	xor ax,ax
	xor dx,dx
	
	; поиск года рождения по номеру карты
	
	lea di, pac1
	mov bl, compNumCard
	mov cx,3
	
	NumCard:
	push cx
	
	lea si, [di].cardNum
	lodsb
	cmp bl,al
	jne next_pac3
	
	mov ah,9h
	mov dx, offset message3
	int 21h
	
	; вывод 4-значного числа
	
	push di
	mov ax, [di].birthYear
	pop di
	
	mov cx,3
	mov bl, 10
	
	Number:
	div bl
	add ah, 30h
	mov dl, ah
	mov ah, 0
	push dx
	
	loop Number
	
	add al, 30h
	mov dl, al
	push dx
	xor ax,ax
	
	mov cx,4
	OutputNumber:
	pop dx
	mov ah, 2h
	int 21h
	loop OutputNumber
	
	; конец вывода 4-значного числа и выход из цикла
	
	jmp breakLoop
	
	next_pac3:
	add di, type pacient
	pop cx
	
	loop NumCard

	breakLoop:
	
	mov ah,9h
	mov dx, offset endl
	int 21h
	
	; очистка регистров
	
	mov si,0
	mov di,0
	xor ax,ax
	xor dx,dx
	xor cx,cx
	xor bx,bx
	mov NumOfPac, 0
	
	; получение количества мужчин по заданному году рождения
	
	lea di, pac1
	mov cx,3

	MainLoop4:
	push cx
	mov cx, 8
	lea si, compBirthYear
	push si
	lea si, [di].birthYear
		
	lodsw
	mov dx, ax
	mov bp, si
	pop si
	lodsw
	push si
	mov si, bp
	cmp dx, ax
	jne next_pac4
	
	; если год совпал, идет проверка на пол
	
	xor ax,ax
	push di
	lea si, [di].gender
	mov bh, 'M'
	lodsb
	pop di
	cmp bh, al
	jne next_pac4
	
	; если пол совпал
	
	inc NumOfPac
	
	next_pac4:
	add di, type pacient
	pop si
	pop cx
	xor bl,bl
	loop MainLoop4
	
	; вывод количества пациентов мужчин
	
	mov ah,9h
	mov dx, offset message4
	int 21h
	
	mov bh, NumOfPac
	mov ah, 2h
	add bh, 30h
	mov dl, bh
	int 21h
	
mov ah,4ch
int 21h

code ends
end begin

