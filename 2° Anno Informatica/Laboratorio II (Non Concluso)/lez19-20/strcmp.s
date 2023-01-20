@; input:  
@;	r0, r1: array caratteri 0-terminati
@; output: 
@;	r0: valore < > ==0 a seconda che la stringa r0 sia 
@;	lessicograficamente minore maggiore o uguale a r1
	

	.data

	.text
	.global armcmp    @; nome funzione chimabile dall'esterno 
                         

armcmp:	cmp r0,#0
	moveq r0,#11
	beq exit	@; r0==NULL exit(11)
	cmp r1,#0
	moveq r0,#12
	beq exit	@; r1==NULL exit(12)
	mov r2,#0	@; for(i=0 ....)
fori:	ldrb r3,[r0,r2] @; r3 = r0[r2]
	ldrb r12,[r1,r2]@; r12 = r1[r2]
	cmp r3,r12
	subne r0,r3,r12
	movne pc,lr	@; return r3-12
	cmp r3,#0
	moveq r0,#0
	moveq pc,lr     @; return 0
	add r2,r2,#1	@; r2++
	b fori 
	b exit

