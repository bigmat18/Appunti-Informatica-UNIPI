module FlipFlopD_en(output q, output notq, input clock, input d, input en);
    wire c1;

    assign
        c1 = clock & en;

    FlipFlopD ff(q, notq, c1, d);
endmodule