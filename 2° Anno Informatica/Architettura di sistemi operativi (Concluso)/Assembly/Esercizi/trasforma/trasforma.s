.text 
.global trasforma
.type trasforma, %function


trasforma:      ldrb r5, [r0]
                cmp r5, #0
                beq end
                push {r0, r1, r2, lr}
                mov r0, r5
                bl cambia
                mov r5, r0
                pop {r0, r1, r2, lr}
                strb r5, [r0]
                add r0, r0, #1
                b trasforma
end:            mov pc, lr