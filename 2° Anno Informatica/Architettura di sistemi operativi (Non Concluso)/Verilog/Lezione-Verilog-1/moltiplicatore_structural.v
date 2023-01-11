module moltiplicatore(output [3:0]z, input [1:0]x, input [1:0]y);
    wire [1:0]tmp1;
    wire [1:0]tmp2;

    mux #(2) molt1(tmp1, 2'b00, x, y[0]);
    mux #(2) molt2(tmp2, 2'b00, x, y[1]);

    fulladder_Nbit #(3) FA(z[3], z[2:0], 1'b0, {tmp2, 1'b0}, {1'b0, tmp1});
endmodule