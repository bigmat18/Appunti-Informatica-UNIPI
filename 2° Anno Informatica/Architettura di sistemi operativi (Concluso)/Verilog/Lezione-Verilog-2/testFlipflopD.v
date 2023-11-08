module testFlipflopD();
    reg clock, d;
    wire q, notq;

    FlipFlopD flipflop(q, notq, clock, d);

    always
        begin
            #2 clock = 1;
            #2 clock = 0;
        end

    initial
        begin
            $dumpfile("testFlipflopD.vcd");
            $dumpvars;

            clock = 0; // valore iniziale del clock

            d = 1;

            #1 d = 1;

            #6 d = 0;

            #4 d = 1;

            #4 d = 0;

            #4 d = 1;

            #8 $finish;
        end
endmodule