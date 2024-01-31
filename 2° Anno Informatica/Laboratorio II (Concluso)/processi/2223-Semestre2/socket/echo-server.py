#! /usr/bin/env python3
# echo-server.py


# esempio di un server che si mette in attesa 
# su di un socket e quando inizia una connessione
# si limita a rispedire ogni messaggio che ha ricevuto

import socket


# specifica da dove accettare le connessioni
HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)

# creazione del server socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()   
    while True:
      print(f"In attesa di un client su porta {PORT}...")
      # mi metto in attesa di una connessione
      conn, addr = s.accept()
      # lavoro con la connessione appena ricevuta 
      with conn:  
        print(f"Contattato da {addr}")
        while True:
            data = conn.recv(64) # leggo fino a 64 bytes
            print(f"Ricevuti {len(data)} bytes") 
            if not data:           # se ricevo 0 bytes 
                break              # la connessione è terminata
            conn.sendall(data)     # altrimenti echo
        print("Connessione terminata")

