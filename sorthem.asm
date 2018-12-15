%include "asm_io.inc"
SECTION .data

error1: db "Error! Incorrect number of arguments!",10,0
error2: db "Error! Argument must be integer between 2 and 9.",10,0
initial: db "  initial configuration",10,0
final: db "final configuration",10,0
base: db "XXXXXXXXXXXXXXXXXXXXXXX",10,0 
peg: dd 0,0,0,0,0,0,0,0,0

SECTION .bss
disks: resd 1
spaces: resd 1
offset: resd 1
temp: resd 1

SECTION .text

global asm_main

sorthem:
	enter 0,0
	pusha
	mov edx, [ebp+8]  ; edx holds number of disks
	mov ecx, [ebp+12] ; ecx holds peg address 
	cmp edx, dword 1
	je BaseCase       ; base case when disks = 1
	;; start recursive call
	add ecx, 4
	push ecx
	dec edx
	push edx
	call sorthem
	add esp, 8
	;; end of recursive call
	jmp Next

	BaseCase:
		popa
		leave
		ret

	Next:
		;inc edx
		sub ecx, 4
		;;;;;;;;;;;;;;;
		mov ebx, edx ; comparison counter = number of disks 
			
	Sort:
		cmp ebx, 0
		je End5
		mov eax, [ecx]  ; move current disk into eax
		cmp eax, dword [ecx+4] ; compare with next disk
		dec ebx
		jae Sort
		mov [temp], eax   ; temp holds current
		mov eax, [ecx+4]  ; eax holds next
		mov [ecx], eax
		mov eax, [temp]
		mov [ecx+4], eax  ; now next = current disk
		add ecx, 4 
		jmp Sort
	
	End5:
		push peg
		push dword [disks]
		call showp
		add esp, 8
		popa
		leave
		ret


showp:
	enter 0,0
	pusha
	mov edi, [ebp+12] ; edi holds address of peg array 
	mov eax, [ebp+8]  ; ecx holds number of disks
	mov ecx, eax      ; counter for loop = number of disks
	dec eax
	mov bl, 4
	mul bl
	mov [offset], eax ; offset is set
	add edi, [offset] ; edi points to last disk of peg array

	LOOP:
	mov edx, 11
	sub edx, [edi]
	mov [spaces], edx
	call display_line
	sub edi, 4
	loop LOOP
	
	end:
		mov eax, base
		call print_string
		call read_char
		popa
		leave
		ret

;;subprogram to print out each disk on the peg
display_line:
	enter 0,0
	pusha 

	mov ebx, dword [spaces] ; ebx = number of spaces
	mov ecx, 0
	LeftSpaces:
		cmp ecx, ebx
		jae Next1
		mov eax, ' '
		call print_char
		inc ecx
		jmp LeftSpaces
	Next1:
		mov ebx, dword [edi] ; counter for number size of peg
		mov ecx, 0

	LeftDisk:
		cmp ecx, ebx
		jae Next2
		mov eax, 'o'
		call print_char
		inc ecx
		jmp LeftDisk
	Next2:
		mov eax, '|'
		call print_char     ; prints the pin in the middle
		mov ebx, dword [edi] 
		mov ecx, 0

	RightDisk:
		cmp ecx, ebx
		jae Next3
		mov eax, 'o'
		call print_char
		inc ecx
		jmp RightDisk

	Next3:
		mov ebx, dword [spaces]
		mov ecx, 0

	RightSpaces:
		cmp ecx, ebx
		jae end1
		mov eax, ' '
		call print_char
		inc ecx
		jmp RightSpaces
		

	end1:
		call print_nl
		popa
		leave
		ret

asm_main:
	enter 0,0	
	pusha
	
	mov eax, dword [ebp+8] ; argc
	cmp eax, dword 2 ; argc should be 2
	jne ERR1
	; correct number of arguments, now check for correct argument
	mov ebx, dword [ebp+12] ; address of argv[]
	mov eax, dword [ebx+4] ; arbv[1]
	; check if integer is below 2 or above 9
	mov bl, byte [eax] ; first  byte of argv[1]
	cmp bl, '2'  ; first check if below 2
	jb ERR2
	; so first byte must be greater than 2
	cmp bl, '9' ; check if argument greater than 9
	jg ERR2
	; now must check if second byte is terminating char
	sub bl, '0'
	mov [disks], bl
	; check second byte
	mov bl, byte [eax+1] ; 2nd byte of argv[1]
	cmp bl, byte 0
	jne ERR2
	; now argument is correct, numeric value stored in ecx
	jmp arg_ok

arg_ok: 
	mov eax, peg
	call print_int
	call print_nl
	mov ecx, peg
	push dword [disks] ; push number of disks onto stack
	push ecx
	call rconf         ; peg is now initialised
	add esp, 8 
	mov eax, initial
	call print_string
	call print_nl 
	push peg	   ; push pegs first, then disks
	push dword [disks]
	call showp	   ; call showp to show initial config
	add esp, 8
	push peg	   	
	push dword [disks]	
	call sorthem       ; call sorthem subroutine
	add esp, 8
	mov eax, final     ; print final configuration
	call print_string
	call print_nl 
	push peg
	push dword [disks]
	call showp
	add esp, 8         
	jmp asm_main_end

ERR1:
	mov eax, error1
	call print_string
	jmp asm_main_end

ERR2:
	mov eax, error2
	call print_string
	jmp asm_main_end


asm_main_end:
	popa
	leave
	ret
