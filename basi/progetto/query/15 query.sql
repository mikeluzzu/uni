-- Per ogni anno accademico vogliamo conoscere il numero totale di studenti italiani immatricolati con comune di residenza.

select
  year(ms.DataImmatricolazione) as AnnoAccademico,
  count(*) as TotaleStudentiItaliani

from
    matricolastudente ms
    inner join studente s on ms.IdStudente = s.IdStudente

where s.Straniero = 0 and s.IdResidenza is not null

group by year(ms.DataImmatricolazione)
order by AnnoAccademico;







