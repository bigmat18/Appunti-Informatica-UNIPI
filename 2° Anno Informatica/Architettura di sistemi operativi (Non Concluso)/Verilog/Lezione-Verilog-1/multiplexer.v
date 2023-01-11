module multiplexer(output [[N-1:0]]z, input [N-1:0]x, input [N-1:0]y, input alpha);
    parameter N = 32;

    assign
        z = (alpha) ? y : x;
endmodule