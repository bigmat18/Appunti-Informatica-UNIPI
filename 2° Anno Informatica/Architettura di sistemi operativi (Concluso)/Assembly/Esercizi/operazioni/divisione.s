    .text
    .global divisione 
    .type divisione, %function

divisione: mov r2, #0
start: cmp r0, r1
       blo fine
       sub r0, r0, r1
       add r2, r2, #1
       b start
fine:  mov r0, r2
       mov pc, lr