-- Per ogni docente, riportare l’elenco dei titoli di studi con voto, data, titolo della tesi e studente di cui è stato relatore.

SELECT 
    concat(d.Nome, ' ', d.Cognome) as Docente,
    l.Titolo AS TitoloTesi,
    l.Voto AS VotoLaurea,
    case when l.Lode = 0 then 'No'
       when l.Lode = 1 then 'Si'
    end as Lode,
    l.DataLaurea,
    concat(s.Nome, ' ', s.Cognome) as Studente,
    ms.Matricola,
    cl.NomeCorsoLaurea as CDL

FROM docente d

LEFT JOIN relatore r ON d.IdDocente = r.IdDocente
LEFT JOIN matricolastudente ms ON r.Matricola = ms.Matricola
LEFT JOIN laurea l ON ms.Matricola = l.Matricola
LEFT JOIN studente s ON ms.IdStudente = s.IdStudente
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea

where DataLaurea is not null
  
ORDER BY l.DataLaurea DESC, d.Cognome, d.Nome ;