-- Numero di studenti che hanno svolto esami raggruppati per fascio di voto (18-23, 24-27, 28-30, 30 e lode) e per corso d studi e anno di corso
-- (quelli del primo anno, del secondo anno, ecc.)

SELECT 
    cl.NomeCorsoLaurea AS CorsoStudi,
    isc.ProgressivoAnno AS AnnoDiCorso,
    CASE 
        WHEN vf.Voto = 30 AND vf.Lode = 1 THEN '30 e lode'
        WHEN vf.Voto BETWEEN 28 AND 30 THEN '28-30'
        WHEN vf.Voto BETWEEN 24 AND 27 THEN '24-27'
        WHEN vf.Voto BETWEEN 18 AND 23 THEN '18-23'
        ELSE 'Altro'
    END AS FasciaVoto,
    COUNT(DISTINCT vf.Matricola) AS NumeroStudenti
FROM 
    verifichefinali vf
    INNER JOIN matricolastudente m ON vf.Matricola = m.Matricola
    INNER JOIN corsolaurea cl ON m.IdCorsoLaurea = cl.IdCorsoLaurea
    INNER JOIN iscrizione isc ON vf.Matricola = isc.Matricola 
        AND vf.AnnoAccademico = isc.AnnoAccademico
WHERE 
    vf.Validita = 1  -- Solo esami validi
GROUP BY 
    cl.NomeCorsoLaurea,
    isc.ProgressivoAnno,
    CASE 
        WHEN vf.Voto = 30 AND vf.Lode = 1 THEN '30 e lode'
        WHEN vf.Voto BETWEEN 28 AND 30 THEN '28-30'
        WHEN vf.Voto BETWEEN 24 AND 27 THEN '24-27'
        WHEN vf.Voto BETWEEN 18 AND 23 THEN '18-23'
        ELSE 'Altro'
    END
ORDER BY 
    cl.NomeCorsoLaurea,
    isc.ProgressivoAnno,
    FasciaVoto;
  
  





