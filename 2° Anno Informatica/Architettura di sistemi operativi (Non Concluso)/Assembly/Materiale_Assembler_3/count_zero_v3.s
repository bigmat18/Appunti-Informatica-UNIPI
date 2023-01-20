        .text
        .global count @ r0 <- indirizzo base array A
                      @ r1 <- size array A
                      @ r0 <- risultato (numero di elementi nulli)
        .type count, %function

 count: mov r2, #0 @ r2 = ris
        mov r3, #0 @ r3 = i
  loop: cmp r3, r1 @ i == size
        beq fine
        ldr r12, [r0], #4
        cmp r12, #0
        addeq r2, r2, #1 @ count++
        add r3, r3, #1 @ i++
        b loop
  fine: mov r0, r2
        mov pc, lr
