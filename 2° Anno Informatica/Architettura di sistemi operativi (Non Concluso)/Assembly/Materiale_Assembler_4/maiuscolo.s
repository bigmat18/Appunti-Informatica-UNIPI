       .text
       .global maius @ r0 <- indirizzo iniziale stringa da convertire
       .type maius, %function

maius: ldrb r1, [r0] @ carica un carattere della stringa in r1
       cmp r1, #0 @ null terminated string => se è 0 vuol dire che la stringa è finita
       beq fine
       cmp r1, #0x61 @ se è < 'a' passa al prossimo carattere
       blo next
       cmp r1, #0x7a @ se è > 'z' passa al prossimo carattere
       bhi next
       sub r1, r1, #0x20 @ altrimenti togli 'a'-'A' (le maiuscole hanno codici più bassi)
       strb r1, [r0] @ e rimetti il nuovo codice al suo posto in memoria
 next: add r0, r0, #1 @ per il prossimo carattere l'indirizzo aumenta di 1 (byte)
       b maius
 fine: mov pc, lr
