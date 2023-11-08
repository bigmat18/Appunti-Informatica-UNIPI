module rete(output z, input a, input b, input c);
    wire x;

    Uno reteF(x, a, b);
    Due reteG(z, x, c);
endmodule