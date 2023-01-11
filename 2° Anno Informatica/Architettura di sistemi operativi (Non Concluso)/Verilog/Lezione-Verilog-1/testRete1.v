module testRete1();
    reg a, b; // un registro per ogni ingresso del modulo sotto test
    wire c; // un filo per ogni uscita del modulo sotto test

    rete1 myRete1(c, a, b); // si istanzia il modulo sotto test e lo si collega a reg/wire

    initial // qui comincia la descrizione della simulazione
        begin
            $dumpfile("testRete1.vcd"); // vogliamo vedere i cambiamenti delle variabili su file
            $dumpvars; // abilitiamo il dump su file

            // $monitor("A: %b, B: %b -> C: %b\n", a, b, c);

            a = 0;
            b = 0; // c diventa 1

            #4 a = 1;
               b = 1; // c diventa 0

            #4 a = 1;
               b = 0; // c diventa 1

            #4 a = 1;
               b = 1; // c diventa 0

            #4 $finish;
        end
endmodule