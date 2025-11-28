-- 7) Per ogni docente, riportare l’elenco dei titoli di studi con voto, data, titolo della tesi e studente di cui è stato controrelatore


SELECT 
    -- Dati del docente
    d.Nome AS NomeDocente,
    d.Cognome AS CognomeDocente,
    
    -- Dati della laurea
    l.Titolo AS TitoloTesi,
    l.Voto AS VotoLaurea,
    l.Lode,
    l.DataLaurea,
    
    -- Dati dello studente laureato
    s.Nome AS NomeStudente,
    s.Cognome AS CognomeStudente,
    ms.Matricola,
    
    -- Dati del corso di laurea
    cl.NomeCorsoLaurea

FROM docente d
-- prendo l'id del docente che corrisponde all'id del controrelatore
LEFT JOIN laurea l ON d.IdDocente = l.IdControRelatore
  
-- join matricolastudente e prendo la matricola corrispondente 
LEFT JOIN matricolastudente ms ON l.Matricola = ms.Matricola

-- JOIN con studente per prendere i dati dello studente con quella matricola
LEFT JOIN studente s ON ms.IdStudente = s.IdStudente

-- JOIN con corso di laurea per prendere il corso di laurea di quella matricola
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea

ORDER BY d.Cognome, d.Nome, l.DataLaurea DESC;







