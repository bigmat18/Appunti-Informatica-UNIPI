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
	sub r2,r0,#4		@;  = &a[-1]
	add r3,r0,r1,lsl #2	@;  = &a[n]
	ldr r12,[r0]		@; pivot = a[0]
loop:	ldr r4, [r3,#-4]! 	@; r4 = *(--r3) leggo intero prima della pos r3
	cmp r4,r12		@; confronta con il pivot
	bgt loop		@; se r4>pivot considera intero precedente
loop2:	ldr r5, [r2,#4]!	@; r5 = *(++i) intero dopo posizione r2
	cmp r5,r12		@; confronta con il pivot 
	blt loop2		@; se r5<pivot considera intero successivo
	
	@; entrambi gli indici si sono fermati
	@; deve eseguire lo swap o uscire? 
	cmp r2,r3
	@; caso i<j eseguo swap e riparto 
	strlt r4, [r2]
	strlt r5, [r3]
	blt loop
	
	@; fine partizionamento ora le chiamate ricorsive
	@; salvo il numero di elementi della prima metà e n
	@; in r4 e r5 che sono preservati dalle chiamate di funzione
	sub r4,r3,r0		@; r3-r0 = numero di byte nella prima partizione
	mov r4,r4,lsr #2	@; divido per 4 = numero di interi
	add r4,r4,#1 		@; numero elementi prima metà
	mov r5,r1		@; salvo numero elementi in totale
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
