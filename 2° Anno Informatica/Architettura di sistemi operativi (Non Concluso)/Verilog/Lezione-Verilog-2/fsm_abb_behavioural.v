module fsm_abb(output out, input [1:0]in, input clock);
    reg [1:0]s;
    reg [1:0]s_new;

    initial
        s = 0;

    always @(posedge clock)
        s <= s_new;

    always @(s, in)
        begin
            s_new[0] <= ~in[1] | (~s[1] & s[0] & ~in[1]);
            s_new[1] <= ~s[1] & s[0] & ~in[1] & in[0];
        end

    assign
        out = s[1] & s[0] & ~in[1] & in[0];
endmodule