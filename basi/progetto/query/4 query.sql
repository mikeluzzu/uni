-- 4) Per ogni docente vogliamo riportare le edizioni degli insegnamenti svolti (con periodo anno accademico)

select
  -- seleziono le colonne che mi interessano
  concat(d.Nome, ' ', d.Cognome) as Docente,   
  i.NomeInsegnamento,
  e.AnnoAccademico

from docente d
-- join per prendere l'edizione insegnamento
left join edizioneinsegnamento e on d.IdDocente = e.IdEdizioneInsegnamento
-- join per trovare il nome dell insegnamento
left join insegnamento i on d.IdDocente = i.IdInsegnamento








