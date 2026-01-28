/* 2) Per ogni studente vogliamo conoscere: 
  -i dati anagrafici,
  -gli esami svolti con voti e date 
  -il titolo di studi, se conseguito, con voto, data e punteggio 
  -le iscrizioni ai corsi di studi effettuate, con data, anno accademico e tipo di iscrizione
*/

-- dati anagrafici, matricola e laurea
SELECT
  s.Nome,
  s.Cognome,
  s.DataNascita,
  s.Sesso,
  s.CodiceFiscale AS CF,
  cr.NomeComune AS Residenza,
  cd.NomeComune AS Domicilio,
  ms.Matricola,
  ms.DataImmatricolazione,
  cl.NomeCorsoLaurea AS CDL,
  l.Titolo AS TitoloLaurea,
  l.DataLaurea,
  l.Voto AS VotoLaurea,
  l.Lode AS LodeLaurea,
  l.AnnoAccademico AS AALaurea
  
FROM studente s
LEFT JOIN comune cr ON s.IdResidenza = cr.IdComune
INNER JOIN comune cd ON s.IdDomicilio = cd.IdComune
LEFT JOIN matricolastudente ms ON s.IdStudente = ms.IdStudente
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea
LEFT JOIN laurea l ON ms.Matricola = l.Matricola
ORDER BY s.Cognome, s.Nome;

--  esami sostenuti per ogni studente
SELECT
  s.Cognome,
  s.Nome,
  ms.Matricola,
  cl.NomeCorsoLaurea AS Laurea,
  ins.NomeInsegnamento AS NomeMateria,
  vf.DataVerifica AS DataEsame,
  vf.Voto AS VotoEsame,
  case when vf.Lode = 0 then 'No'
       when vf.Lode = 1 then 'Si'
  end as Lode,
  case when vf.Validita = 0 then 'No'
       when vf.Validita = 1 then 'Si'
  end as Validita,
  vf.AnnoAccademico AS AAEsame
FROM studente s
INNER JOIN matricolastudente ms ON s.IdStudente = ms.IdStudente
INNER JOIN verifichefinali vf ON ms.Matricola = vf.Matricola
INNER JOIN insegnamento ins ON vf.IdInsegnamento = ins.IdInsegnamento
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea
ORDER BY s.Cognome, s.Nome, vf.DataVerifica;

-- Iscrizioni annuali per ogni studente
SELECT
  s.Cognome,
  s.Nome,
  ms.Matricola,
  cl.NomeCorsoLaurea as CDL,
  i.AnnoAccademico,
  i.DataIscrizione,
  i.ProgressivoAnno as Anno,
  i.Tipo AS Iscrizione
FROM studente s
INNER JOIN matricolastudente ms ON s.IdStudente = ms.IdStudente
INNER JOIN iscrizione i ON ms.Matricola = i.Matricola
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea
ORDER BY s.Cognome, s.Nome, i.AnnoAccademico;
