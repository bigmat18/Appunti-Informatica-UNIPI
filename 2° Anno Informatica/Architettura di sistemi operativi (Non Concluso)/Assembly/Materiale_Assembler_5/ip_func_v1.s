      .text
      .global IP @ r0 <- indirizzo base di x
                 @ r1 <- indirizzo base di y
                 @ r2 <- dimensione n di x e y
                 @ r0 <- valore di ritorno
      .type IP, %function

  IP: push {r4, r5}
      mov r3, #0 @ accumulatore
loop: cmp r2, #0
      beq fine
      ldr r4, [r0], #4 @ carica x[i]
      ldr r5, [r1], #4 @ carica y[i]
      mul r4, r4, r5
      add r3, r3, r4
      sub r2, r2, #1
      b loop
fine: pop {r4, r5}
      mov r0, r3
      mov pc, lr
