#! /usr/bin/env python3

# programma numeri.py
# crea un file di testo contenente un numero assegnato di interi positivi 

import random
import sys

def main(n,nomefile):
  f = open(nomefile,"w");
  assert(f!=None);
  for i in range( n ):
    x = random.randint(1, 2**20)
    print(x,file=f)
  f.close();

if len(sys.argv)!=3:
  print("Uso:\n\t %s numero_interi outfile" % sys.argv[0])
else:
  main(int(sys.argv[1]), sys.argv[2] )
