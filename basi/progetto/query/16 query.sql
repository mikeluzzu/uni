-- Per ogni comune e per ogni anno accademico vogliamo conoscere la percentuale della popolazione degli studenti iscritti al corso
-- di laurea in Informatica.

SELECT 
    c.IdComune,
    c.NomeComune,
    c.NumeroAbitanti AS PopolazioneComune,
    isc.AnnoAccademico,
    COUNT(DISTINCT ms.Matricola) AS StudentiInformatica,  -- conto gli studenti 
    ROUND((COUNT(DISTINCT ms.Matricola) * 100.0) / c.NumeroAbitanti, 2) AS PercentualeStudenti  -- conto la percentuale su ogni matricola iscritta al corso
FROM 
    comune c
    LEFT JOIN studente s ON c.IdComune = s.IdDomicilio
    LEFT JOIN matricolastudente ms ON s.IdStudente = ms.IdStudente
    LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea
    LEFT JOIN iscrizione isc ON ms.Matricola = isc.Matricola
WHERE 
    cl.NomeCorsoLaurea = 'Informatica'  -- filtro le matricole che corrispondono ad informatica
    AND c.NumeroAbitanti > 0  -- evito di dividere per 0 se la popolazione è null
GROUP BY 
    c.IdComune, 
    c.NomeComune, 
    c.NumeroAbitanti,
    isc.AnnoAccademico
ORDER BY 
    c.NomeComune, 
    isc.AnnoAccademico;






