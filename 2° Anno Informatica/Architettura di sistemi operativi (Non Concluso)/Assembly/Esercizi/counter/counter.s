.text 
.global counter
.type counter, %function

counter: mov r3, #0 @counter number equals to r2
         mov r4, #0 @counter i = 0
loop:    cmp r4, r1
         beq end
         ldr r12, [r0, r4, lsl #2]
         cmp r12, r2
         addeq r3, r3, #1
         add r4, r4, #1
         b loop
end:     mov r0, r3
         mov pc, lr