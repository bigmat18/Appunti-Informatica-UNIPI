module Parity(output out, input in, input clock);
    reg stato;
    reg stato_new;
    wire in_sync;

    Registro #(1) sync(in_sync, in, 1'b1, clock);

    initial
        stato = 0;

    always @(posedge clock)
        stato <= stato_new;

    always @(in_sync, stato)
        stato_new <= (~in_sync * stato) + (in_sync * ~stato);

    assign
        out = (~in_sync * ~stato) + (in_sync * stato);
endmodule