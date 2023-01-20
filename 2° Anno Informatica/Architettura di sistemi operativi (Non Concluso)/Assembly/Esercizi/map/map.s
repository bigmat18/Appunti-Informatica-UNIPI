.text 
.global map
.type map, %function

map:  mov r3, #0 @index
loop: cmp r3, r1
      beq end
      ldr r12, [r0, r3, lsl #2]
      add r12, r12, r2
      str r12, [r0, r3, lsl #2]
      add r3, r3, #1
      b loop

end: mov pc, lr