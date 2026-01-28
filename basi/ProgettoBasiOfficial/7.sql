-- 7) Per ogni docente, riportare l’elenco dei titoli di studi con voto, data, titolo della tesi e studente di cui è stato controrelatore

SELECT 
    concat(d.Nome, ' ', d.Cognome) as Docente,
    l.Titolo AS TitoloTesi,
    l.Voto AS VotoLaurea,
    l.Lode,
    l.DataLaurea,
    concat(s.Nome, ' ', s.Cognome) as Studente,
    ms.Matricola,
    cl.NomeCorsoLaurea as CDL

FROM docente d

LEFT JOIN laurea l ON d.IdDocente = l.IdControRelatore
LEFT JOIN matricolastudente ms ON l.Matricola = ms.Matricola
LEFT JOIN studente s ON ms.IdStudente = s.IdStudente
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea

where DataLaurea is not null
  
ORDER BY l.DataLaurea DESC, d.Cognome, d.Nome;







