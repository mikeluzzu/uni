-- STEP 1: Comuni (2-3 comuni)
INSERT INTO comune (NomeComune, NumeroAbitanti) VALUES
('Rende', 1400),
('Lamezia', 12800),
('Feroleto Antico', 2000);

-- STEP 2: Dipartimenti (2)
INSERT INTO dipartimento (NomeDipartimento) VALUES
('Dipartimento di Informatica'),
('Dipartimento di Matematica');

-- STEP 3: Corsi di Laurea (2)
INSERT INTO corsolaurea (NomeCorsoLaurea, IdDipartimento) VALUES
('Informatica', 1),
('Matematica', 2);

-- STEP 4: Studenti (3 studenti con casi diversi)
INSERT INTO studente (CodiceFiscale, Nome, Cognome, DataNascita, Sesso, Straniero, IdResidenza, IdDomicilio) VALUES
('RSSMRA90A01F205Z', 'Mario', 'Rossi', '1990-01-01', 'M', 0, 1, 1),
('VRDLGI92B15H501X', 'Luigi', 'Verdi', '1992-02-15', 'M', 0, 2, 2),
('BNCLRA95C20D612Y', 'Laura', 'Bianchi', '1995-03-20', 'F', 0, 1, 3);

-- STEP 5: Matricole
INSERT INTO matricolastudente (DataImmatricolazione, IdStudente, IdCorsoLaurea) VALUES
('2020-09-01', 1, 1),  -- Mario in Informatica
('2021-09-01', 2, 1),  -- Luigi in Informatica
('2020-09-01', 3, 2);  -- Laura in Matematica

-- STEP 6: Iscrizioni (almeno 2 anni per uno studente)
INSERT INTO iscrizione (Matricola, AnnoAccademico, ProgressivoAnno, DataIscrizione, Tipo) VALUES
(1, 2020, 1, '2020-09-01', 'Regolare'),
(1, 2021, 2, '2021-09-15', 'Regolare'),
(1, 2022, 3, '2022-09-10', 'Regolare'),
(2, 2021, 1, '2021-09-01', 'Regolare'),
(2, 2022, 2, '2022-09-15', 'Fuori Corso'),
(3, 2020, 1, '2020-09-01', 'Regolare'),
(3, 2021, 2, '2021-09-15', 'Regolare');

-- STEP 7: Insegnamenti (3-4 insegnamenti)
INSERT INTO insegnamento (NomeInsegnamento) VALUES
('Basi di Dati'),
('Algoritmi e Strutture Dati'),
('Analisi Matematica I'),
('Fisica I');

-- STEP 8: Insegnamenti per corso
INSERT INTO insegnamentoindirizzo (IdInsegnamento, IdCorsoLaurea, Crediti, Anno, Semestre) VALUES
(1, 1, 9, 2, 1),  -- Basi di Dati per Informatica
(2, 1, 9, 1, 2),  -- Algoritmi per Informatica
(3, 1, 6, 1, 1),  -- Analisi per Informatica
(3, 2, 12, 1, 1), -- Analisi per Matematica
(4, 2, 9, 1, 2);  -- Fisica per Matematica

-- STEP 9: Docenti (2-3 docenti)
INSERT INTO docente (CodiceFiscale, Nome, Cognome, Tipo) VALUES
('BNCGNN70D15F205W', 'Giovanni', 'Bianchi', 'Docente di ruolo'),
('MRTFNC65M20H501V', 'Francesca', 'Mariani', 'Docente di ruolo'),
('RSSLCA75S10D612T', 'Luca', 'Rossetti', 'Collaboratore');

-- STEP 10: Edizioni insegnamento
INSERT INTO edizioneinsegnamento (IdInsegnamento, IdCorsoLaurea, AnnoAccademico, Semestre, DataInizio, DataFine) VALUES
(1, 1, 2021, '1', '2021-09-20', '2021-12-20'),  -- Basi di Dati 2021
(2, 1, 2020, '2', '2021-02-15', '2021-06-15'),  -- Algoritmi 2020
(3, 1, 2020, '1', '2020-09-20', '2020-12-20');  -- Analisi 2020

-- STEP 11: Docenze
INSERT INTO docenza (IdDocente, IdEdizioneInsegnamento) VALUES
(1, 1),  -- Bianchi insegna Basi di Dati
(2, 2),  -- Mariani insegna Algoritmi
(2, 3);  -- Mariani insegna Analisi

-- STEP 12: Verifiche/Esami (alcuni esami per ogni studente)
INSERT INTO verifichefinali (Matricola, IdInsegnamento, IdCorsoLaurea, DataVerifica, Voto, Lode, Validita, AnnoAccademico) VALUES
-- Mario Rossi
(1, 2, 1, '2021-06-20', 28, 0, 1, 2020),  -- Algoritmi
(1, 3, 1, '2021-01-15', 30, 1, 1, 2020),  -- Analisi
(1, 1, 1, '2022-01-20', 27, 0, 1, 2021),  -- Basi di Dati
-- Luigi Verdi
(2, 2, 1, '2022-06-25', 24, 0, 1, 2021),  -- Algoritmi
(2, 3, 1, '2022-01-18', 26, 0, 1, 2021),  -- Analisi
-- Laura Bianchi
(3, 3, 2, '2021-01-22', 30, 1, 1, 2020),  -- Analisi
(3, 4, 2, '2021-06-28', 29, 0, 1, 2020);  -- Fisica

-- STEP 13: Relatori (per chi si laureerà)
INSERT INTO relatore (IdDocente, Matricola) VALUES
(1, 1),  -- Bianchi relatore di Mario
(2, 3);  -- Mariani relatrice di Laura

-- STEP 14: Laurea (solo uno studente laureato)
INSERT INTO laurea (Matricola, AnnoAccademico, Voto, Lode, DataLaurea, Titolo, IdControRelatore) VALUES
(3, 2023, 110, 1, '2023-07-15', 'Analisi delle Serie di Fourier', 3);








