module mux_1bit(output OUT, input IN1, input IN2, input ctrl);
    assign
        OUT = ctrl ? IN2 : IN1;
endmodule

module mux(output [N-1:0]OUT, input [N-1:0]IN1, input [N-1:0]IN2, input ctrl);
    parameter N=32;

    genvar i;
    generate
        for (i=0; i<N; i=i+1)
            begin
                mux_1bit mul(OUT[i], IN1[i], IN2[i], ctrl);
            end
    endgenerate
endmodule