#! /usr/bin/env python3

import sys, threading, logging, time, os
import concurrent.futures

# configurazione del logging
# il logger scrive su un file con nome uguale al nome del file eseguibile
logging.basicConfig(filename=os.path.basename(sys.argv[0])[:-3] + '.log',
                    level=logging.DEBUG, datefmt='%d/%m/%y %H:%M:%S',
                    format='%(asctime)s - %(levelname)s - %(message)s')



# classe usata per passare i dati ai thread e ricevere il risultato
class Dati:
  def __init__(self,a,b):
    self.a = a
    self.b = b
    self.risultato = -1


# corpo del thread
def tbody(dati):
  logging.debug(f"Inizia esecuzione del thread che parte da {dati.a} e arriva a {dati.b}")
  dati.risultato = conta_primi(dati.a, dati.b)
  logging.debug(f"Termina esecuzione del thread che parte da {dati.a} e arriva a {dati.b}")
  return dati.risultato


def main(a,b):
  logging.debug("Inizia esecuzione del main")
  # crea 2 thread passando ad ognuno i suoi dati
  c = (a+b)//2
  d1 = Dati(a,c)
  d2 = Dati(c,b)
  t1 = threading.Thread(target=tbody, args=(d1,))
  t2 = threading.Thread(target=tbody, args=(d2,))
  # avvia i thread misurando il tempo di esecuzione
  start = time.time()
  t1.start()
  t2.start()
  t1.join()
  t2.join()
  end = time.time()
  print(f"Tra {a} e {b} ci sono {d1.risultato+d2.risultato} primi e ci ho messo {end-start:.2f} secondi")
  logging.info("Termina esecuzione del main")
  return
 
def main2(a,b,p):
  logging.debug("Inizia esecuzione di main2")
  assert p>1, "Il numero di thread deve essere maggiore di 1"
  # crea l'intervallo per ognuno dei p thread
  dati = []
  for i in range(p):
    dati.append(Dati(a+(b-a)*i//p, a+(b-a)*(i+1)//p-1))
  # avvia i thread misurando il tempo di esecuzione 
  start = time.time() 
  # se nella riga seguente uso ProcessPoolExecutor invece di ThreadPoolExecutor
  # vengono lanciati processi invece che thread
  with concurrent.futures.ThreadPoolExecutor(max_workers=p) as executor:
    # il return value di ogni singola chiamata a tbody viene messo in risultati
    risultati = executor.map(tbody, dati)
  # il calcolo del tempo di esecuzione e' da fare fuori dal contesto del with
  # perché executor.map() termina prima che abbiano terminato tutti i thread
  end = time.time()
  tot = 0
  for r in risultati:
    tot += r
  # metodo di calcolo del risultato quando viene scritto in dati.risultato
  # non può essere usato per un pool di processi  
  #for d in dati:
  #  tot += d.risultato
  print(f"Tra {a} e {b} ci sono {tot} primi e ci ho messo {end-start:.2f} secondi")
  logging.debug("Termina esecuzione di main2")
  return




# conta i primi in [a,b]
def conta_primi(a,b):
  tot = 0
  for i in range(a,b+1):
    if primo(i):
      tot += 1
  return tot



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
  main(int(sys.argv[1]), int(sys.argv[2]))
elif len(sys.argv)==4:
  main2(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
else:
  print("Uso:\n\t %s inizio fine [numthread]" % sys.argv[0])



