; 4*x + ((-z)*(-z)) mod 2y
data segment
	x db 5
	y db 2
	z db 10
	two_num db 00010001B
	four_x db ?
	square_z db ?
	result db ?
data ends
	code segment
		assume ds:data, cs:code
		begin:
		
		mov ax, data
		mov ds, ax
		
		mov al, x
		mov ah, 4
		mul ah
		mov four_x, al ;рез в al
		
		mov al, z
		neg al
		mov ah, al
		imul ah
		mov square_z, al ;рез в al
		
		mov al, y
		mov ah, 2
		mul ah
		mov bh, al
		
;		mov bl, square_z
		mov al, square_z
		div bh
;		mov res_mod, ah
		
		add ah, four_x
		mov result, ah 
		
		mov al, two_num
		not al
		or al, 10000101B
		and al, 11100111B
		
		mov ah, 4ch
		int 21h
		
	code ends
	end begin