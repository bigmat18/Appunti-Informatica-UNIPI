       .data
 mess: .string "Il fattoriale di %d è %d\n"
ermsg: .string "Inserisci un numero da riga di comando\n"

       .text
       .global main @ r0 <- valore di argc
                    @ r1 <- indirizzo inziale di argv
                    @ r0 <- valore di ritorno al preambolo GCC
       .type main, %function

 main: push {lr}
       cmp r0, #2 @ almeno due argomenti da riga di comando
       bne error
       ldr r0, [r1, #4] @ carico in r0 argv[1] che è una stringa
       bl atoi @ dopo questa, r0 contiene il numero di cui calcolare il fattoriale
       push {r0} @ mi salvo il numero di cui calcolare il fattoriale
       bl fact @ dopo questa, r0 contiene il fattoriale
       mov r2, r0
       pop {r1}
       ldr r0, = mess
       bl printf
       pop {lr}
       mov r0, #0
       mov pc, lr

error: ldr r0, =ermsg @ carico indirizzo iniziale stringa di errore
       bl printf
       pop {lr}
       mov pc, lr
