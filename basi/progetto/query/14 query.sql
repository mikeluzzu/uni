-- Il docente che ha svolto il maggior numero di esami in un dato anno accademico.

select
  concat(d.Nome, ' ', d.Cognome) as Docente,
  count(*) as NumeroEsami

from verifichefinali vf

  inner join edizioneinsegnamento ei
      on vf.IdInsegnamento = ei.IdInsegnamento
      and vf.IdCorsoLaurea = ei.IdCorsoLaurea
      and vf.AnnoAccademico = ei.AnnoAccademico
  inner join docenza doc
      on ei.IdEdizioneInsegnamento = doc.IdEdizioneInsegnamento
  inner join docente d
      on doc.IdDocente = d.IdDocente

where vf.AnnoAccademico = 2020

group by d.IdDocente, d.Nome, d.Cognome
order by NumeroEsami desc
limit 1;





