        .data
     x: .word 1,2,3,4,5,6,7,8 @ primo vettore di 8 elementi
     y: .word 8,7,6,5,4,3,2,1 @ secondo vettore di 8 elementi
     n: .word 8 @ lunghezza dei due vettori
  mess: .string "Il risultato vale %d\n"

        .text
        .global main
        .type main, %function

  main: ldr r0, =x @ r0 indirizzo del primo vettore
        ldr r1, =y @ r1 indirizzo del secondo vettore
        ldr r2, =n @ r3 indirizzo costante n in memoria
        ldr r2, [r2] @ r2 numero degli elementi nei vettori
        push {lr}
        bl IP
        mov r1, r0 @ stampo il risultato: primo param => stringa, quindi r0 -> r1
        ldr r0, =mess
        bl printf
        mov r0, #0
        pop {lr}
        mov pc, lr
