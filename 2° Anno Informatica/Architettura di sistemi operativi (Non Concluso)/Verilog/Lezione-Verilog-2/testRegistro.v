module testRegistro();
    reg clock;
    reg we;
    reg [7:0] in;
    wire [7:0] out;

    Registro myreg(out, in, we, clock);

    always
        begin
            #2 clock = 1;
            #2 clock = 0;
        end

    initial
        begin
            $dumpfile("testRegistro.vcd");
            $dumpvars;

            clock = 0; // valore iniziale del clock
            we = 0; // inizialmente scrittura disabilitata

            in = 7;

            #5 we = 1; // scrittura abilitata

            #6 in = 12;

            #6 in = 5;

            #8 $finish;
        end
endmodule