.text
        .global myatoi
        .type myatoi, %function

myatoi: mov r2, #0 @result = 0
        mov r3, #1
        mov r4, #10
        ldrb r1, [r0]
        
loop:   cmp r1, #0
        beq end
        cmp r1, #0x30
        blo error
        cmp r1, #0x39
        bhi error
        sub r1, r1, #48
        mul r0, r0, r3
        add r2, r2, r0
        mul r3, r3, r4
        add r1, r1, #1
        b loop

end:    mov r0, r2
        mov pc, lr

error:  mov r0, r6
        mov pc, lr