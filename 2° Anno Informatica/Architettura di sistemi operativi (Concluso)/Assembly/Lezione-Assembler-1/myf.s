     .text
     .global fun @ r0 <- valore a
                 @ r1 <- valore b
                 @ r0 <- risultato (a+b)/2
     .type fun, %function

fun: add r0, r0, r1
     asr r0, r0, #1
     mov pc, lr
