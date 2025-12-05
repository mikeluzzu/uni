-- Per ogni studente e per ogni anno accademico vogliamo conoscere il numero di esami superati,
-- voto medio e numero di crediti acquisiti.

select

  concat(s.Nome, ' ', s.Cognome) as Studente,
  ms.Matricola,
  year(vf.AnnoAccademico) as AnnoAccademico,
  sum(insInd.Crediti) as CreditiAcquisiti,
  count(case when vf.Validita = 1 then 1 end) as EsamiSuperati,
  avg(case when vf.Validita = 1 then vf.Voto end) as VotoMedio

from studente s

left join matricolastudente ms on s.IdStudente = ms.IdStudente
left join verifichefinali vf on ms.Matricola = vf.Matricola
left join insegnamentoindirizzo insInd on vf.IdInsegnamento = insInd.IdInsegnamento

group by s.IdStudente, ms.Matricola, year(vf.AnnoAccademico)
order by s.Cognome, s.Nome, year(vf.AnnoAccademico);






