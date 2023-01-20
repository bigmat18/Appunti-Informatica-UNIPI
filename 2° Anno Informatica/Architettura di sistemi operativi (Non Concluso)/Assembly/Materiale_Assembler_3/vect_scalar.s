             .text
             .global vect_scalar @ r0 <- indirizzo base array
                                 @ r1 <- valore x
                                 @ r2 <- dimensione array
             .type vect_scalar, %function

vect_scalar: mov r3, #0 @ r3 indice loop
       loop: cmp r3, r2
             beq fine
             ldr r12, [r0, r3, lsl #2]
             mul r12, r12, r1
             str r12, [r0, r3, lsl #2]
             add r3, r3, #1
             b loop
       fine: mov pc, lr
