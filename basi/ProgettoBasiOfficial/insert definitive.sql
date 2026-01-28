-- ==========================================
-- INSERT COMUNI
-- ==========================================
INSERT INTO `comune` (`NomeComune`, `NumeroAbitanti`) VALUES
('Rende', 180),
('Lamezia Terme', 140),
('Cosenza', 100),
('Crotone', 120),
('Catanzaro', 80),
('Reggio Calabria', 270);

-- ==========================================
-- INSERT DIPARTIMENTI
-- ==========================================
INSERT INTO `dipartimento` (`NomeDipartimento`) VALUES
('Dipartimento di Matematica e Informatica'),
('Dipartimento di Ingegneria Informatica ed Elettronica'),
('Dipartimento di Studi Umanistici'),
('Dipartimento di Scienze della Salute');

-- ==========================================
-- INSERT CORSI DI LAUREA
-- ==========================================
INSERT INTO `corsolaurea` (`NomeCorsoLaurea`, `IdDipartimento`) VALUES
('Informatica', 1),
('Matematica', 1),
('Ingegneria Informatica', 2),
('Ingegneria Elettronica', 2),
('Storia', 3),
('Lettere', 3),
('Medicina e Chirurgia', 4),
('Infermieristica', 4);

-- ==========================================
-- INSERT STUDENTI (15 studenti)
-- ==========================================
INSERT INTO `studente` (`CodiceFiscale`, `Nome`, `Cognome`, `DataNascita`, `Sesso`, `Straniero`, `IdResidenza`, `IdDomicilio`) VALUES
('RSSMRA00A01H501Z', 'Michele', 'Molinaro', '2000-01-01', 'M', 0, 1, 1),
('VRDGLL99B42F839K', 'Giulia', 'Verdi', '1999-02-02', 'F', 0, 3, 3),
('BNCLCU01C15D086M', 'Luca', 'Bianchi', '2001-03-15', 'M', 0, 2, 2),
('FRNMRT98D50H224L', 'Marta', 'Ferrari', '1998-04-10', 'F', 0, 5, 5),
('CNTGVN02E20F839A', 'Giovanni', 'Conti', '2002-05-20', 'M', 0, 3, 1),
('GRCLRA00F55H501B', 'Laura', 'Greco', '2000-06-15', 'F', 0, 1, 1),
('MRNSFN01G12D086C', 'Stefano', 'Marino', '2001-07-12', 'M', 0, 2, 3),
('CLMSLV99H48F839D', 'Silvia', 'Colombo', '1999-08-08', 'F', 0, 3, 3),
('SMITHJHN00A01Z40', 'John', 'Smith', '2000-01-01', 'M', 1, NULL, 1),
('MLLRANA01B42Z100', 'Anna', 'Mueller', '2001-02-02', 'F', 1, NULL, 2),
('KHNMHMD02C15Z200', 'Mohamed', 'Khan', '2002-03-15', 'M', 1, NULL, 5),
('PTRSOFA99D50Z300', 'Sofia', 'Petrov', '1999-04-10', 'F', 1, NULL, 6),
('RCCFRN00E20H501I', 'Francesco', 'Molinaro', '2002-05-20', 'M', 0, 1, 2),
('BRNGRT01F55D086J', 'Margherita', 'Bruno', '2001-06-15', 'F', 0, 2, 2),
('GLLMRC98G12F839K', 'Marco', 'Gallo', '1998-07-12', 'M', 0, 3, 4);

-- ==========================================
-- INSERT MATRICOLE STUDENTE
-- ==========================================
INSERT INTO `matricolastudente` (`DataImmatricolazione`, `IdStudente`, `IdCorsoLaurea`) VALUES
('2021-09-15', 1, 1),  -- Michele Molinaro - Informatica
('2021-09-15', 2, 2),  -- Giulia Verdi - Matematica
('2022-09-20', 3, 3),  -- Luca Bianchi - Ing. Informatica
('2020-09-10', 4, 4),  -- Marta Ferrari - Ing. Elettronica
('2023-09-18', 5, 5),  -- Giovanni Conti - Storia
('2021-09-15', 6, 6),  -- Laura Greco - Lettere
('2022-09-20', 7, 7),  -- Stefano Marino - Medicina
('2021-09-15', 8, 1),  -- Silvia Colombo - Informatica
('2021-09-15', 9, 3),  -- John Smith - Ing. Informatica
('2022-09-20', 10, 2), -- Anna Mueller - Matematica
('2023-09-18', 11, 8), -- Mohamed Khan - Infermieristica
('2020-09-10', 12, 6), -- Sofia Petrov - Lettere
('2021-09-15', 13, 1), -- Francesco Molinaro - Informatica
('2022-09-20', 14, 4), -- Margherita Bruno - Ing. Elettronica
('2020-09-10', 15, 7); -- Marco Gallo - Medicina

-- ==========================================
-- INSERT ISCRIZIONI
-- ==========================================
-- Studenti del 2021 (4° anno o laureandi)
INSERT INTO `iscrizione` (`Matricola`, `AnnoAccademico`, `ProgressivoAnno`, `DataIscrizione`, `Tipo`) VALUES
(1, 2021, 1, '2021-09-15', 'Regolare'),
(1, 2022, 2, '2022-09-15', 'Regolare'),
(1, 2023, 3, '2023-09-15', 'Regolare'),
(1, 2024, 4, '2024-09-15', 'Fuori Corso'),

(2, 2021, 1, '2021-09-15', 'Regolare'),
(2, 2022, 2, '2022-09-15', 'Regolare'),
(2, 2023, 3, '2023-09-15', 'Regolare'),

(6, 2021, 1, '2021-09-15', 'Regolare'),
(6, 2022, 2, '2022-09-15', 'Regolare'),
(6, 2023, 3, '2023-09-15', 'Regolare'),
(6, 2024, 4, '2024-09-15', 'Fuori Corso'),

(8, 2021, 1, '2021-09-15', 'Regolare'),
(8, 2022, 2, '2022-09-15', 'Regolare'),
(8, 2023, 3, '2023-09-15', 'Regolare'),

(9, 2021, 1, '2021-09-15', 'Regolare'),
(9, 2022, 2, '2022-09-15', 'Regolare'),
(9, 2023, 3, '2023-09-15', 'Regolare'),

(13, 2021, 1, '2021-09-15', 'Regolare'),
(13, 2022, 2, '2022-09-15', 'Regolare'),
(13, 2023, 3, '2023-09-15', 'Regolare'),
(13, 2024, 4, '2024-09-15', 'Fuori Corso'),

-- Studenti del 2020 (5° anno o laureandi/laureati)
(4, 2020, 1, '2020-09-10', 'Regolare'),
(4, 2021, 2, '2021-09-10', 'Regolare'),
(4, 2022, 3, '2022-09-10', 'Regolare'),

(12, 2020, 1, '2020-09-10', 'Regolare'),
(12, 2021, 2, '2021-09-10', 'Regolare'),
(12, 2022, 3, '2022-09-10', 'Regolare'),
(12, 2023, 4, '2023-09-10', 'Fuori Corso'),

(15, 2020, 1, '2020-09-10', 'Regolare'),
(15, 2021, 2, '2021-09-10', 'Regolare'),
(15, 2022, 3, '2022-09-10', 'Regolare'),
(15, 2023, 4, '2023-09-10', 'Regolare'),
(15, 2024, 5, '2024-09-10', 'Regolare'),

-- Studenti del 2022 (3° anno)
(3, 2022, 1, '2022-09-20', 'Regolare'),
(3, 2023, 2, '2023-09-20', 'Regolare'),
(3, 2024, 3, '2024-09-20', 'Regolare'),

(7, 2022, 1, '2022-09-20', 'Regolare'),
(7, 2023, 2, '2023-09-20', 'Regolare'),
(7, 2024, 3, '2024-09-20', 'Regolare'),

(10, 2022, 1, '2022-09-20', 'Regolare'),
(10, 2023, 2, '2023-09-20', 'Regolare'),
(10, 2024, 3, '2024-09-20', 'Regolare'),

(14, 2022, 1, '2022-09-20', 'Regolare'),
(14, 2023, 2, '2023-09-20', 'Regolare'),
(14, 2024, 3, '2024-09-20', 'Regolare'),

-- Studenti del 2023 (2° anno)
(5, 2023, 1, '2023-09-18', 'Regolare'),
(5, 2024, 2, '2024-09-18', 'Regolare'),

(11, 2023, 1, '2023-09-18', 'Regolare'),
(11, 2024, 2, '2024-09-18', 'Regolare');

-- ==========================================
-- INSERT INSEGNAMENTI
-- ==========================================
-- Informatica
INSERT INTO `insegnamento` (`NomeInsegnamento`) VALUES
('Programmazione I'),
('Programmazione II'),
('Basi di Dati'),
('Algoritmi e Strutture Dati'),
('Reti di Calcolatori'),

-- Matematica
('Analisi Matematica I'),
('Analisi Matematica II'),
('Algebra Lineare'),
('Geometria'),

-- Ingegneria Informatica
('Fondamenti di Informatica'),
('Sistemi Operativi'),
('Ingegneria del Software'),

-- Ingegneria Elettronica
('Elettrotecnica'),
('Elettronica Analogica'),
('Elettronica Digitale'),

-- Storia
('Storia Antica'),
('Storia Medievale'),
('Storia Moderna'),

-- Lettere
('Letteratura Italiana'),
('Filologia Romanza'),
('Linguistica Generale'),

-- Medicina
('Anatomia Umana'),
('Fisiologia'),
('Patologia Generale'),

-- Infermieristica
('Infermieristica Generale'),
('Infermieristica Clinica');

-- ==========================================
-- INSERT INSEGNAMENTO INDIRIZZO
-- ==========================================
-- Informatica (IdCorsoLaurea = 1)
INSERT INTO `insegnamentoindirizzo` (`IdInsegnamento`, `IdCorsoLaurea`, `Crediti`, `Anno`, `Semestre`) VALUES
(1, 1, 9, 1, 1),
(2, 1, 9, 1, 2),
(3, 1, 9, 2, 1),
(4, 1, 12, 2, 2),
(5, 1, 6, 3, 1),

-- Matematica (IdCorsoLaurea = 2)
(6, 2, 12, 1, 1),
(7, 2, 12, 1, 2),
(8, 2, 9, 2, 1),
(9, 2, 9, 2, 2),

-- Ingegneria Informatica (IdCorsoLaurea = 3)
(10, 3, 9, 1, 1),
(11, 3, 9, 2, 1),
(12, 3, 12, 2, 2),
(6, 3, 12, 1, 1),

-- Ingegneria Elettronica (IdCorsoLaurea = 4)
(13, 4, 9, 1, 1),
(14, 4, 9, 2, 1),
(15, 4, 9, 2, 2),
(6, 4, 12, 1, 1),

-- Storia (IdCorsoLaurea = 5)
(16, 5, 12, 1, 1),
(17, 5, 12, 2, 1),
(18, 5, 12, 3, 1),

-- Lettere (IdCorsoLaurea = 6)
(19, 6, 12, 1, 1),
(20, 6, 9, 2, 1),
(21, 6, 9, 2, 2),

-- Medicina (IdCorsoLaurea = 7)
(22, 7, 15, 1, 1),
(23, 7, 12, 1, 2),
(24, 7, 12, 2, 1),

-- Infermieristica (IdCorsoLaurea = 8)
(25, 8, 12, 1, 1),
(26, 8, 12, 2, 1);

-- ==========================================
-- INSERT DOCENTI
-- ==========================================
INSERT INTO `docente` (`CodiceFiscale`, `Nome`, `Cognome`, `Tipo`) VALUES
('RSSLGI65A01H501A', 'Luigi', 'Russo', 'Docente di ruolo'),
('FRRGPP70B15F839B', 'Giuseppe', 'Ferri', 'Docente di ruolo'),
('GRCPLA68C20D086C', 'Paola', 'Greco', 'Docente di ruolo'),
('MRTANT72D10H224D', 'Antonio', 'Martini', 'Docente di ruolo'),
('CLMFRN75E05F839E', 'Francesca', 'Colombo', 'Collaboratore'),
('BNCCRL69F12H501F', 'Carlo', 'Bianchi', 'Docente di ruolo'),
('VRDMRA73G08D086G', 'Maria', 'Verdi', 'Collaboratore'),
('RSSNDR71H25F839H', 'Andrea', 'Rossi', 'Docente di ruolo'),
('FRRELT76I18H224I', 'Elena', 'Ferrari', 'Collaboratore'),
('CNTRCR68J30H501J', 'Riccardo', 'Conti', 'Docente di ruolo');

-- ==========================================
-- INSERT EDIZIONI INSEGNAMENTO
-- ==========================================
INSERT INTO `edizioneinsegnamento` (`IdInsegnamento`, `IdCorsoLaurea`, `AnnoAccademico`, `Semestre`, `DataInizio`, `DataFine`) VALUES
-- Anno Accademico 2023/2024
(1, 1, 2023, '1', '2023-10-01', '2024-01-31'),
(2, 1, 2023, '2', '2024-03-01', '2024-06-30'),
(3, 1, 2023, '1', '2023-10-01', '2024-01-31'),
(4, 1, 2023, '2', '2024-03-01', '2024-06-30'),
(6, 2, 2023, '1', '2023-10-01', '2024-01-31'),
(7, 2, 2023, '2', '2024-03-01', '2024-06-30'),
(10, 3, 2023, '1', '2023-10-01', '2024-01-31'),
(11, 3, 2023, '1', '2023-10-01', '2024-01-31'),
(13, 4, 2023, '1', '2023-10-01', '2024-01-31'),
(14, 4, 2023, '1', '2023-10-01', '2024-01-31'),
(16, 5, 2023, '1', '2023-10-01', '2024-01-31'),
(19, 6, 2023, '1', '2023-10-01', '2024-01-31'),
(22, 7, 2023, '1', '2023-10-01', '2024-01-31'),
(23, 7, 2023, '2', '2024-03-01', '2024-06-30'),
(25, 8, 2023, '1', '2023-10-01', '2024-01-31'),

-- Anno Accademico 2024/2025
(1, 1, 2024, '1', '2024-10-01', '2025-01-31'),
(2, 1, 2024, '2', '2025-03-01', '2025-06-30'),
(3, 1, 2024, '1', '2024-10-01', '2025-01-31'),
(6, 2, 2024, '1', '2024-10-01', '2025-01-31'),
(10, 3, 2024, '1', '2024-10-01', '2025-01-31'),
(16, 5, 2024, '1', '2024-10-01', '2025-01-31');

-- ==========================================
-- INSERT DOCENZE
-- ==========================================
INSERT INTO `docenza` (`IdDocente`, `IdEdizioneInsegnamento`) VALUES
(1, 1),  -- Russo - Programmazione I
(1, 16), -- Russo - Programmazione I (2024)
(2, 2),  -- Ferri - Programmazione II
(2, 17), -- Ferri - Programmazione II (2024)
(3, 3),  -- Greco - Basi di Dati
(3, 18), -- Greco - Basi di Dati (2024)
(4, 4),  -- Martini - Algoritmi
(5, 5),  -- Colombo - Analisi I
(5, 19), -- Colombo - Analisi I (2024)
(6, 6),  -- Bianchi - Analisi II
(7, 7),  -- Verdi - Fondamenti
(7, 20), -- Verdi - Fondamenti (2024)
(8, 8),  -- Rossi - Sistemi Operativi
(9, 9),  -- Ferrari - Elettrotecnica
(10, 10), -- Conti - Elettronica Analogica
(1, 11),  -- Russo - Storia Antica
(1, 21),  -- Russo - Storia Antica (2024)
(2, 12),  -- Ferri - Letteratura Italiana
(3, 13),  -- Greco - Anatomia
(4, 14),  -- Martini - Fisiologia
(5, 15);  -- Colombo - Infermieristica Generale

-- ==========================================
-- INSERT VERIFICHE FINALI (esami)
-- ==========================================
INSERT INTO `verifichefinali` (`Matricola`, `IdInsegnamento`, `IdCorsoLaurea`, `DataVerifica`, `Voto`, `Lode`, `Validita`, `AnnoAccademico`) VALUES
-- Mario Rossi (Matricola 1 - Informatica - 4° anno/FC)
(1, 1, 1, '2022-02-15', 28, 0, 1, 2021),
(1, 2, 1, '2022-07-10', 30, 1, 1, 2021),
(1, 3, 1, '2023-02-20', 27, 0, 1, 2022),
(1, 4, 1, '2023-07-15', 26, 0, 1, 2022),
(1, 5, 1, '2024-02-10', 29, 0, 1, 2023),

-- Giulia Verdi (Matricola 2 - Matematica - 3° anno)
(2, 6, 2, '2022-02-10', 30, 1, 1, 2021),
(2, 7, 2, '2022-07-05', 28, 0, 1, 2021),
(2, 8, 2, '2023-02-15', 29, 0, 1, 2022),
(2, 9, 2, '2023-07-12', 27, 0, 1, 2022),

-- Luca Bianchi (Matricola 3 - Ing. Informatica - 3° anno)
(3, 10, 3, '2023-02-18', 25, 0, 1, 2022),
(3, 6, 3, '2023-07-20', 28, 0, 1, 2022),
(3, 11, 3, '2024-02-15', 26, 0, 1, 2023),

-- Marta Ferrari (Matricola 4 - Ing. Elettronica - laureanda)
(4, 13, 4, '2021-02-10', 27, 0, 1, 2020),
(4, 6, 4, '2021-07-08', 30, 0, 1, 2020),
(4, 14, 4, '2022-02-12', 28, 0, 1, 2021),
(4, 15, 4, '2022-07-10', 29, 0, 1, 2021),

-- Giovanni Conti (Matricola 5 - Storia - 2° anno)
(5, 16, 5, '2024-02-20', 26, 0, 1, 2023),

-- Laura Greco (Matricola 6 - Lettere - 4° anno/FC)
(6, 19, 6, '2022-02-15', 30, 1, 1, 2021),
(6, 20, 6, '2023-02-18', 28, 0, 1, 2022),
(6, 21, 6, '2023-07-14', 27, 0, 1, 2022),

-- Stefano Marino (Matricola 7 - Medicina - 3° anno)
(7, 22, 7, '2023-02-20', 29, 0, 1, 2022),
(7, 23, 7, '2023-07-15', 28, 0, 1, 2022),
(7, 24, 7, '2024-02-18', 30, 0, 1, 2023),

-- Silvia Colombo (Matricola 8 - Informatica - 3° anno)
(8, 1, 1, '2022-02-12', 24, 0, 1, 2021),
(8, 2, 1, '2022-09-15', 26, 0, 1, 2021),
(8, 3, 1, '2023-02-18', 25, 0, 1, 2022),

-- John Smith (Matricola 9 - Ing. Informatica - 3° anno)
(9, 10, 3, '2022-02-15', 28, 0, 1, 2021),
(9, 6, 3, '2022-07-12', 27, 0, 1, 2021),
(9, 11, 3, '2023-02-20', 29, 0, 1, 2022),

-- Anna Mueller (Matricola 10 - Matematica - 3° anno)
(10, 6, 2, '2023-02-10', 30, 1, 1, 2022),
(10, 7, 2, '2023-07-08', 29, 0, 1, 2022),
(10, 8, 2, '2024-02-15', 28, 0, 1, 2023),

-- Mohamed Khan (Matricola 11 - Infermieristica - 2° anno)
(11, 25, 8, '2024-02-20', 27, 0, 1, 2023),

-- Sofia Petrov (Matricola 12 - Lettere - laureanda)
(12, 19, 6, '2021-02-10', 28, 0, 1, 2020),
(12, 20, 6, '2022-02-12', 30, 1, 1, 2021),
(12, 21, 6, '2022-07-10', 29, 0, 1, 2021),

-- Francesco Ricci (Matricola 13 - Informatica - 4° anno/FC)
(13, 1, 1, '2022-02-18', 26, 0, 1, 2021),
(13, 2, 1, '2022-07-15', 27, 0, 1, 2021),
(13, 3, 1, '2023-02-20', 28, 0, 1, 2022),
(13, 4, 1, '2023-07-18', 25, 0, 1, 2022),

-- Margherita Bruno (Matricola 14 - Ing. Elettronica - 3° anno)
(14, 13, 4, '2023-02-15', 29, 0, 1, 2022),
(14, 6, 4, '2023-07-10', 30, 0, 1, 2022),
(14, 14, 4, '2024-02-12', 28, 0, 1, 2023),

-- Marco Gallo (Matricola 15 - Medicina - 5° anno)
(15, 22, 7, '2021-02-10', 30, 1, 1, 2020),
(15, 23, 7, '2021-07-08', 29, 0, 1, 2020),
(15, 24, 7, '2022-02-15', 28, 0, 1, 2021);

-- ==========================================
-- INSERT RELATORI
-- ==========================================
INSERT INTO `relatore` (`IdDocente`, `Matricola`) VALUES
(3, 4),   -- Greco relatore di Marta Ferrari
(2, 12),  -- Ferri relatore di Sofia Petrov
(1, 1),   -- Russo relatore di Mario Rossi
(4, 15),  -- Martini relatore di Marco Gallo
(6, 6);   -- Bianchi relatore di Laura Greco

-- ==========================================
-- INSERT LAUREE (5 lauree)
-- ==========================================
INSERT INTO `laurea` (`Matricola`, `AnnoAccademico`, `Voto`, `Lode`, `DataLaurea`, `Titolo`, `IdControRelatore`) VALUES
(4, 2022, 105, 0, '2023-03-20', 'Progettazione di sistemi elettronici avanzati', 4),
(12, 2023, 110, 1, '2023-12-15', 'Analisi critica della letteratura del Novecento', 3),
(15, 2024, 110, 1, '2024-10-18', 'Nuove frontiere nella terapia oncologica', 5),
(1, 2024, 100, 0, '2024-12-10', 'Sviluppo di applicazioni web scalabili', 2),
(6, 2024, 108, 0, '2024-12-12', 'La filologia romanza nel contesto mediterraneo', 1);









