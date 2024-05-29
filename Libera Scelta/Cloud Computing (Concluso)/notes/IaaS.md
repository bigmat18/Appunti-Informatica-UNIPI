**Hypervios**: crea un layer virtulizzato che consente ai server di runnare più macchine virtuali ospiti. Esistono **due** tipi:
- **Tipo 1**: caricare direttamente sull'hardware, senza OS, un alto ratio di consolidamento, usato per datacenter.
- **Tipo 2**: caricate su un OS, basso consolidation ratio, per deskstop/laptop.

## AWS EC2
- Mette a disposizioni server virtuali
- Si può scegliere con console o SDK tipo istante e template (window/linux)
- Ampia gamma istanza (CPU, memoria, storage, GPU)
- Pagamento del tipo on demand, istanze riservate, istanze spot.
- Storage persistente (EBS)
- Autoscaling

AWS ha il 40.0% del mercato
Microsoft il 22.5%
Alibaba 7.7%
Google 7.7%
Huawei 4.4%
##### Crea un istanza EC2
1. EC2 -> Istanze -> Avvia un’istanza 
2. Specificare il nome dell’istanza 
3. Scegliere l’immagine Amazon Linux 2 
4. Selezionare il tipo di istanza t2.micro (verificare che sia presente la scritta «Idoneo al piano gratuito») 
5. Selezionare la coppia di chiavi creata precedentemente 
6. Lasciare il resto delle impostazioni inalterate 
7. Verificare la correttezza della configurazione nel «Riepilogo» 
8. Cliccare su «Avvia istanza»
##### Crea un coppia chiave EC2
1. Accedere al servizio EC2 
2. Verificare di essere nella regione di Parigi 
3. EC2 -> Rete e sicurezza -> Coppie di chiavi -> Crea una coppia di chiavi 
4. Specificare il nome della coppia di chiavi 
5. Selezionare il formato .pem 
6. Cliccare su «Crea una coppia di chiavi» 
7. È importante tenere traccia del percorso del file .pem scaricato, in quanto ci servirà in seguito
##### Accedere da terminale ad istanza
1. Avviare un terminale nella directory dove è salvata la chiave.pem
	- Su linux:
	```
	chmod 400 chiavi.pem
	```
	- Su window:
	```
	icacls.exe chiavi.pem /reset 
	icacls.exe chiavi.pem /grant:r "$($env:username):(r)" 
	icacls.exe chiavi.pem /inheritance:r
	```
2. Accedere tramite ssh all'istanza EC2 
```
ssh –i chiavi.pem ec2-user@
```

## AWS S3
- Fornisce storage sicuro e facile 
- Un "bucket" su una regione specifica
- Affidabilità garantita da più copie su server diversi in DC diversi, e versioning.
- Diverse classi di memorizzazione
- Controllo accessi semplice (politiche identità, liste accesso, SSL)
##### Creare un bucket S3
1. S3 -> Bucket -> Crea bucket
2. Specificare il nome del Bucket e la regione (noi useremo quella di Parigi: eu-west-3)
3. Lasciare «ACL disabilitate» 
4. Lasciare «Blocca tutti gli accessi pubblici» 
5. Cliccare su «Crea bucket»
##### Caricare e gestire gile da s3 a ec2
1. Caricare un file su bucket s3
2. Dentro terminale istanza scaricare file con il comando
```
aws s3 mv s3://<BUCKET>/<FILE> <LOCAL_PATH>
```
## AWS EBS
- Blocchi di storage persistenti da usare insieme alle instanze EC2 nel AWS cloud
- Ogni volume EBS viene automaticamente replicato all'interno della sua Zona di disponibilità per proteggersi da guasti dei componenti.
- Progettato per carichi di applicazione che traggono vantaggio dall'ottimizzazione di prestazioni, costi e capacità

## AWS IAM
Per accedere al bucket S3 dalle istanze EC2 è necessario creare un Ruolo IAM per concedere l’accesso.
1. IAM -> Ruoli -> Crea ruolo 
2. Selezionare «Servizio AWS» come «Tipo di entità attendibile»
3. Come «Caso d’uso» selezionare «EC2» 
4. Cliccare su «Successivo» 
5. Selezionare la policy «AmazonS3FullAccess»
6. Cliccare su «Successivo» e inserire il nome del ruolo

Da qui si può aggiungere il ruole all'istanza EC2
1. EC2 -> Istanze 
2. Selezionare l’istanza 
3. Operazioni -> Sicurezza- > Modifica il ruolo IAM
4. Selezionare il ruolo creato precedentemente 
5. Riprovare il comando aws