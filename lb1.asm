data segment

	twsev db 27
	ten db 10
	two_ss db 00001101B
	sum db 1 DUP(0)
	razn db 1 DUP(0)
	proizv dw 1 DUP(1)
	proizv2 dw 1 DUP(1)
	div_1 db 1 DUP(?)
	mod_1 db 1 DUP(?)

data ends
code segment
	assume ds:data, cs:code 
		begin:

		mov ax, data
		mov ds, ax

		;(27+10)
		mov ah, twsev
		add ah, ten
		mov sum, ah

		;(10-27)
		mov ah, ten
		sub ah, twsev
		mov razn, ah

		;(10 - (-27))
		mov ah, ten
		mov al, twsev
		neg al
		sub ah, al

		;(10*(-27)) uchet znaka

		mov al, twsev
		mov bh, ten
		neg al
		imul bh
		mov proizv, ax

		;(10*(-27)) bez ucheta znaka

		mov al, twsev
		mov bh, ten
		neg al
		mul bh

;(27/10)
		mov ax, 27
		mov bh, 10
		div bh
		mov cl, al
		mov ch, ah
		mov div_1, cl
		mov mod_1, ch
		
		mov al, two_ss
		or al, 11000000B 
		not al
		and al, 00000101B
		
		mov bl, al
		xor bl, al
		

mov ah, 4ch
int 21h
ret

code ends    
end begin  

;OutInt proc
;    aam 
;    add ax,3030h 
;    mov dl,ah 
;    mov dh,al 
;    mov ah,02 
;    int 21h 
;    mov dl,dh 
;    int 21h
;OutInt endp