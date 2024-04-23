@; input:  r0 intero unsigned >1
@; output: r0=0 se composto, l'input se è primo 

        .data
errmsg: .string "Input non valido (primo)"        

        .text
        .global primo  @; r0 contiene n,
                       @; r0 conterrà il risultato 0/1

primo:  cmp r0, #2     @; calcola r0-2
        blt stop       @; r0<2 errore  
        bne not2
        mov pc, lr     @; return 2
not2:   and r1, r0, #1 @; r1 = r0 && 1 = r0%2
        cmp r1, #0     @; r0 e' pari?
        bne odd
nonpr:  mov r0, #0     
end:    mov pc,lr      @; return 0
odd:    mov r1, #3     @; for(r1=3;r1*r1 <= r0; r1 +=2)
loop:   mul r3,r1,r1
        cmp r3,r0      @; se r1*r1 > r0
        bhi end        @; return r0
        @; calcolo resto r3 = r0% r1 per sottrazioni successive (inefficiente)
        mov r3, r0
resto1: cmp r3,r1
        blo resto2     @; is r3<r1 r3 è il resto
        sub r3,r3,r1
        b resto1
resto2: cmp r3,#0      @; non primo 
        beq nonpr
        add r1,r1,#2
        b loop
        
@; stampa messaggio errore         
stop:   ldr r0,=errmsg
        bl perror       @; perror(errormsg)
        mov r0,#33      @; non ho salvato lr perché la exit non ritorna 
        b exit          @; exit(33)
         
