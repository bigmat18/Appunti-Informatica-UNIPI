@; input:  r0: array interi (indirizzo primo elemento)
@;         r1:  numero di elementi (>0)
@; output: nessuno richiesto (l'array viene ordinato in place)
@;         ma lasciamo in r0 l'indirizzo del primo elemento 

@; I commenti fanno riferimento al codice in C
@; delle funzioni quicksort() e partition() in quicksort.c 


        .data

        .text
        .global qs_arm @; 
                         

qs_arm: cmp r1,#1
	moveq pc, lr	@; if(r1==1) return;
	movlt r0, #11
	blt exit	@; if(r1<1) exit(11)
	@; r1 > 1 procediamo con il partizionamento
	push {r4,r5,lr}
	mov r2,#-1	@; i=-1
	mov r3,r1	@; j=n
	ldr r12,[r0]	@; pivot = a[0]
loop:	sub r3,r3,#1	@; --j
	ldr r4, [r0,r3,lsl #2] 	@; leggo r3*4 byte dopo l'indirizzo in r0
	cmp r4,r12	@; confronta con il pivot
	bgt loop	@; se r4>pivot decrementa j
loop2:	add r2,r2,#1	@; i++
	ldr r5, [r0,r2,lsl #2]	
	cmp r5,r12	@; confronta con il pivot 
	blt loop2
	@; entrambi gli indici si sono fermati
	@; deve eseguire lo swap o uscire? 
	cmp r2,r3
	@; caso i<j eseguo swap e riparto 
	strlt r4, [r0,r2,lsl #2]
	strlt r5, [r0,r3,lsl #2]
	blt loop
	@; fine partizionamento ora le chiamate ricorsive
	@; salvo il numero di elementi della prima metà e n
	@; in r4 e r5 che sono preservati dalle chiamate di funzione
	add r4,r3,#1 	@; numero elementi prima metà
	mov r5,r1	@; numero elementi in totale
	@; effettua chiamata qsort(a,q)
	mov r1,r4
	bl qs_arm		@; prima chiamata ricorsiva
	@; effettua chiamata qsort(a+q,n-q)
	add r0,r0,r4,lsl #2	@; r0 = r0 + 4*r4 = &r0[r4]
	sub r1, r5, r4		@; r1 = r5-r4 = n-1
	bl qs_arm		@; seconda chiamata ricorsiva
	sub r0,r0,r4,lsl #2	@; ripristina r0
	pop {r4,r5,lr}		@; ripristino registri 
	mov pc,lr		@; return 
	mov r0,#10		@; exit(10) ma non viene mai eseguito
	b exit
