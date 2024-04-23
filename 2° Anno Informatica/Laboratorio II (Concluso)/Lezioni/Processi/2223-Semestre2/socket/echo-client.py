#! /usr/bin/env python3
# echo-client.py


# esempio di un client che si connette a echo-server.py


import sys,socket

# valori di default verso cui connettersi 
HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432        # The port used by the server


# creazione del socket per la connesssione al server
def main(host=HOST,port=PORT):
  print(f"Mi collego a {host} sulla porta {port}")
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((host, port))
    while True:
      n = int(input("Quanti byte? "))
      if n<=0:
        break
      # invio stringa di n a e attendo la risposta   
      msg = "a"*n  
      # converte il messaggio in sequenza di byte
      s.sendall(msg.encode())
      data = s.recv(64)
      print(f"Ricevuto {data}, bytes: {len(data)}")
      if len(data)==0:
        break
    # all'uscita dal blocco with viene eseguito s.close()
    # ma per uscire in maniera più pulita dobbiamo
    # usare prima anche shutdown()
    # SHUT_RDWR indica che terminiamo sia lettura che scrittura     
    s.shutdown(socket.SHUT_RDWR)



# invoca il main con i parametri passati sulla linea di comando 
# oppure con HOST e PORT di default
if len(sys.argv)==1:
  main()
elif len(sys.argv)==2:
  main(sys.argv[1])
elif len(sys.argv)==3:
  main(sys.argv[1], int(sys.argv[2]))
else:
  print("Uso:\n\t %s [host] [port]" % sys.argv[0])

