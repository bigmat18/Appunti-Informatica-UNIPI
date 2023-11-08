module testContatore();
    reg clock;
    reg in;
    wire [1:0]out;

    Contatore #(2) contatore(out, in, clock);

    always
        begin
            #2 clock = 1;
            #2 clock = 0;
        end

    initial
        begin
            $dumpfile("testContatore.vcd");
            $dumpvars;

            clock = 0; // valore iniziale del clock
            in = 0; // valore iniziale di in

            #6 in = 0;

            #4 in = 1;

            #4 in = 0;

            #4 in = 1;

            #4 in = 1;

            #4 in = 0;

            #4 in = 1;

            #4 in = 0;

            #4 in = 1;

            #8 $finish;
        end
endmodule