// Memoria con una porta in lettura/scrittura
module memoryV1(output [M-1:0]RA,
                input [M-1:0]WD,
                input WE,
                input clock,
                input [K-1:0]A);

    parameter M=8; // larghezza di una cella di memoria
    parameter K=10; // numero di bit dell'indirizzo (capacità 2^K*M bit)

    reg [M-1:0] mem[0:(2**K)-1]; // memoria da 1KB per default
    integer i;

    initial
        begin
            for (i=0; i<(2**K)-1; i++)
                mem[i] = 0; // inizializzo tutta la memoria a 0
        end

    always @(posedge clock)
        begin
            if (WE)
                mem[A] <= WD;
        end

    assign
        RA = mem[A];
endmodule