module LatchSR(output q, output notq, input s, input r);
    wire w1, w2;
    wire nw1, nw2;
    or(w1, r, nw2);
    or(w2, s, nw1);
    not(nw1, w1);
    not(nw2, w2);

    assign
        q = nw1;

    assign
        notq = nw2;
endmodule