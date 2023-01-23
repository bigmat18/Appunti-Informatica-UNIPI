        .text
        .global main
        .type main, %function

  main: mov r2, #0 @ r2 contiene ris
        mov r0, #7 @ il dividendo è fissato a 7
        mov r1, #3 @ il divisore è fissato a 3
 start: cmp r0, r1 @ r0 - r1
        blo fine @ salto a fine se r0 < r1
        add r2, r2, #1 @ ris = ris + 1
        sub r0, r0, r1
        b start
  fine: mov r0, r2 @ muovo ris in r0
        mov pc, lr @ ritorno al chiamante

@ Il risultato qui è presente in r0 ma non viene
@ stampato prima di ritornare e terminare. Con il
@ debugger si può vedere quanto vale r0 alla fine
@ e vedremo comunque come chiamare la printf tramite
@ codice ARMv7.
