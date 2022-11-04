module rete1(output z, input x, input y);
    assign
        z = (~x) | (~y); // assegnamento continuo (solo wire)
endmodule