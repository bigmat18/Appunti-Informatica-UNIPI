// Memoria con una porta in lettura/scrittura, e una porta in lettura
module memoryV2(output [M-1:0]RA1,
                output [M-1:0]RA2,
                input [M-1:0]WD1,
                input WE1,
                input clock,
                input [K-1:0]A1,
                input [K-1:0]A2);

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
            if (WE1)
                mem[A1] <= WD1;
        end

    assign
        RA1 = mem[A1];

    assign
        RA2 = mem[A2];
endmodule