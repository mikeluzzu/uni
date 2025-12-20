-- Comuni (verifica che siano inseriti)
INSERT INTO comune (NomeComune, NumeroAbitanti) VALUES
('Rende', 1400),
('Lamezia Terme', 12800),
('Cosenza', 2600)
;

-- Dipartimenti
INSERT INTO dipartimento (NomeDipartimento) VALUES
('Dipartimento di Matematica e Informatica'),
('Dipartimento di Ingegneria Informatica ed Elettronica'),
('Dipartimento di Studi Umanistici'),
('Dipartimento di Scienze della Salute')
;

-- Corsi di Laurea (con IdDipartimento corretto)
INSERT INTO corsolaurea (NomeCorsoLaurea, IdDipartimento) VALUES
('Informatica', 1),
('Matematica', 1),
('Ingegneria Informatica', 2),
('Ingegneria Elettronica', 2),
('Storia', 3),
('Lettere', 3),
('Medicina e Chirurgia', 4),
('Infermieristica', 4)
;

-- Studenti (SOLO con IdResidenza e IdDomicilio da 1 a 3, o NULL)
INSERT INTO studente (CodiceFiscale, Nome, Cognome, DataNascita, Sesso, Straniero, IdResidenza, IdDomicilio) VALUES
('RSSMRA95A01H501Z', 'Mario', 'Rossi', '1995-01-01', 'M', 0, 1, 1),
('VRDLGI96B15H501W', 'Luigi', 'Verdi', '1996-02-15', 'M', 0, 2, 2),
('BNCMRA97C20H501X', 'Maria', 'Bianchi', '1997-03-20', 'F', 1, 3, 3),
('GLLFNC98D10H501Y', 'Francesca', 'Galli', '1998-04-10', 'F', 0, 1, 1),
('RCCGVN99E25H501V', 'Giovanni', 'Ricci', '1999-05-25', 'M', 1, 2, 1),
('FRNLRA00F12H501U', 'Laura', 'Ferrini', '2000-06-12', 'F', 0, 1, 2),
('CSTPLA01G08H501T', 'Paolo', 'Costa', '2001-07-08', 'M', 1, 1, 3),
('MNTSMN02H18H501S', 'Simone', 'Monti', '2002-08-18', 'M', 0, 3, 3)
;

-- Matricole
INSERT INTO matricolastudente (DataImmatricolazione, IdStudente, IdCorsoLaurea) VALUES
('2020-09-15', 1, 1),
('2020-09-15', 2, 2),
('2021-09-20', 3, 1),
('2021-09-20', 4, 3),
('2022-09-18', 5, 1),
('2022-09-18', 6, 7),
('2023-09-16', 7, 5),
('2023-09-16', 8, 1)
;

-- Iscrizioni 
INSERT INTO iscrizione (Matricola, AnnoAccademico, ProgressivoAnno, DataIscrizione, Tipo) VALUES
(1, 2020, 1, '2020-09-15', 'Regolare'),
(1, 2021, 2, '2021-09-10', 'Regolare'),
(1, 2022, 3, '2022-09-12', 'Regolare'),
(2, 2020, 1, '2020-09-15', 'Regolare'),
(2, 2021, 2, '2021-09-10', 'Regolare'),
(2, 2022, 3, '2022-09-12', 'Regolare'),
(3, 2021, 1, '2021-09-20', 'Regolare'),
(3, 2022, 2, '2022-09-18', 'Regolare'),
(3, 2023, 3, '2023-09-15', 'Regolare'),
(4, 2021, 1, '2021-09-20', 'Regolare'),
(4, 2022, 2, '2022-09-18', 'Regolare'),
(5, 2022, 1, '2022-09-18', 'Regolare'),
(5, 2023, 2, '2023-09-15', 'Regolare'),
(6, 2022, 1, '2022-09-18', 'Regolare'),
(6, 2023, 2, '2023-09-15', 'Fuori Corso'),
(7, 2023, 1, '2023-09-16', 'Regolare'),
(8, 2023, 1, '2023-09-16', 'Regolare')
;

-- Insegnamenti
INSERT INTO insegnamento (NomeInsegnamento) VALUES
('Programmazione I'),
('Basi di Dati'),
('Algoritmi e Strutture Dati'),
('Analisi Matematica I'),
('Fisica I'),
('Ingegneria del Software'),
('Reti di Calcolatori'),
('Anatomia Umana'),
('Storia Medievale'),
('Letteratura Italiana')
;

-- Insegnamenti per corso
INSERT INTO insegnamentoindirizzo (IdInsegnamento, IdCorsoLaurea, Crediti, Anno, Semestre) VALUES
(1, 1, 9, 1, 1),
(2, 1, 9, 2, 1),
(3, 1, 12, 2, 2),
(4, 1, 9, 1, 1),
(5, 1, 6, 1, 2),
(1, 3, 9, 1, 1),
(6, 3, 12, 3, 1),
(7, 3, 9, 3, 2),
(4, 2, 12, 1, 1),
(8, 7, 15, 1, 1),
(9, 5, 12, 1, 1),
(10, 6, 9, 1, 1)
;

-- Docenti
INSERT INTO docente (CodiceFiscale, Nome, Cognome, Tipo) VALUES
('BRTGVN70A01H501A', 'Giovanni', 'Berti', 'Docente di ruolo'),
('MRLFNC68B12H501B', 'Francesca', 'Morelli', 'Docente di ruolo'),
('CNTPLA72C25H501C', 'Paolo', 'Conti', 'Docente di ruolo'),
('SRALNA75D08H501D', 'Anna', 'Serra', 'Collaboratore'),
('FBBMRC69E15H501E', 'Marco', 'Fabbri', 'Docente di ruolo'),
('GRSLCU73F22H501F', 'Luca', 'Grassi', 'Docente di ruolo'),
('PLLMRA71G10H501G', 'Marta', 'Pulli', 'Collaboratore')
;

-- Edizioni insegnamento
INSERT INTO edizioneinsegnamento (IdInsegnamento, IdCorsoLaurea, AnnoAccademico, Semestre, DataInizio, DataFine) VALUES
(1, 1, 2020, '1', '2020-10-01', '2021-01-31'),
(4, 1, 2020, '1', '2020-10-01', '2021-01-31'),
(5, 1, 2021, '2', '2021-03-01', '2021-06-30'),
(2, 1, 2021, '1', '2021-10-01', '2022-01-31'),
(3, 1, 2022, '2', '2022-03-01', '2022-06-30'),
(1, 3, 2021, '1', '2021-10-01', '2022-01-31'),
(6, 3, 2023, '1', '2023-10-01', '2024-01-31'),
(8, 7, 2022, '1', '2022-10-01', '2023-01-31'),
(9, 5, 2023, '1', '2023-10-01', '2024-01-31'),
(4, 2, 2020, '1', '2020-10-01', '2021-01-31')
;

-- Docenze
INSERT INTO docenza (IdDocente, IdEdizioneInsegnamento) VALUES
(1, 1),
(2, 2),
(3, 3),
(2, 4),
(1, 5),
(4, 6),
(5, 7),
(6, 8),
(7, 9),
(2, 10)
;

-- Verifiche/Esami 
INSERT INTO verifichefinali (Matricola, IdInsegnamento, IdCorsoLaurea, DataVerifica, Voto, Lode, Validita, AnnoAccademico) VALUES
(1, 1, 1, '2021-02-15', 28, 0, 1, 2020),
(1, 4, 1, '2021-02-20', 30, 1, 1, 2020),
(1, 5, 1, '2021-07-10', 25, 0, 1, 2020),
(1, 2, 1, '2022-02-12', 27, 0, 1, 2021),
(1, 3, 1, '2022-07-05', 30, 0, 1, 2021),
(2, 4, 2, '2021-02-18', 24, 0, 1, 2020),
(3, 1, 1, '2022-02-10', 26, 0, 1, 2021),
(3, 4, 1, '2022-02-25', 29, 0, 1, 2021),
(3, 2, 1, '2023-02-15', 30, 1, 1, 2022),
(4, 1, 3, '2022-02-14', 27, 0, 1, 2021),
(5, 1, 1, '2023-02-20', 25, 0, 1, 2022),
(6, 8, 7, '2023-02-10', 22, 0, 1, 2022),
(7, 9, 5, '2024-02-05', 28, 0, 1, 2023),
(8, 1, 1, '2024-02-08', 30, 0, 1, 2023)
;

-- Relatori 
INSERT INTO relatore (IdDocente, Matricola) VALUES
(1, 1),
(2, 2),
(1, 3)
;

-- Laurea 
INSERT INTO laurea (Matricola, AnnoAccademico, Voto, Lode, DataLaurea, Titolo, IdControRelatore) VALUES
(1, 2023, 110, 1, '2023-07-20', 'Ottimizzazione algoritmi di ricerca distribuita', 2),
(2, 2023, 95, 0, '2023-10-15', 'Analisi numerica di sistemi dinamici', 3)
;