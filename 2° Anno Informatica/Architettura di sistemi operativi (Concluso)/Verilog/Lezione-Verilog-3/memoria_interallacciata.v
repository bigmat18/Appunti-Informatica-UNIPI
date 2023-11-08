// Memoria modulare interallacciata con una porta in lettura/scrittura
module memInterleaved(output [M-1:0]RA,
                      input [M-1:0]WD,
                      input WE,
                      input clock,
                      input [K-1:0]A);

    parameter M=8; // larghezza di una cella di memoria
    parameter K=11; // numero di bit dell'indirizzo (capacità 2^K*M bit)

    // uscite del valore letto dei due moduli
    wire [M-1:0]readValue1;
    wire [M-1:0]readValue2;

    // due WE distinti per i due modili
    wire WE1, WE2;

    // al primo modulo scrivo solo se il bit più significativo è 0
    assign
        WE1 = WE & ~A[0];

    // al secondo modulo scrivo solo se il bit più significativo è 1
    assign
        WE2 = WE & A[0];

    // istanzio due moduli di memoria, ciascuno metà della capacità
    memoryV1 #(M,K-1) modulo1(readValue1, WD, WE1, clock, A[K-1:1]);
    memoryV1 #(M,K-1) modulo2(readValue2, WD, WE2, clock, A[K-1:1]);

    // multiplexer per scegliere se leggo dal primo o dal secondo modulo
    assign
        RA = (A[0] == 1'b0 ? readValue1 : readValue2);
endmodule