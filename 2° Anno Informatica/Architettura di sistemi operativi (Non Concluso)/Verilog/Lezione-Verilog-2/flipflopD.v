module FlipFlopD(output q, output notq, input clock, input d);
    wire n1;
    wire dummy;
    wire notclock;

    assign
        notclock = ~clock;

    LatchD master(n1, dummy, notclock, d);
    LatchD slave(q, notq, clock, n1);
endmodule