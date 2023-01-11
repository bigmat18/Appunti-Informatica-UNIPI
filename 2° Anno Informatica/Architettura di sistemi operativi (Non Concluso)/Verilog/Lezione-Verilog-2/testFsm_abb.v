module testFSM_abb();
    reg clock;
    reg [1:0]in;
    wire out;

    fsm_abb fsm(out, in, clock);

    always
        begin
            #2 clock = 1;
            #2 clock = 0;
        end

    initial
        begin
            $dumpfile("testFsm_abb.vcd");
            $dumpvars;

            clock = 0; // valore iniziale del clock
            in = 0; // 0 -> 'A'

            #6 in = 1; // 1 -> 'B'

            #4 in = 3; // 3 -> 'C'

            #4 in = 0; // 0 -> 'A'

            #4 in = 1; // 1 -> 'B'

            #4 in = 1; // 1 -> 'B'

            #4 in = 3; // 3 -> 'C'

            #8 $finish;
        end
endmodule