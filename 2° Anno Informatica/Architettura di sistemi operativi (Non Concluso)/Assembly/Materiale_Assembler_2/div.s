        .text
        .global mydiv @ r0 <- dividendo
                      @ r1 <- divisore
                      @ r0 <- risultato finale
        .type mydiv, %function

 mydiv: mov r2, #0 @ r2 contiene ris
 start: cmp r0, r1 @ r0 - r1
        blo fine @ salto a fine se r0 < r1
        add r2, r2, #1 @ ris = ris + 1
        sub r0, r0, r1
        b start
  fine: mov r0, r2 @ muovo ris in r0
        mov pc, lr @ ritorno al chiamante
