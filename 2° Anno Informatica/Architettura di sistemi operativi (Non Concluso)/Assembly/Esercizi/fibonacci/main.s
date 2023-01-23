.data
    msg:     .string "fib(%d) = %d\n"
    errore:  .string "Inserisci almeno 1 argomento da riga di comando \n"

.text
    .global main
    .type main, %function

main: push {lr}
      cmp r0, #2
      bne error
      ldr r0, [r1, #4]
      bl atoi
      push {r0}
      bl fibonacci
      mov r2, r0
      pop {r1}
      ldr r0, =msg
      bl printf
      pop {lr}
      mov r0, #0
      mov pc, lr

error: ldr r0, =errore
       bl printf
       pop {lr}
       mov r0, #1
       mov pc, lr