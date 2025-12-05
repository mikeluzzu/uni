/* 3) Vogliamo conoscere l’elenco completo, in ordine alfabetico, dei docenti dell’università.
*/

select 
  IdDocente as Id,
  CodiceFiscale as CF,
  concat(Nome, ' ', Cognome) as Docente,
  Tipo

from docente

order by Nome, Cognome








