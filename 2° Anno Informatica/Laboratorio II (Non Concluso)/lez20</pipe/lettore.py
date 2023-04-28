#!/usr/bin/env python3
# legge i dati dalla pipe passata sulla linea di comando

import sys, os, struct


def main(nome):
  fd = os.open(nome,os.O_RDONLY)
  print(f"=={os.getpid()}== {nome} aperto in lettura",file=sys.stderr)
  tot = 0
  while True:
    # legge fino a 4 byte mettendoli in un bytarray
    bs = os.read(fd,4)
    if len(bs)==0:    # non c'e' nessuno che scrive: termina
      break
    tot +=1
    # converte i 4 byte letti in un intero e lo stampa
    valore = struct.unpack("<i",bs)[0] 
    print(f"=={os.getpid()}== {valore}")
  print(f"=={os.getpid()}== Letti {tot} interi",file=sys.stderr)
 
 
if len(sys.argv)!=2:
  print("Uso:\n\t %s nomepipe" % sys.argv[0])
else:
  main(sys.argv[1])
 
