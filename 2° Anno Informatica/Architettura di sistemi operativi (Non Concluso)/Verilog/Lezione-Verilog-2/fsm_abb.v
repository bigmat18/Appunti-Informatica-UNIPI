module omega(output out, input [1:0]s, input [1:0]in); // calcola le uscite (Mealy)
    assign
        out = s[1] & s[0] & ~in[1] & in[0];
endmodule

module sigma(output [1:0]s_new, input [1:0]s, input [1:0]in); // calcolo il nuovo stato interno
    assign
        s_new[0] = ~in[0] | (~s[1] & s[0] & ~in[1]);

    assign
        s_new[1] = ~s[1] & s[0] & ~in[1] & in[0];
endmodule

module fsm_abb(output out, input [1:0]in, input clock);
    wire [1:0]stato_in;
    wire [1:0]stato_out;

    Registro #(2) stato(stato_out, stato_in, 1'b1, clock);
    omega w(out, stato_out, in);
    sigma s(stato_in, stato_out, in);
endmodule