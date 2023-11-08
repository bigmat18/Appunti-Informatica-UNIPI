        .text
        .global fibo @ r0 contiene n
                     @ r0 conterrà F(n)
        .type fibo, %function

  fibo: cmp r0, #0
        moveq pc, lr @ caso base 1: r0 = fib(0) = 0
        cmp r0, #1
        moveq pc, lr @ case base 2: r0 = fib(1) = 1
        sub r0, r0, #1 @ calcolo n-1
        push {r0, lr} @ salvo (n-1) e lr sullo stack
        bl fibo @ al termine ho in r0 = Fib(n-1)
        pop {r1} @ metto in r1 il valore n-1
        push {r0} @ salvo fib(n-1) sullo stack
        sub r0, r1, #1 @ r0 contiene n-2
        bl fibo @ al termine ho in r0 = Fib(n-2)
        pop {r1} @ metto in r1 il valore Fib(n-1)
        add r0, r0, r1 @ metto in r0 = Fib(n-1) + Fib(n-2)
        pop {lr}
        mov pc, lr
