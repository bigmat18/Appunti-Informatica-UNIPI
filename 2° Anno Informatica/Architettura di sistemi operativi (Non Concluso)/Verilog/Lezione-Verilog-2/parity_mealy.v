module Parity(output out, input in, input clock);
    reg stato;
    reg stato_new;

    initial
        stato = 0;

    always @(posedge clock)
        stato <= stato_new;

    always @(in, stato)
        stato_new <= (~in & stato) | (in & ~stato);

    assign
        out = (~in & ~stato) | (in & stato);
endmodule