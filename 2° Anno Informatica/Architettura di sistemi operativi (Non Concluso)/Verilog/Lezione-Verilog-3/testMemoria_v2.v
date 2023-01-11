module testMem_v2();
    parameter M = 8; // parole di 8 bit
    parameter K = 4; // indirizzi di 4 bit (16 parole complessive)

    reg [M-1:0]Min;
    reg we, clk;
    reg [K-1:0] addr1, addr2;
    wire [M-1:0] Mout1, Mout2;

    memoryV2 #(M,K) MEM(Mout1, Mout2, Min, we, clk, addr1, addr2);

    always
        begin
            #1 clk = ~clk;
        end

    initial
        begin
            $dumpfile("testMem_v2.vcd");
            $dumpvars;

            clk = 0;
            we = 0;
            addr1 = 0;
            addr2 = 0;

            #1 we = 1;
               addr1 = 7;
               Min = 127;

            #2 we = 0;

            #2 we = 1;
               addr1 = 8;
               Min = 255;

            #2 we = 0;
               addr1 = 7;

            #2 addr2 = 8;

            #2 addr2 = 0;

            #10 $finish;
        end
endmodule