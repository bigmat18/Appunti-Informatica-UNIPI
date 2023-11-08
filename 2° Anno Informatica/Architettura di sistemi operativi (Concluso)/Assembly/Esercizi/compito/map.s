     .text
     .global map
     .type map, %function

     .global divisione 
     .type divisione, %function


map:           mov r3, #0 @ i = 0
               mov r4, #0 @ counter = 0
               mov r6, #1
               mvn r6, r6
loop:          cmp r3, r1
               beq end
               ldrb r2, [r0, r3, lsl #2]
               push {r0, r1, r3, r4, lr}
               mov r0, r2
               bl myatoi
               cmp r0, r6
               beq salta
               mov r1, #4
               bl divisione
               mov r2, r0
               pop {r0, r1, r3, r4, lr}
               add r4, r4, r2
               add r3, r3, #1
               b loop

salta:         mov r2, r0
               pop {r0, r1, r3, r4, lr}
               add r3, r3, #1
               b loop

end:           mov r0, r4
               mov pc, lr


divisione:     mov r2, #0
start:         cmp r0, r1
               blo fine
               sub r0, r0, r1
               add r2, r2, #1
               b start
fine:          mov r0, r2
               mov pc, lr
