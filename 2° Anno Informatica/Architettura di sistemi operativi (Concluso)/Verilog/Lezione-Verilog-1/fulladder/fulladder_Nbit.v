module fulladder_Nbit(output ripout, output [N-1:0]somma, input ripin, input [N-1:0]x1, input [N-1:0]x2);
    parameter N=2;
    wire rips[N-1];

    fulladder FA_primo(rips[0], somma[0], ripin, x1[0], x2[0]);

    genvar i;
    generate
        for (i=1; i<N-1; i=i+1)
            begin
                fulladder FA(rips[i], somma[i], rips[i-1], x1[i], x2[i]);
            end
    endgenerate

    fulladder FA_ultimo(ripout, somma[N-1], rips[N-2], x1[N-1], x2[N-1]);
endmodule