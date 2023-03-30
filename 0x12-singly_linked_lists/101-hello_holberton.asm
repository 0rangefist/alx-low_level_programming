section .data
    hello db "Hello, Holberton", 10,0
    format db "%s", 0

section .text
    global main

    extern printf

main:
    push rbp
    mov rbp, rsp

    mov rdi, format
    mov rsi, hello
    xor eax, eax
    call printf

    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret
