/*
Scrivere una query SQL che restituisca la data di nascita dei clienti che hanno
acquistato dal maggior numero di vendor diversi.
*/

select C.DataNascita
from Cliente C
join Acquisto A on C.CF = A.Cliente
join Modulo M on A.Modulo = M.Codice

group by C.DataNascita
having (distinct count)