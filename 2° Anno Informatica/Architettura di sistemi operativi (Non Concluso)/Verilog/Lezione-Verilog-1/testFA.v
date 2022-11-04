module testFA();
    reg rin, a, b;
    wire rout, som;

    fulladder adder(rout, som, rin, a, b);

    initial
        begin
            $dumpfile("testFA.vcd");
            $dumpvars;

            a = 0;
            b = 0;
            rin = 1; // som = 1 e rout = 0

            #4 a = 1;
               b = 0;
               rin = 1; // som = 0 e rout = 1

            #4 a = 1;
               b = 1;
               rin = 1; // som = 1 e rout = 1

            #4 a = 1;
               b = 1;
               rin = 0; // som = 0 e rout = 1

            #4 $finish;
         end
    endmodule