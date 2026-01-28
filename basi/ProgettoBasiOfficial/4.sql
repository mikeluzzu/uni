-- 4) Per ogni docente vogliamo riportare le edizioni degli insegnamenti svolti (con periodo anno accademico)

select
  -- seleziono le colonne che mi interessano
  concat(d.Nome, ' ', d.Cognome) as Docente,   
  i.NomeInsegnamento as Corso,
  e.AnnoAccademico

from docente d
-- prendo  l'edizione insegnamento
left join edizioneinsegnamento e on d.IdDocente = e.IdEdizioneInsegnamento
-- prendo il nome dell insegnamento
left join insegnamento i on d.IdDocente = i.IdInsegnamento








