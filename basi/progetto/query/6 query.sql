-- Per ogni docente, riportare l’elenco dei titoli di studi con voto, data, titolo della tesi e studente di cui è stato relatore.


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

-- JOIN con la tabella relatore (collegamento docente-studente)
LEFT JOIN relatore r ON d.IdDocente = r.IdDocente

-- JOIN con matricola per ottenere i dati dello studente
LEFT JOIN matricolastudente ms ON r.Matricola = ms.Matricola

-- JOIN con laurea per ottenere i dati della tesi
LEFT JOIN laurea l ON ms.Matricola = l.Matricola

-- JOIN con studente per i dati anagrafici
LEFT JOIN studente s ON ms.IdStudente = s.IdStudente

-- JOIN con corso di laurea
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea

ORDER BY d.Cognome, d.Nome, l.DataLaurea DESC;