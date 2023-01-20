.text
.global cambia
.type cambia, %function

cambia:         mov r4, #0
loop:           cmp r4, r3
                beq end
                ldrb r5, [r1]
                cmp r5, r0
                beq found
                add r1, r1, #1
                add r2, r2, #1
                add r4, r4, #1
                b loop

found:          ldrb r6, [r2]
                mov r0, r6
end:            mov pc, lr