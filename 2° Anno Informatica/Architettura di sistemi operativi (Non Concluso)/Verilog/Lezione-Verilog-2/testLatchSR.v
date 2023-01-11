module testLatchSR();
    reg s, r;
    wire q, notq;

    LatchSR srlatch(q, notq, s, r);

    initial
        begin
            $dumpfile("testLatchSR.vcd");
            $dumpvars;

            s = 0;
            r = 0;

            #2 s = 1;
               r = 0; // q diventa 1 e notq 0

            #2 s = 0;
               r = 0; // q matiene il valore 1 e notq 0

            #2 s = 0;
               r = 1; // q diventa 0 e notq 1

            #2 s = 0;
               r = 0; // q matiene il valore 0 e notq 1

            #4 $finish;
        end
endmodule