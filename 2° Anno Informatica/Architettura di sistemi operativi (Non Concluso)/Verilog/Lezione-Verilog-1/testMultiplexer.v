module testMultiplexer();
    reg a, b, c;
    wire out;

    multiplexer #(1) mux(out, a, b, c);

    initial
        begin
            $dumpfile("testMultiplexer.vcd");
            $dumpvars;

            a = 0;
            b = 1;
            c = 0; // out diventa 0

            #4 a = 0;
               b = 1;
               c = 1; // out diventa 1

            #4 a = 0;
               b = 0;
               c = 1; // out diventa 0

            #4 a = 1;
               b = 0;
               c = 0; // out diventa 1

            #4 $finish;
        end
endmodule