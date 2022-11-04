module moltiplicatore(output [3:0]z, input [1:0]x, input [1:0]y);
    assign
        z[0] = y[0] & x[0];

    assign
        z[1] = (~x[1] & x[0] & y[1]) | (y[1] & ~y[0] & x[0]) | (~y[1] & y[0] & x[1]) | (x[1] & ~x[0] & y[0]);

    assign
        z[2] = (x[1] & ~x[0] & y[1]) | (y[1] & ~y[0] & x[1]);

    assign
        z[3] = x[1] & x[0] & y[1] & y[0];
endmodule