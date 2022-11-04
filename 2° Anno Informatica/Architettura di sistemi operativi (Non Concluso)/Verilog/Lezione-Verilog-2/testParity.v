module testParity();
    reg clock;
    reg in;
    wire out;

    Parity parity(out, in, clock);

    always
        begin
            #2 clock = 1;
            #2 clock = 0;
        end

    initial
        begin
            $dumpfile("testParity.vcd");
            $dumpvars;

            clock = 0; // valore iniziale del clock
            in = 0; // valore iniziale di in

            #6 in = 0;

            #4 in = 0;

            #4 in = 1;

            #4 in = 1;

            #4 in = 0;

            #4 in = 1;

            #4 in = 1;

            #4 in = 0;

            #4 in = 1;

            #8 $finish;
        end
endmodule