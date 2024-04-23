#! /usr/bin/env python3

import sys, threading, logging, time, os
import concurrent.futures

# configurazione del logging
# il logger scrive su un file con nome uguale al nome del file eseguibile
logging.basicConfig(filename=os.path.basename(sys.argv[0])[:-3] + '.log',
                    level=logging.DEBUG, datefmt='%d/%m/%y %H:%M:%S',
                    format='%(asctime)s - %(levelname)s - %(message)s')



# classe usata per rappresentare la somma e il suo mutex
class Somma:
  def __init__(self):
    self.somma = 0
    self.lock = threading.Lock() # questo è l'analogo di un mutex del C


# calcola la somma dei primi in [a,b) 
def tbody(a,b,somma):
  logging.debug(f"Inizia esecuzione del thread che parte da {a} e arriva a {b}")
  lis = elenco_primi(a, b)
  for p in lis:
    with somma.lock:
      tmp = somma.somma + p
      time.sleep(0.01)
      somma.somma = tmp
  logging.debug(f"Termina esecuzione del thread che parte da {a} e arriva a {b}")
  return


# funzione per calcolare la somma dei primi in [a,b]
def main(a,b,p):
  logging.debug("Inizia esecuzione di main")
  assert p>0, "Il numero di thread deve essere maggiore di 0"
  # crea l'intervallo per ognuno dei p thread
  somma = Somma()
  with concurrent.futures.ThreadPoolExecutor(max_workers=p) as executor:
    for i in range(p):
      ai = a+(b-a)*i//p
      bi = a+(b-a)*(i+1)//p-1
      # esempio di uso di submit(): crea un singolo thread 
      # che esegue la funzione tbody con i parametri ai, bi, somma
      executor.submit(tbody, ai, bi, somma)
  print(f"La somma dei primi in [{a},{b}) e' {somma.somma}") 
  logging.debug("Termina esecuzione di main")
  return


# restituisce lista dei primi in [a,b]
def elenco_primi(a,b):
  ris = []
  for i in range(a,b+1):
    if primo(i):
      ris.append(i);
  return ris


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


# invoca il main con i parametri passati sulla linea di comando 
if len(sys.argv)==3:
  main(int(sys.argv[1]), int(sys.argv[2]), 1)
elif len(sys.argv)==4:
  main(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
else:
  print("Uso:\n\t %s inizio fine [numthread]" % sys.argv[0])



