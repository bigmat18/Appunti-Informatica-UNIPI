module testLatchD();
    reg clock, d;
    wire q, notq;

    LatchD dlatch(q, notq, clock, d);

    always // questo codice viene fatto in continuazione
        begin
            #2 clock = 1;
            #2 clock = 0;
        end

    initial
        begin
            $dumpfile("testLatchD.vcd");
            $dumpvars;

            clock = 0; // valore iniziale del clock

            d = 0;

            #1 d = 1;

            #4 d = 0;

            #5 d = 1;

            #1 d = 0;

            #1 d = 1;

            #8 $finish;
        end
endmodule