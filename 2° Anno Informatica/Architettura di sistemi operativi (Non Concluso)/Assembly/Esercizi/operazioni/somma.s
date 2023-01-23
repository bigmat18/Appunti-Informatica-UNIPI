    .text
    .global somma 
    .type somma, %function

somma: add r0, r0, r1
       mov pc, lr