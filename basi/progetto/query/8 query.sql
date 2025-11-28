-- 8) Elenco dei titoli di studi (con livello, voto, data, titolo della tesi, studente, relatori e controrelatori) 
-- per le quali nel titolo della tesi è contenuta una data sottostringa.

select
  l.Voto,
  l.DataLaurea,
  l.Titolo as TitoloTesi,
  l.AnnoAccademico,

  ms.Matricola,
  s.Nome as NomeStudente,
  s.Cognome as CognomeStudente,
  cl.NomeCorsoLaurea,

  dr.Nome as NomeRelatore,
  dr.Cognome as CognomeRelatore,

  dc.Nome as NomeControRelatore,
  dc.Cognome as CognomeControRelatore

from laurea l

inner join matricolastudente ms on l.Matricola = ms.Matricola
inner join studente s on ms.IdStudente = s.IdStudente
left join corsolaurea cl on ms.IdCorsoLaurea = cl.IdCorsoLaurea

left join relatore rel on l.Matricola = rel.Matricola
left join docente dr on rel.IdDocente = dr.IdDocente

left join docente dc on l.IdControRelatore = dc.IdDocente

where l.Titolo like '%Analisi%'
order by l.DataLaurea desc;









