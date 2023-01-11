// confrontatore a 1 bit
module comp1(output z, input a, input b);
    assign
        z = ~(a^b); // ^ è lo XOR
endmodule

// confrontatore a N bit
module compN(output z, input [N-1:0]a, input [N-1:0]b);
    parameter N=2;
    wire [N-1:0]w;

    genvar i;
    generate
        for(i=0; i<N; i=i+1)
            begin
                comp1 c(w[i], a[i], b[i]);
            end
    endgenerate

    assign
        z = &w; // and bit a bit di w
endmodule

// encoder 4to2
module encoder4to2(output z1, output z0, input x3, input x2, input x1, input x0);
    assign
        z0 = (~x3 * ~x2 * x1 * ~x0) + (x3 * ~x2 * ~x1 * ~x0);

    assign
        z1 = (~x3 * x2 * ~x1 * ~x0) + (x3 * ~x2 * ~x1 * ~x0);
endmodule

// multiplexer 4 input a 3 bit
module mux4(output [2:0]out, input [1:0]ctl, input[2:0]v3,  input[2:0]v2,  input[2:0]v1,  input[2:0]v0);
    assign
        out = (ctl == 2'b00 ? v0 : (ctl == 2'b01 ? v1 : (ctl == 2'b10 ? v2 : v3)));
endmodule

// Hash Table
module HT(output hit, output [2:0]outValue, input [2:0]inKey);
    // dichiarazione dei registri: il secondo è l'indice il primo è la dimensione
    reg [2:0] key[0:3];
    reg [2:0] value[0:3];

    // inizializzazione
    initial
        begin
            key[0] = 5;
            value[0] = 1;
            key[1] = 6;
            value[1] = 2;
            key[2] = 1;
            value[2] = 1;
            key[3] = 2;
            value[3] = 3;
        end

    // generatore per fare quattro confrontatori
    genvar i;
    wire [3:0]confr;
    generate
        for(i=0; i<4; i=i+1)
            begin
                compN #(3) cn(confr[i], inKey, key[i]);
            end
    endgenerate

    // hit è l'or dei confrontatori : se almeno uno è a 1 allora hit altriment fault
    assign
        hit = |confr;

    // genera il segnale per il mux
    wire [1:0]ctl;
    encoder4to2 cod(ctl[1], ctl[0], confr[3], confr[2], confr[1], confr[0]);

    // adesso scegli fra i valori
    mux4 mux(outValue, ctl, value[3], value[2], value[1], value[0]);
endmodule

// test bench
module testHT();
    reg [2:0]key;
    wire [2:0]value;
    wire hit;

    // instantiate the Hasb Table
    HT myhm(hit, value, key);
   
    initial
        begin
            $dumpfile("testHT.vcd");
            $dumpvars;

            key = 6; // ritorna hit=1 e out=2

            #10
             key = 2; // ritorna hit=1 e out=3

            #10
             key = 7; // ritorna hit=0 e out non è significativo

            #10
             $finish;
        end
endmodule