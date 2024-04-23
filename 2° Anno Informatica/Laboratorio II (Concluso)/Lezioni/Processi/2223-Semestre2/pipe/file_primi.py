#!/usr/bin/env python3
# crea un file di testo contenente un numero assegnato di interi
# e stampa la somma dei primi contenuti nei file

import random
import sys, os

def main(num):
  s = 0
  nome = str(num) + "interi"
  with open(nome,"w") as f:
      for i in range(num):
        x = random.randint(1,2000000)
        print(x,file=f)
        if primo(x):
          s += x
  print("Somma primi nei file:", s)
  os.rename(nome,nome+"_somma"+str(s))

# dato un intero n>0 restituisce True se n e' primo
# False altrimenti
def primo(n):
    assert n>0, "L'input deve essere positivo"
    if n==1:
        return False
    if n==2:
        return True
    if n%2 == 0:
        return False
    assert n>=3 and n%2==1, "C'e' qualcosa che non funziona"
    for i in range(3,n//2,2):
        if n%i==0:
            return False
        if i*i > n:
            break    
    return True


if len(sys.argv)!=2:
  print("Uso:\n\t %s numero_interi" % sys.argv[0])
else:
  main(int(sys.argv[1]))

