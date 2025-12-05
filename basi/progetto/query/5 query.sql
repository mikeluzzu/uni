-- 5) Per ogni docente, vogliamo conoscere l’elenco delle edizioni degli insegnamenti con la lista dei collaboratori.

select
  -- seleziono le colonne che mi interessano
  concat(d.Nome, ' ', d.Cognome) as Docente,
  d.Tipo,
  i.NomeInsegnamento
  
from docente d
-- join per prendere l'edizione insegnamento
left join edizioneinsegnamento e on d.IdDocente = e.IdEdizioneInsegnamento
-- join per trovare il nome dell insegnamento
left join insegnamento i on d.IdDocente = i.IdInsegnamento

where d.Tipo = 'Collaboratore'








