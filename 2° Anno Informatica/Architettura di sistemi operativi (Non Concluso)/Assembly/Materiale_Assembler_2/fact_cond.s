        .text
        .global fact @ r0 <- numero n di cui calcolare fattoriale
                     @ r0 <- risultato (fattoriale)
        .type fact, %function

  fact: mov r1, r0 @ muovo n in r1
        mov r0, #1 @ r0 inizializzato a 1 (ris)
 start: cmp r1, #0
        mulhi r0, r0, r1 @ ris = ris * n
        subhi r1, r1, #1 @ n = n - 1
        bhi start
  fine: mov pc, lr
