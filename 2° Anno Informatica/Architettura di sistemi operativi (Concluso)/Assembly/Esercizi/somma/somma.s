.text
    .global somma
    .global pow
    .type somma, %function
    .type pow, %function


somma: push {r4, r5}
       mov r3, #0 @counter
       mov r4, #0 @adder

loop:  ldr r5, [r1]

       push {r0, r1, r2, lr}
       mov r1, r3
       bl pow
       mul r5, r5, r0
       add r4, r4, r5
       pop {r0, r1, r2, lr}

       add r3, r3, #1
       add r1, r1, #4

       cmp r3, r2
       blt loop

       mov r0, r4
       pop {r4, r5}
       mov pc, lr


pow:     mov r2, #1
powloop: cmp r1, #0
         beq end

         mul r2, r2, r0
         sub r1, r1, #1
         b powloop

end: mov r0, r2
     mov pc, lr