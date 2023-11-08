.text
.global reduce
.type reduce, %function

reduce: mov r2, #0 @counter
        mov r3, #0 @index
loop:   cmp r3, r1
        beq end
        ldr r12, [r0, r3, lsl #2]
        add r2, r2, r12
        add r3, r3, #1
        b loop
end:    mov r0, r2
        mov pc, lr