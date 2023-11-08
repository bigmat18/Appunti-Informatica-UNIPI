module fulladder(output ripout, output z, input ripin, input x1, input x2);
    assign
        z = (~x1 & ~x2 & ripin) | (~x1 & x2 & ~ripin) | (x1 & ~x2 & ~ripin) | (x1 & x2 & ripin);

    assign
        ripout = (~x1 & x2 & ripin) | (x1 & ~x2 & ripin) | (x1 & x2 & ~ripin) | (x1 & x2 & ripin);
endmodule