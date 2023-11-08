.text
    .global automa
    .type automa, %function


automa: mov r2, #0

stato1: ldrb r1, [r0]
        
        cmp r1, #0
        beq error

        cmp r1, #97
        bne error

stato2: add r2, r2, #1
        add r0, r0, #1

        ldrb r1, [r0]

        cmp r1, #0
        beq error

        cmp r1, #98
        beq stato3

        cmp r1, #97
        bne error

        b stato2


stato3: add r2, r2, #1
        add r0, r0, #1

        ldrb r1, [r0]

        cmp r1, #97
        beq end

        cmp r1, #98
        beq stato3

error:  mov r0, #0
        mov pc, lr

end:   mov r0, r2
       mov pc, lr