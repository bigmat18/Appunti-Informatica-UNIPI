#! /usr/bin/env python3
# multip1client.py
# lancia -t processi client per testare i server concorrenti
# invia il byte inutile all'inizio della connessione
Description ="""Client che manda connessione multiple concorrenti"""


import sys,struct,socket,time,argparse,concurrent.futures

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432        # The port used by the server


def main(a,b,host=HOST,port=PORT):
  # inizializzazione socket client 
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # la prossima chiamata è blocking 
    s.connect((host, port))
    print("Io", s.getsockname(), "sono connesso a", s.getpeername())
    # legge il byte inutile
    data = recv_all(s,1)
    assert data[0] == 120, "A questo punto mi aspettavo il codice ascii di x"
    time.sleep(6)   # simulo una rete lenta 
    # pronto per inviare la richiesta
    s.sendall(struct.pack("!i",a))
    s.sendall(struct.pack("!i",b))
    # chiedo quanti primi mi verranno restituiti
    data = recv_all(s,4)
    n = struct.unpack("!i",data)[0]
    print("Devo ricevere", n, "primi", s.getsockname())
    for i in range(n):
      data = recv_all(s,4)
      p = struct.unpack("!i",data)[0]
    print(s.getsockname(), "finito")


# Riceve esattamente n byte dal socket conn e li restituisce
# il tipo restituto è "bytes": una sequenza immutabile di valori 0-255
# Questa funzione è analoga alla readn che abbiamo visto nel C
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
  parser.add_argument('-t', help='threads', type = int, default=1) 
  args = parser.parse_args()
  assert args.t > 0, "Il numero di thread deve essere positivo"
  with concurrent.futures.ProcessPoolExecutor(max_workers=args.t) as executor:
    for i in range(args.t):
      # attenzione: l'executor non mostra eventuali eccezioni verificate in main() 
      executor.submit(main,1000*i+args.min,1000*i + args.max,args.a,args.p)

