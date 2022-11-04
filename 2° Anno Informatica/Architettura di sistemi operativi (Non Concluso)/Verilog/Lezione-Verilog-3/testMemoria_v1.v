module testMem_v1();
    parameter M = 8; // parole di 8 bit
    parameter K = 4; // indirizzi di 4 bit (16 parole complessive)

    reg [M-1:0]Min;
    reg we, clk;
    reg [K-1:0]addr;
    wire [M-1:0]Mout;

    memoryV1 #(M,K) MEM(Mout, Min, we, clk, addr);

    always
        begin
            #2 clk = ~clk;
        end

    initial
        begin
            $dumpfile("testMem_v1.vcd");
            $dumpvars;

            clk = 0;
            we = 0;

            #1 we = 1;
               addr = 7;
               Min = 127;

            #2 we = 0;

            #2 we = 1;
               addr = 8;
               Min = 255;

            #4 we = 0;
               addr = 7;

            #2 addr = 8;

            #2 addr = 0;

            #10 $finish;
     end
endmodule