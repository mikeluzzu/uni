/* 1) Vogliamo conoscere l’elenco completo, in ordine alfabetico, degli studenti dell’università 
con le relative informazioni anagrafiche estese. Gli studenti devono essere inoltre raggruppati
in studenti italiani e studenti stranieri.
*/

select
  s.CodiceFiscale,
  s.Cognome,
  s.Nome,
  s.DataNascita,
  s.Sesso,
  s.Straniero,
  cr.NomeComune as ComuneResidenza,
  cd.NomeComune as ComuneDomicilio
  
from studente s
left join comune cr on s.IdResidenza = cr.IdComune
inner join comune cd on s.IdDomicilio = cd.IdComune

order by
  s.Straniero asc,
  s.Cognome asc,
  s.Nome asc;