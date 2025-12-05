-- 9) Per ogni studente e per ogni anno solare vogliamo conoscere il numero di esami sostenuti, quelli superati ed il voto medio.

select

  concat(s.Nome, ' ', s.Cognome) as Studente,
  ms.Matricola,
  year(vf.DataVerifica) as AnnoSolare,
  count(vf.DataVerifica) as EsamiSostenuti,
  count(case when vf.Validita = 1 then 1 end) as EsamiSuperati,
  avg(case when vf.Validita = 1 then vf.Voto end) as VotoMedio

from studente s

left join matricolastudente ms on s.IdStudente = ms.IdStudente
left join verifichefinali vf on ms.Matricola = vf.Matricola


group by s.IdStudente, ms.Matricola, year(vf.DataVerifica)
order by s.Cognome, s.Nome;




