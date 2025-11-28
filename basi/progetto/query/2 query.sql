/* 2) Per ogni studente vogliamo conoscere: 
  -i dati anagrafici,
  -gli esami svolti con voti e date 
  -il titolo di studi, se conseguito, con voto, data e punteggio 
  -le iscrizioni ai corsi di studi effettuate, con data, anno accademico e tipo di iscrizione
*/

select
  -- dati anagrafici studente
  s.IdStudente,
  s.Nome,
  s.Cognome,

  cr.NomeComune as ComuneResidenza,
  cd.NomeComune as ComuneDomicilio,

  -- dati matricola
  ms.Matricola,
  ms.DataImmatricolazione,
  cl.NomeCorsoLaurea,

  -- esami svolti
  ins.NomeInsegnamento as EsameInsegnamento,
  vf.DataVerifica as DataEsame,
  vf.Voto as VotoEsame,
  vf.Lode as Lode,
  vf.Validita as Valido,
  vf.AnnoAccademico as AAEsame,

  -- titolo di studi
  l.Titolo as TitoloLaurea,
  l.DataLaurea,
  l.Voto as VotoLaurea,
  l.Lode as LodeLaurea,
  l.AnnoAccademico as AALaurea,

  -- iscrizioni
  i.AnnoAccademico as AAIscrizione,
  i.DataIscrizione,
  i.ProgressivoAnno,
  i.Tipo as TipoIscrizione

from studente s
-- join base
left join comune cr on s.IdResidenza = cr.IdComune
left join comune cd on s.IdDomicilio = cd.IdComune
left join matricolastudente ms on s.IdStudente = ms.IdStudente
left join corsolaurea cl on ms.IdCorsoLaurea = cl.IdCorsoLaurea
-- join per esami
left join verifichefinali vf on ms.Matricola = vf.Matricola
left join insegnamento ins on vf.IdInsegnamento = ins.IdInsegnamento

-- laurea
left join laurea l on ms.Matricola = l.Matricola

-- iscrizioni
left join iscrizione i on ms.Matricola = i.Matricola

order by s.Cognome, s.Nome, ms.Matricola, vf.DataVerifica, i.AnnoAccademico;


