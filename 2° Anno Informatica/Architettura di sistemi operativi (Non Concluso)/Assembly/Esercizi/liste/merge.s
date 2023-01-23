.text 
    .global merge
    .type merge, %function


merge:  ldr r2, [r0, #4] @ r2 = *next
loop:   cmp r2, #0
        beq end
        ldr r2, [r2, #4]
        b loop
end:    mov r2, r1
        mov pc, lr

/*
merge:  mov r3, r0
        add r0, r0, #4

loop:   ldr r2, [r0]
        cmp r2, #0
        beq end
        add r2, r2, #4
        mov r0, r2
        
        b loop

end:    str r1, [r0]
        mov r0, r3
        mov pc, lr
 */