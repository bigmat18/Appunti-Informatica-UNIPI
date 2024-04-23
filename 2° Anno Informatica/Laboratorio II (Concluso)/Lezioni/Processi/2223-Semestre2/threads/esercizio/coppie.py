#!/usr/bin/env python3
# programma coppie.py
# crea un file di testo contenente un numero assegnato di coppie di interi positivi
# e un file con i gcd ordinati in modo crescente
import random
import sys

def main(n,nomefile):
  a = []
  # --- crea file di coppie
  with open(nomefile,"w") as f:
    for i in range( n ):
      x = random.randint(1,100)
      y = random.randint(1,100)
      print(x,y,file=f)
      a.append(gcd(x,y))
  # ----- crea file dei gcd ordinati
  a.sort()
  with open(nomefile+".gcd","w") as f:
    for x in a:
      print(x,file=f)
  
def gcd(a,b):
  if b==0:
    return a
  return gcd(b,a%b)

if len(sys.argv)!=3:
  print("Uso:\n\t %s numero_coppie outfile" % sys.argv[0])
else:
  main(int(sys.argv[1]), sys.argv[2] )