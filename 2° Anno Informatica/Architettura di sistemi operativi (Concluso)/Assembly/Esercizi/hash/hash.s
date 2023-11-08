.text 
.global hash
.type hash, %function

hash: mov r1, #0
loop: and r2, r0, #0xF0
      
      lsr r2, r2, #4
      add r1, r1, r2

      lsr r0, r0, #8
      cmp r0, #0
      bne loop

mod:  cmp r1, #16
      blt end

      sub r1, r1, #16
      b mod
    
end:  mov r0, r1
      mov pc, lr
