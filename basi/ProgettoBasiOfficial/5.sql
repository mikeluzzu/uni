-- 5) Per ogni docente, vogliamo conoscere l’elenco delle edizioni degli insegnamenti con la lista dei collaboratori.

select
  concat(d.Nome, ' ', d.Cognome) as Docente,
  d.Tipo,
  i.NomeInsegnamento as Corso
  
from docente d
left join edizioneinsegnamento e on d.IdDocente = e.IdEdizioneInsegnamento
left join insegnamento i on d.IdDocente = i.IdInsegnamento

where d.Tipo = 'Collaboratore'








