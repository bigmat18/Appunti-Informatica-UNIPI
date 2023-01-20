        .data
 array: .word 0,1,2,3,4,5,6,7,8,9 @ vettore di 10 interi a 32 bit
  mess: .string "Il risultato e' %d\n" @ stringa che verrà passata alla printf

        .text
        .global main
        .type main, %function

  main: ldr r0, =array @ carico in r0 indirizzo iniziale array
        ldr r2, [r0] @ inizializzo r2 (result) a A[0]
        mov r1, #1 @ indice del for (parte da 1 perché il primo elemento e già stato letto)
  loop: cmp r1, #10
        beq fine
        ldr r12, [r0, #4]!
        add r2, r2, r12 @ aggiorno result
        add r1, r1, #1 @ incremento indice for
        b loop
  fine: ldr r0, =mess @ carico in r0 indirizzo iniziale stringa messaggio
        mov r1, r2 @ sposto in r1 il valore somma da stampare con la stringa
        bl printf @ invoco la printf
        mov r7, #1 @ termino con una exit(1), perché?
        svc 0
