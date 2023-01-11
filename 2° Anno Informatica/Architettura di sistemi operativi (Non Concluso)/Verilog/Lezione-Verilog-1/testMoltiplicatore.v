module testMoltiplicatore();
    reg [1:0]a;
    reg [1:0]b;
    wire [3:0]ris;

    moltiplicatore myMOL(ris, a, b);

    initial // qui comincia la descrizione della simulazione
        begin
            $dumpfile("testMoltiplicatore.vcd");
            $dumpvars;

            a = 0;
            b = 0; // ris diventa 0

            #6 a = 2;
               b = 1; // ris diventa 2

            #6 a = 3;
               b = 2; // ris diventa 6

            #6 a = 1;
               b = 1; // ris diventa 1

            #6 $finish;
        end
endmodule