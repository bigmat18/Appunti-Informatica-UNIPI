        .text
        .global fact @ r0 <- valore n
                     @ r0 <- valore di ritorno
        .type fact, %function

  fact: mov r1, #1 @ r1 contiene acc
        push {lr}
        bl fact1
        pop {lr}
        mov pc, lr

 fact1: cmp r0, #0
        moveq r0, r1 @ case base: ritorno acc
        moveq pc, lr
        mul r1, r1, r0 @ r1 = n*acc
        sub r0, r0, #1 @ r0 = n-1
        b fact1
