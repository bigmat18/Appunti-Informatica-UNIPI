module decoder (
    input [1:0]in, output [4:0]out 
);

assign out[0] = (in[1] && in[0]);
assign out[1] = (in[1] && ~in[0]);
assign out[2] = (~in[1] && in[0]);
assign out[3] = (~in[1] && ~in[0]);
    
endmodule


module testDecoder ();
    reg [1:0]in;
    wire [4:0]out;
    
    decoder dec(in, out);
    initial begin
        $dumpfile("decoder.vcd");
        $dumpvars;

        in[0] = 0;
        in[1] = 0;

        #4 in[0] = 1;
           in[1] = 0;

        #4 in[0] = 0;
           in[1] = 1;

        #4 in[0] = 1;
           in[1] = 1;

        #4 $finish;
    end
endmodule