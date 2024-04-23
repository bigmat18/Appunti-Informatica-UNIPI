#! /usr/bin/env python3
# server che fornisce l'elenco dei primi in un dato intervallo 
# gestisce più clienti contemporaneamente usando i thread
# invia il byte inutile all'inizio della connessione
import sys, struct, socket, threading, concurrent.futures


# host e porta di default
HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)
 

def main(host=HOST,port=PORT):
  # creiamo il server socket
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    try:  
      s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)            
      s.bind((host, port))
      s.listen()
      with concurrent.futures.ThreadPoolExecutor(max_workers=5) as executor:
        while True:
          print("In attesa di un client...")
          # mi metto in attesa di una connessione
          conn, addr = s.accept()
          # l'esecuzione di submit non è bloccante
          # fino a quando ci sono thread liberi
          executor.submit(gestisci_connessione, conn,addr)
    except KeyboardInterrupt:
      pass
    print('Va bene smetto...')
    s.shutdown(socket.SHUT_RDWR)
    

# gestisci una singola connessione con un client
def gestisci_connessione(conn,addr): 
  # in questo caso potrei usare direttamente conn
  # e l'uso di with serve solo a garantire che
  # conn venga chiusa all'uscita del blocco
  # ma in generale with esegue le necessarie
  # inzializzazione e il clean-up finale
  with conn:  
    print(f"{threading.current_thread().name} contattato da {addr}")
    # ---- invio un byte inutile (il codice ascii di x) 
    conn.sendall(b'x')
    # ---- attendo due interi da 32 bit
    data = recv_all(conn,8)
    assert len(data)==8
    inizio  = struct.unpack("!i",data[:4])[0]
    fine = struct.unpack("!i",data[4:])[0]
    print(f"Ho ricevuto i valori:", inizio,fine)
    # ---- calcolo elenco dei primi
    primi = elenco_primi(inizio, fine)
    # ---- invio risultato in formato preceduto da lunghezza
    conn.sendall(struct.pack("!i",len(primi))) #lunghezza
    for p in primi:
      conn.sendall(struct.pack("!i",p))       # singoli valori 
  print(f"{threading.current_thread().name} finito con {addr}")
 


# riceve esattamente n byte e li restituisce in un array di byte
# il tipo restituto è "bytes": una sequenza immutabile di valori 0-255
# analoga alla readn che abbiamo visto nel C
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
        # fa attendere solamente questo thread 
        # threading.Event().wait(.5)
        if n%i==0:
            return False
        if i*i > n:
            break    
    return True



if len(sys.argv)==1:
  main()
elif len(sys.argv)==2:
  main(sys.argv[1])
elif len(sys.argv)==3:
  main(sys.argv[1], int(sys.argv[2]))
else:
  print("Uso:\n\t %s [host] [port]" % sys.argv[0])



