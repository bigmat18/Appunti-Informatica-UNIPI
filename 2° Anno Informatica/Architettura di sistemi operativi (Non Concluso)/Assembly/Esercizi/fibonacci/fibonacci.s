.text
.global fibonacci
.type fibonacci, %function

fibonacci: cmp r0, #0
           moveq pc, lr
           cmp r0, #1
           moveq pc, lr
           sub r0, r0, #1
           push {r0, lr}
           bl fibonacci
           pop {r1}
           push {r0}
           sub r0, r1, #1
           bl fibonacci
           pop {r1}
           add r0, r0, r1
           pop {lr}
           mov pc, lr