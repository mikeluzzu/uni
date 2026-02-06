/*
data di nascita degli iscritti che hanno seguito il maggior numero di corsi
tenuti da istruttori diversi
*/

select I.DataNascita
from Iscritto I 
join Iscrizione Iscron I.CF = Iscr.Studente
join Corso C on Iscr.Corso = C.Codice
group by I.CF, I.DataNascita
having count(distinct C.istruttore) = (
    select max(NumIstruttori) --prendo il max degli istruttori dalla subquery 
    from (
        select count(distinct C2.istruttore) as NumIstruttori
        from Iscrizione Iscr2
        join Corso C2 on Iscr2.Corso = C2.Codice
        group by Iscr2.Studente
    ) as Conteggi
);

/*coppie(iscritto,istruttore) che appaiono esattamente una volta per corsi 
di livello 'Basic'*/

select Iscr.Studente, C.istruttore
from Iscrizione Iscr
join Corso C on Iscr.Corso = C.Codice
where C.Livello = 'Basic'
group by Iscr.Studente, C.istruttore
having count(*) = 1;