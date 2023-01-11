module testFA_2bit();
    reg [1:0]x1;
    reg [1:0]x2;
    reg ripin;
    wire ripout;
    wire [1:0]somma;

    fulladder_2bit adder(ripout, somma, ripin, x1, x2);

    initial
        begin
            $dumpfile("testFA_2bit.vcd");
            $dumpvars;

            x1 = 1;
            x2 = 2;
            ripin = 0; // somma = 3 e ripout = 0

            #6 x1 = 1;
               x2 = 3;
               ripin = 1; // somma = 1 e ripout = 1

            #6 $finish;
        end
endmodule