#! /usr/bin/env python3
# multipclient.py
# lancia -t processi client per testare i server concorrenti

Description ="""Client che manda richieste multiple concorrenti al server dei primi"""

import struct,socket,argparse,concurrent.futures, time

# default HOST e PORT
HOST = "127.0.0.1"  
PORT = 65432        


def main(a,b,host,port):
  # inizializzazione socket client 
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # la prossima chiamata è blocking 
    s.connect((host, port))
    print("Connesso a", s.getpeername())
    # pronto per inviare la richiesta
    s.sendall(struct.pack("!2i",a,b))
    # chiedo quanti primi mi verranno restituiti
    data = recv_all(s,4)
    n = struct.unpack("!i",data)[0]
    print("Devo ricevere", n, "primi")
    # ricevo i byte di tutti i primi e li decodifico
    data = recv_all(s,4*n)
    # notare l'uso dell'espressione {n} per leggere n interi
    primi = struct.unpack(f"!{n}i",data)
    for p in primi:  
      print(f"{p:>12}") # stampa p right aligned in 12 caratteri
    print("finito")
    s.shutdown(socket.SHUT_RDWR)


# Riceve esattamente n byte dal socket conn e li restituisce
# il tipo restituto è "bytes": una sequenza immutabile di valori 0-255
def recv_all(conn,n):
  chunks = b''
  bytes_recd = 0
  while bytes_recd < n:
    chunk = conn.recv(min(n - bytes_recd, 1024))
    if len(chunk) == 0:
      raise RuntimeError("socket connection broken")
    chunks += chunk
    bytes_recd = bytes_recd + len(chunk)
  return chunks


# questo codice viene eseguito solo se il file è eseguito direttamente
# e non importato come modulo con import da un altro file
if __name__ == '__main__':
  # parsing della linea di comando vedere la guida
  #    https://docs.python.org/3/howto/argparse.html
  parser = argparse.ArgumentParser(description=Description, formatter_class=argparse.RawTextHelpFormatter)
  parser.add_argument('min', help='minimo', type = int)  
  parser.add_argument('max', help='massimo', type = int)  
  parser.add_argument('-a', help='host address', type = str, default=HOST)  
  parser.add_argument('-p', help='port', type = int, default=PORT) 
  parser.add_argument('-t', help='numero processi', type = int, default=1) 
  args = parser.parse_args()
  assert args.t > 0, "Il numero di thread deve essere maggiore di 0"
  with concurrent.futures.ProcessPoolExecutor(max_workers=args.t) as executor:
    for i in range(args.t):
      # attenzione: l'executor non mostra eventuali eccezioni verficate in main() 
      executor.submit(main,1000*i+args.min,1000*i+args.max,args.a,args.p)
