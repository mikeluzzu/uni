/* 2) Per ogni studente vogliamo conoscere: 
  -i dati anagrafici,
  -gli esami svolti con voti e date 
  -il titolo di studi, se conseguito, con voto, data e punteggio 
  -le iscrizioni ai corsi di studi effettuate, con data, anno accademico e tipo di iscrizione
*/

-- query separate tra dati anagrafici, esami, iscrizione

-- parte 1 : Dati anagrafici, matricola e laurea
SELECT
  s.Nome,
  s.Cognome,
  s.DataNascita,
  s.Sesso,
  s.CodiceFiscale,
  cr.NomeComune AS ComuneResidenza,
  cd.NomeComune AS ComuneDomicilio,
  ms.Matricola,
  ms.DataImmatricolazione,
  cl.NomeCorsoLaurea,
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

-- parte 2: Esami sostenuti per ogni studente
SELECT
  s.Cognome,
  s.Nome,
  ms.Matricola,
  cl.NomeCorsoLaurea,
  ins.NomeInsegnamento,
  vf.DataVerifica AS DataEsame,
  vf.Voto AS VotoEsame,
  vf.Lode,
  vf.Validita,
  vf.AnnoAccademico AS AAEsame
FROM studente s
INNER JOIN matricolastudente ms ON s.IdStudente = ms.IdStudente
INNER JOIN verifichefinali vf ON ms.Matricola = vf.Matricola
INNER JOIN insegnamento ins ON vf.IdInsegnamento = ins.IdInsegnamento
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea
ORDER BY s.Cognome, s.Nome, vf.DataVerifica;

-- parte 3 : Iscrizioni annuali per ogni studente
SELECT
  s.Cognome,
  s.Nome,
  ms.Matricola,
  cl.NomeCorsoLaurea,
  i.AnnoAccademico,
  i.DataIscrizione,
  i.ProgressivoAnno,
  i.Tipo AS TipoIscrizione
FROM studente s
INNER JOIN matricolastudente ms ON s.IdStudente = ms.IdStudente
INNER JOIN iscrizione i ON ms.Matricola = i.Matricola
LEFT JOIN corsolaurea cl ON ms.IdCorsoLaurea = cl.IdCorsoLaurea
ORDER BY s.Cognome, s.Nome, i.AnnoAccademico;
