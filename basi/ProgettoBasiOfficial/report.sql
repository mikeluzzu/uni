create event if not exists ReportTrimestrale
on schedule every 3 month
starts current_timestamp
do begin
    insert into report(AnnoAccademico, NomeInsegnamento, NomeDocente, CognomeDocente, 
    v18_24, v25_27, v28_30, Lodi)
    
    --  seleziono i valori da inserire 
    select VF.AnnoAccademico,
    I.NomeInsegnamento,
    D.Nome,
    D.Cognome,
    sum(case when VF.Voto between 18 and 24 then 1 else 0 end),
    sum(case when VF.Voto between 25 and 27 then 1 esle 0 end),
    sum(case when VF.Voto between 28 and 30 and (VD.Lode = 0 or VF.Lode is null ) then 1 else 0 end),
    sum(case when VF.Voto == 30 and VF.Lode == 1 then 1 else 0)

    from verifichefinali VF
    join insegnamento I on VF.IdInsegnamento = I.IdInsegnamento
    join edizioneinsegnamento EI on EI.IdInsegnamento = VF.IdInsegnamento and EI.AnnoAccademico = VF.AnnoAccademico
    join docenza DOC on DOC DOC.IdEdizioneInsegnamento = EI.IdEdizioneInsegnamento
    join docente D on D.IdDocente = DOC.IdDocente

    where 
    VF.Validita = 1 -- lo prendo solo se l esame e' valido 
    and
    group by VF.AnnoAccademico, I.IdInsegnamento, D.IdDocente

