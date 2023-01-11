module Contatore(output [N-1: 0]out, input in, input clock);
    parameter N = 2;

    reg [N-1:0]s;
    reg [N-1:0]s_new;

    initial
        begin
            s = 0; // stato iniziale
        end

        always @(posedge clock)
            s <= s_new;

        always @(s, in)
            s_new <= s + in; // attenzione qui si considerano s
                             // e in come interi e si fa la somma +

        assign
            out = s;
endmodule