module LatchD(output q, output notq, input clock, input d);
    wire s, r;

    assign
        r = clock & (~d);

    assign
        s = clock & d;

    LatchSR sr(q, notq, s, r);
endmodule