#! /usr/bin/env python3

# programma testradd.py
# crea 2 file di contenenti l'input e il corrispondente output 
# per l'esercizio raddoppia 

import random
import sys

def main(n,nomefile):
  fin = open(nomefile+".in","w");
  fout = open(nomefile+".out","w");
  for i in range( n ):
    x = random.randint(-2**20, 2**20)
    print(x,file=fin)
    if x>0:
      print(2*x,file=fout)
  fin.close(); fout.close()


if len(sys.argv)!=3:
  print("Uso:\n\t %s numero_interi nomefile" % sys.argv[0])
else:
  main(int(sys.argv[1]), sys.argv[2] )
