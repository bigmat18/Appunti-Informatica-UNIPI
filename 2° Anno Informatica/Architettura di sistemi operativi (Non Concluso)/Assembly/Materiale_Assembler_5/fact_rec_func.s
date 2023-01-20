      .text
      .global fact @ r0 <- valore n
                   @ r0 <- valore di ritorno
      .type fact, %function

 fact: cmp r0, #0 @ caso base: fact(0) = 1
       bne else
       mov r0, #1
       mov pc, lr
 else: push {r0, lr}
       sub r0, r0, #1 @ calcolo n-1
       bl fact @ dopo questa, r0 contiene Fact(n-1)
       pop {r1, lr} @ r1 qui contiene n
       mul r0, r0, r1
       mov pc, lr
