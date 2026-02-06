/*restituire il nome e il dipartimento dei docenti che hanno insegnato il maggior numero
di crediti */

select D.Nome, D.Dipartimento
from Docente D
join Materia M on D.Nome = M.Docente
group by D.Nome, D.Dipartimento
having sum(M.Crediti) = (
    select max(TotaleCrediti)
    from (
        select sum(M2.Crediti) as TotaleCrediti -- somma per ogni docente
        from Docente D2
        join Materia M2 on D2.Nome = M2.Docente
        group by D2.Nome
    ) as CreditiPerDocente
)

/*coppie (aula,data) in cui si sono tenuti il maggior numero di esami di 
crediti >= 6 */

select E.Aula, E.Data
from Esame E
join Materia M on E.Materia = M.Codice
where M.Crediti >= 6
group by E.Aula, E.Data
having count(*) = (
    select max(NumEsami)
    from (
        select E2.Aula, E2.Data, count(*) as NumEsami
        from Esame E2
        join Materia M2 on E2.Materia = M2.Codice
        where M2.Crediti >= 6
        group by E2.Aula, E2.Data
    ) as EsamiPerAulaData
)
