create table if not exists report(
    IdReport int(10) primary key,
    DataGenerazione datetime,
    AnnoAccademico year,
    NomeInsegnamento varchar(100),
    NomeDocente varchar(100),
    CognomeDocente varchar(100),
    Voti_18_24 int ,
    Voti_25_27 int,
    Voti_28_30 int ,
    Lodi int default 0,
)