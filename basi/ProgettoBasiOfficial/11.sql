--  Per ogni anno accademico vogliamo conoscere il numero totale di studenti immatricolati, la
-- percentuale di studenti stranieri e quella di studenti italiani.

SELECT 
    YEAR(m.DataImmatricolazione) AS AnnoAccademico,
    COUNT(*) AS TotaleStudenti,
    SUM(CASE WHEN s.Straniero = 1 THEN 1 ELSE 0 END) AS StudentiStranieri,
    SUM(CASE WHEN s.Straniero = 0 THEN 1 ELSE 0 END) AS StudentiItaliani,
    ROUND((SUM(CASE WHEN s.Straniero = 1 THEN 1 ELSE 0 END) * 100.0) / COUNT(*), 2) AS PercentualeStranieri,
    ROUND((SUM(CASE WHEN s.Straniero = 0 THEN 1 ELSE 0 END) * 100.0) / COUNT(*), 2) AS PercentualeItaliani
FROM 
    matricolastudente m
    INNER JOIN studente s ON m.IdStudente = s.IdStudente
GROUP BY 
    YEAR(m.DataImmatricolazione)
ORDER BY 
    AnnoAccademico;





