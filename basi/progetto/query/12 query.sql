-- Per ogni anno solare vogliamo conoscere il numero di studenti laureati e voto medio. 

select
  year(l.DataLaurea) as AnnoSolare,
  count(*) as LaureatiTotali,
  avg(l.Voto) as VotoMedio

from laurea l

group by year(l.DataLaurea)

  