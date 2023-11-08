module multiplexer (
    input in1, input in2, input s, output out
);

    assign
        out = (s) ? in1 : in2;
endmodule


module testMuliplexer ();
    reg in1, in2, s;
    wire out;

    multiplexer mux(in1, in2, s, out);

    initial begin
        $dumpfile("multiplexer.vcd");
        $dumpvars;
        in1 = 0;
        in2 = 0;
        s = 0;

        #4  in1 = 0;
            in2 = 0;
            s = 0;

        #4  in1 = 1;
            in2 = 0;
            s = 0;

        #4  in1 = 1;
            in2 = 0;
            s = 1;

        #4  in1 = 0;
            in2 = 1;
            s = 0;
        #4 $finish;
    end
    
endmodule