module Registro(output [N-1:0]out, input [N-1:0]in, input we, input clock);
    parameter N = 8;
    reg [N-1:0]state;

    initial
        state = 0;

    always @(posedge clock)
        begin
            if(we)
                state <= in;
        end

    assign
        out = state;
endmodule