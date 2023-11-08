.data
    msg:     .string "%d\n"
    array:   .word 0,1,2,3,4

.text  
    .global main
    .global print_all
    .type main, %function
    .type print_all, %function


main: push {lr}
      ldr r0, =array
      mov r1, #5
      bl print_all
      pop {lr}
      mov r0, #0
      mov pc, lr

print_all: mov r2, #0
loop:      cmp r2, r1
           beq end
           push {r1}
           ldr r1, =msg
           bl printf
           pop {r1}
           add r2, r2, #1
           b loop

end:       mov pc, lr