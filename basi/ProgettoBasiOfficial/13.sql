-- Per ogni anno solare vogliamo conoscere il numero di studenti iscritti regolarmente, non regolarmente e fuori corso

select
  year(isc.DataIscrizione) as AnnoSolare,
  isc.Tipo,
  count(*) as TotaleIscrizioni

from iscrizione isc
  group by
    year(isc.DataIscrizione),
    isc.Tipo
  order by
    AnnoSolare,
    isc.Tipo;