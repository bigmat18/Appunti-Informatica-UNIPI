#!/usr/bin/env python3

"""
esercizio sulle named pipe
  legge gli interi dal file di testo argv[1] e li
  scrive nella pipe somma_down 
  al termine, aspetta dalla pipe somma_up le somme dei primi 
  provenienti dai processi ausiliari
"""	
import sys, os, struct

"""
funzioni utili
  os.mkfifo(path)						# crea una named fifo
  os.unlink(path)						# cancella un file
  os.open(path,flags)       # analoga alla open dal C
  os.read(fd,n)             # leggedal file descriptor fd
	struct.pack(format,val)   # trasforma int -> sequenza byte
  struct.unpack(format,bs)  # trasforma sequenza byte -> int
"""


# Variabili globali con i nomi delle pipe da usare
Pipeup = "somma_up"
Pipedown = "somma_down"


def main(nomefile):

	## DA COMPLETARE!!!
	
  # apriamo pipe verso i programmi C
  fd = os.open(Pipedown,os.O_WRONLY)
  # apriamo il file di testo contenente gli interi
  tot = 0
  with open(nomefile,"r") as f:
    for linea in f:
			# converte linea in intero 
      intero = int(linea)
			# converto intero in sequenza di byte scrive nella pipe
      bs = struct.pack("<i",intero)
      os.write(fd,bs)
      tot += 1
  print(f"{tot} interi letti da file e scritti nella pipe")

	

	
# lancio di main()
if len(sys.argv)!=2:
  print("Uso:\n\t %s nome_file_interi" % sys.argv[0])
else:
  main(sys.argv[1])
 
