BASI DI DATI LABORATORIO 20 ottobre

per creare le tabelle usiamo CREATE TABLE
per modificare le tabelle usiamo ALTER TABLE

è meglio creare prima tutte le tabelle con CREATE TABLE 
successivamente fare l ALTER TABLE per aggiungere i dati

con auto possiamo inserire qualsiasi dato, lo trova da solo il tipo

durante il porting dei dati non possiamo perdere dati, quindi quando insieriamo dati in un database 

se ho un vincolo referenziale di un dato  relativo ad un altra tabella esterna, non posso inserire il dato perchè non esiste.


per eliminare una tabella usiamo DROP TABLE 

Definizione degli indici: è rilevante per le prestazioni 

i tempi di risposta delle query devono essere accettabili rispetto all applicativo che si usa.  
 
 con l'istruzione CREATE INDEX creaiamo un indice nelle tabelle, possiamo mettere piu colonne nell'indice e l'ordine di queste colonne è importante

quando avviamo mySql il server sta in attesa su una porta, questo server su cui gira mySql tendenzialmente è progettato solo per mySql, con hardware performante. 

il dmbs admin può decidere a chi dare gli accessi, per esempio a specifici utenti o dipendenti. 

la maggior parte dei database girano su linux, quindi è meglio usare la riga di comando da linux piuttosto che l'ui.

il computer che contiene il dbms non deve essere accessibile, non deve essere mai esposto in una rete. Deve essere accessibile tramite altri applicativi, che aggiungono un layer di sicurezza. Usare ssh con vpn,


CREATE TABLE infrazioni(
    Codice int,
    Data DATE,
    Provincia char(2),
    Vigile int,
    
);
