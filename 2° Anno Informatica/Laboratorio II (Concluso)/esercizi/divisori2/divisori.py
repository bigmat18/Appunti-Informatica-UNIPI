#! /usr/bin/env python3

# programma divisori.py
# calcola il numeri di divisori degli interi dati nei file di input 

import sys

def main(infiles):
	for infile in infiles:  
		with open(infile,"r") as f:
			for s in f:
				x = int(s)
				d = divisori(x)
				print(x,d)

def divisori( n ):
  assert(n>0)
  tot = 0
  for i in range ( 1,n+1 ):
    if n%i==0:
      tot += 1
  return tot


if len(sys.argv)<2:
  print("Uso:\n\t %s infile1 infile2 ... infile3" % sys.argv[0])
else:
  main(sys.argv[1:])
