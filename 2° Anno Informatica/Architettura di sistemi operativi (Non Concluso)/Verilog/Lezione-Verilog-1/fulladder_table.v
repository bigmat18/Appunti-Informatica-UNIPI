primitive fa_somma(output z, input ripin, input x1, input x2);
    table
        0 0 0 : 0;
        0 0 1 : 1;
        0 1 0 : 1;
        0 1 1 : 0;
        1 0 0 : 1;
        1 0 1 : 0;
        1 1 0 : 0;
        1 1 1 : 1;
    endtable
endprimitive

primitive fa_riporto(output ripout, input ripin, input x1, input x2);
    table
        0 0 0 : 0;
        0 0 1 : 0;
        0 1 0 : 0;
        0 1 1 : 1;
        1 0 0 : 0;
        1 0 1 : 1;
        1 1 0 : 1;
        1 1 1 : 1;
    endtable
endprimitive

module fulladder(output ripout, output z, input ripin, input x1, input x2);
   fa_riporto m1(ripout, ripin, x1, x2);
   fa_somma m2(z, ripin, x1, x2);
endmodule