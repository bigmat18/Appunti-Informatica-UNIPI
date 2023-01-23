.text
.global fattoriale 
.type fattoriale, %function

fattoriale: mov r2, r0
            sub r0, r0, #1
start:      cmp r0, #1
            ble end
            mul r2, r2, r0
            sub r0, r0, #1
            b start

end:        mov r0, r2
            mov pc, lr
