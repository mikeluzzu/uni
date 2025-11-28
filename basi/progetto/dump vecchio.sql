/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19-12.1.2-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: progettodb
-- ------------------------------------------------------
-- Server version	12.1.2-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*M!100616 SET @OLD_NOTE_VERBOSITY=@@NOTE_VERBOSITY, NOTE_VERBOSITY=0 */;

--
-- Table structure for table `comune`
--

DROP TABLE IF EXISTS `comune`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `comune` (
  `IdComune` int(11) NOT NULL AUTO_INCREMENT,
  `NomeComune` varchar(150) DEFAULT NULL,
  `NumeroAbitanti` int(11) DEFAULT NULL,
  PRIMARY KEY (`IdComune`),
  UNIQUE KEY `IdComune` (`IdComune`)
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comune`
--

LOCK TABLES `comune` WRITE;
/*!40000 ALTER TABLE `comune` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `comune` VALUES
(1,'Lamezia Terme',67000),
(2,'Feroleto Antico',2000),
(3,'Cosenza',70000),
(4,'Rende',36000),
(5,'Reggio Calabria',171000),
(6,'Catanzaro',88000),
(7,'Crotone',64000),
(8,'Vibo Valentia',33000),
(9,'Corigliano-Rossano',77000),
(10,'Castrovillari',22000),
(11,'Paola',16000),
(12,'Siderno',18000),
(13,'Gioia Tauro',19000),
(14,'Palmi',19000),
(15,'Locri',12000),
(16,'Polistena',10000),
(17,'Rosarno',15000),
(18,'Amantea',13000),
(19,'Soverato',9000),
(20,'Napoli',910000),
(21,'Bari',320000),
(22,'Salerno',125000),
(23,'Lecce',95000),
(24,'Messina',220000),
(25,'Cagliari',150000),
(26,'Palermo',630000),
(27,'Roma',2800000),
(28,'Firenze',360000),
(29,'Pisa',90000),
(30,'Milano',1380000),
(31,'Torino',850000),
(32,'Genova',560000),
(33,'Bologna',390000),
(34,'Parma',195000),
(35,'Verona',260000),
(36,'Venezia',250000),
(37,'Trieste',200000),
(38,'Bergamo',120000);
/*!40000 ALTER TABLE `comune` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `corsolaurea`
--

DROP TABLE IF EXISTS `corsolaurea`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `corsolaurea` (
  `IdCorsoLaurea` int(11) NOT NULL AUTO_INCREMENT,
  `NomeCorsoLaurea` varchar(150) NOT NULL,
  `IdDipartimento` int(11) DEFAULT NULL,
  PRIMARY KEY (`IdCorsoLaurea`),
  UNIQUE KEY `IdCorsoLaurea` (`IdCorsoLaurea`),
  KEY `fk_corso_dipartimento` (`IdDipartimento`),
  CONSTRAINT `fk_corso_dipartimento` FOREIGN KEY (`IdDipartimento`) REFERENCES `dipartimento` (`IdDipartimento`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `corsolaurea`
--

LOCK TABLES `corsolaurea` WRITE;
/*!40000 ALTER TABLE `corsolaurea` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `corsolaurea` VALUES
(1,'Matematica',1),
(2,'Informatica',1),
(3,'Biologia',2),
(4,'Scienze Motorie e Sportive',2),
(5,'Scienze Geologiche',2),
(6,'Scienze Naturali e Ambientali',2),
(7,'Fisica',3),
(8,'Filosofia e Storia',4),
(9,'Lettere',4),
(10,'Lingue e Culture Moderne',4),
(11,'Chimica',5),
(12,'Scienze e Tecniche Psicologiche',6),
(13,'Scienze dell\'Educazione',6),
(14,'Economia',7),
(15,'Statistica per Data Science',7),
(16,'Farmacia',8),
(17,'Infermieristica',8),
(18,'Fisioterapia',8),
(19,'Medicina e Chirurgia',8),
(20,'Scienza della Nutrizione',8),
(21,'Ingegneria Civile',9),
(22,'Ingegneria Ambientale',10),
(23,'Tecnologie del Mare e della Navigazione',10),
(24,'Ingegneria Informatica',11),
(25,'Ingegneria Elettronica',11),
(26,'Ingegneria Meccanica',12),
(27,'Ingegneria Gestionale',12),
(28,'Economia Aziendale',13),
(29,'Giurisprudenza',13),
(30,'Scienze del Turismo e Servizi Turistici',13),
(31,'Scienze Politiche',14),
(32,'Scienze dell\'Amministrazione',14);
/*!40000 ALTER TABLE `corsolaurea` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `dipartimento`
--

DROP TABLE IF EXISTS `dipartimento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `dipartimento` (
  `IdDipartimento` int(11) NOT NULL AUTO_INCREMENT,
  `NomeDipartimento` varchar(150) NOT NULL,
  PRIMARY KEY (`IdDipartimento`),
  UNIQUE KEY `IdDipartimento` (`IdDipartimento`),
  UNIQUE KEY `NomeDipartimento` (`NomeDipartimento`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dipartimento`
--

LOCK TABLES `dipartimento` WRITE;
/*!40000 ALTER TABLE `dipartimento` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `dipartimento` VALUES
(2,'Biologia, Ecologia e Scienze della Terra'),
(5,'Chimica e Teconologie Chimiche'),
(6,'Culture, Educazione e Società'),
(7,'Economia, Statistica e Finanza'),
(8,'Farmacia e Scienze della Salute e Nutrizione'),
(3,'Fisica'),
(10,'Ingegneria Ambientale'),
(9,'Ingegneria Civile'),
(11,'Ingegneria Informatica ed Elettronica'),
(12,'Ingegneria Meccanica, Energetica e Gestionale'),
(1,'Matematica e Informatica'),
(13,'Scienze Aziendali e Giuridiche'),
(14,'Scienze Politiche e Sociali'),
(4,'Studi Umanistici');
/*!40000 ALTER TABLE `dipartimento` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `docente`
--

DROP TABLE IF EXISTS `docente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `docente` (
  `IdDocente` int(11) NOT NULL AUTO_INCREMENT,
  `CodiceFiscale` char(16) NOT NULL,
  `Nome` varchar(100) NOT NULL,
  `Cognome` varchar(100) NOT NULL,
  `Tipo` enum('Docente di ruolo','Collaboratore') DEFAULT NULL,
  PRIMARY KEY (`IdDocente`),
  UNIQUE KEY `CodiceFiscale` (`CodiceFiscale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `docente`
--

LOCK TABLES `docente` WRITE;
/*!40000 ALTER TABLE `docente` DISABLE KEYS */;
set autocommit=0;
/*!40000 ALTER TABLE `docente` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `docenza`
--

DROP TABLE IF EXISTS `docenza`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `docenza` (
  `IdDocente` int(11) NOT NULL,
  `IdEdizioneInsegnamento` int(11) NOT NULL,
  PRIMARY KEY (`IdDocente`,`IdEdizioneInsegnamento`),
  KEY `fk_docenza_edizione` (`IdEdizioneInsegnamento`),
  CONSTRAINT `fk_docenza_docente` FOREIGN KEY (`IdDocente`) REFERENCES `docente` (`IdDocente`),
  CONSTRAINT `fk_docenza_edizione` FOREIGN KEY (`IdEdizioneInsegnamento`) REFERENCES `edizioneinsegnamento` (`IdEdizioneInsegnamento`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `docenza`
--

LOCK TABLES `docenza` WRITE;
/*!40000 ALTER TABLE `docenza` DISABLE KEYS */;
set autocommit=0;
/*!40000 ALTER TABLE `docenza` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `edizioneinsegnamento`
--

DROP TABLE IF EXISTS `edizioneinsegnamento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `edizioneinsegnamento` (
  `IdEdizioneInsegnamento` int(11) NOT NULL AUTO_INCREMENT,
  `IdInsegnamento` int(11) NOT NULL,
  `IdCorsoLaurea` int(11) NOT NULL,
  `AnnoAccademico` year(4) NOT NULL,
  `Trimestre` enum('1','2','3','4') NOT NULL,
  PRIMARY KEY (`IdEdizioneInsegnamento`),
  UNIQUE KEY `IdEdizioneInsegnamento` (`IdEdizioneInsegnamento`),
  KEY `fk_edizione_insegnamento` (`IdInsegnamento`),
  KEY `fk_edizione_corso` (`IdCorsoLaurea`),
  CONSTRAINT `fk_edizione_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`),
  CONSTRAINT `fk_edizione_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `edizioneinsegnamento`
--

LOCK TABLES `edizioneinsegnamento` WRITE;
/*!40000 ALTER TABLE `edizioneinsegnamento` DISABLE KEYS */;
set autocommit=0;
/*!40000 ALTER TABLE `edizioneinsegnamento` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `insegnamento`
--

DROP TABLE IF EXISTS `insegnamento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `insegnamento` (
  `IdInsegnamento` int(11) NOT NULL AUTO_INCREMENT,
  `NomeInsegnamento` varchar(150) NOT NULL,
  PRIMARY KEY (`IdInsegnamento`),
  UNIQUE KEY `IdInsegnamento` (`IdInsegnamento`)
) ENGINE=InnoDB AUTO_INCREMENT=225 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `insegnamento`
--

LOCK TABLES `insegnamento` WRITE;
/*!40000 ALTER TABLE `insegnamento` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `insegnamento` VALUES
(1,'Analisi Matematica I'),
(2,'Analisi Matematica II'),
(3,'Algebra Lineare'),
(4,'Geometria'),
(5,'Fisica Generale I'),
(6,'Analisi Numerica'),
(7,'Probabilità e Statistica'),
(8,'Programmazione I'),
(9,'Programmazione II'),
(10,'Algoritmi e Strutture Dati'),
(11,'Basi di Dati'),
(12,'Sistemi Operativi'),
(13,'Reti di Calcolatori'),
(14,'Ingegneria del Software'),
(15,'Biologia Cellulare'),
(16,'Genetica'),
(17,'Chimica Organica'),
(18,'Biochimica'),
(19,'Botanica'),
(20,'Zoologia'),
(21,'Ecologia'),
(22,'Anatomia Umana'),
(23,'Fisiologia Umana'),
(24,'Teoria e Metodologia del Movimento Umano'),
(25,'Teoria e Metodologia dell\'Allenamento'),
(26,'Medicina dello Sport'),
(27,'Traumatologia dello Sport'),
(28,'Psicologia dello Sport'),
(29,'Geologia Generale'),
(30,'Mineralogia'),
(31,'Petrografia'),
(32,'Paleontologia'),
(33,'Geologia Strutturale'),
(34,'Geofisica'),
(35,'Geologia Applicata'),
(36,'Ecologia Generale'),
(37,'Botanica Sistematica'),
(38,'Zoologia Sistematica'),
(39,'Chimica dell\'Ambiente'),
(40,'Geologia Ambientale'),
(41,'Conservazione della Natura'),
(42,'Valutazione di Impatto Ambientale'),
(43,'Fisica Generale II'),
(44,'Meccanica Quantistica'),
(45,'Termodinamica'),
(46,'Elettromagnetismo'),
(47,'Fisica Moderna'),
(48,'Laboratorio di Fisica'),
(49,'Fisica della Materia'),
(50,'Storia della Filosofia Antica'),
(51,'Storia della Filosofia Moderna'),
(52,'Storia della Filosofia Contemporanea'),
(53,'Storia Medievale'),
(54,'Storia Moderna'),
(55,'Storia Contemporanea'),
(56,'Filosofia Teoretica'),
(57,'Letteratura Italiana'),
(58,'Letteratura Latina'),
(59,'Letteratura Greca'),
(60,'Linguistica Generale'),
(61,'Filologia Romanza'),
(62,'Storia della Lingua Italiana'),
(63,'Letteratura Italiana Contemporanea'),
(64,'Lingua Inglese I'),
(65,'Lingua Inglese II'),
(66,'Lingua Francese I'),
(67,'Lingua Spagnola I'),
(68,'Lingua Tedesca I'),
(69,'Letteratura Inglese'),
(70,'Linguistica Applicata'),
(71,'Chimica Generale e Inorganica'),
(72,'Chimica Organica I'),
(73,'Chimica Organica II'),
(74,'Chimica Fisica'),
(75,'Chimica Analitica'),
(76,'Chimica Industriale'),
(77,'Laboratorio di Chimica'),
(78,'Psicologia Generale'),
(79,'Psicologia dello Sviluppo'),
(80,'Psicologia Sociale'),
(81,'Psicologia Clinica'),
(82,'Neuropsicologia'),
(83,'Psicometria'),
(84,'Psicologia del Lavoro'),
(85,'Pedagogia Generale'),
(86,'Storia della Pedagogia'),
(87,'Didattica Generale'),
(88,'Pedagogia Speciale'),
(89,'Psicologia dell\'Educazione'),
(90,'Sociologia dell\'Educazione'),
(91,'Tecnologie Didattiche'),
(92,'Microeconomia'),
(93,'Macroeconomia'),
(94,'Economia Politica'),
(95,'Matematica per l\'Economia'),
(96,'Statistica Economica'),
(97,'Politica Economica'),
(98,'Economia Internazionale'),
(99,'Statistica Descrittiva'),
(100,'Statistica Inferenziale'),
(101,'Machine Learning'),
(102,'Data Mining'),
(103,'Big Data Analytics'),
(104,'Programmazione per la Data Science'),
(105,'Analisi delle Serie Temporali'),
(106,'Chimica Farmaceutica'),
(107,'Farmacologia'),
(108,'Farmacognosia'),
(109,'Tecnologia Farmaceutica'),
(110,'Tossicologia'),
(111,'Chimica degli Alimenti'),
(112,'Legislazione Farmaceutica'),
(113,'Infermieristica Generale'),
(114,'Infermieristica Clinica'),
(115,'Infermieristica Chirurgica'),
(116,'Patologia Generale'),
(117,'Farmacologia Clinica'),
(118,'Igiene e Prevenzione'),
(119,'Primo Soccorso'),
(120,'Cinesiologia'),
(121,'Fisioterapia Generale'),
(122,'Riabilitazione Ortopedica'),
(123,'Riabilitazione Neurologica'),
(124,'Fisioterapia Respiratoria'),
(125,'Terapia Manuale'),
(126,'Biomeccanica'),
(127,'Anatomia Patologica'),
(128,'Medicina Interna'),
(129,'Chirurgia Generale'),
(130,'Pediatria'),
(131,'Ginecologia e Ostetricia'),
(132,'Cardiologia'),
(133,'Neurologia'),
(134,'Biochimica della Nutrizione'),
(135,'Fisiologia della Nutrizione'),
(136,'Dietetica'),
(137,'Nutrizione Clinica'),
(138,'Scienza e Tecnologia Alimentare'),
(139,'Igiene degli Alimenti'),
(140,'Nutrizione dello Sport'),
(141,'Scienza delle Costruzioni'),
(142,'Tecnica delle Costruzioni'),
(143,'Geotecnica'),
(144,'Idraulica'),
(145,'Topografia'),
(146,'Costruzioni Idrauliche'),
(147,'Strade Ferrovie Aeroporti'),
(148,'Ingegneria Sanitaria Ambientale'),
(149,'Gestione dei Rifiuti'),
(150,'Depurazione delle Acque'),
(151,'Inquinamento Atmosferico'),
(152,'Bonifica dei Siti Contaminati'),
(153,'Ecologia Industriale'),
(154,'Energie Rinnovabili'),
(155,'Architettura Navale'),
(156,'Navigazione'),
(157,'Oceanografia'),
(158,'Impianti Navali'),
(159,'Costruzioni Navali'),
(160,'Diritto della Navigazione'),
(161,'Tecnologie Marine'),
(162,'Architettura dei Calcolatori'),
(163,'Sistemi Embedded'),
(164,'Sicurezza Informatica'),
(165,'Intelligenza Artificiale'),
(166,'Sistemi Distribuiti'),
(167,'Cloud Computing'),
(168,'Internet of Things'),
(169,'Elettronica Analogica'),
(170,'Elettronica Digitale'),
(171,'Microelettronica'),
(172,'Elettronica di Potenza'),
(173,'Telecomunicazioni'),
(174,'Teoria dei Segnali'),
(175,'Strumentazione Elettronica'),
(176,'Meccanica Applicata alle Macchine'),
(177,'Disegno Meccanico'),
(178,'Tecnologia Meccanica'),
(179,'Macchine a Fluido'),
(180,'Impianti Meccanici'),
(181,'Termodinamica Applicata'),
(182,'Meccanica dei Materiali'),
(183,'Gestione della Produzione'),
(184,'Gestione della Qualità'),
(185,'Logistica Industriale'),
(186,'Organizzazione Aziendale'),
(187,'Controllo di Gestione'),
(188,'Marketing Industriale'),
(189,'Project Management'),
(190,'Ragioneria Generale'),
(191,'Contabilità e Bilancio'),
(192,'Economia e Gestione delle Imprese'),
(193,'Finanza Aziendale'),
(194,'Marketing'),
(195,'Diritto Commerciale'),
(196,'Revisione Aziendale'),
(197,'Diritto Privato'),
(198,'Diritto Costituzionale'),
(199,'Diritto Penale'),
(200,'Diritto Amministrativo'),
(201,'Diritto del Lavoro'),
(202,'Diritto Processuale Civile'),
(203,'Diritto Internazionale'),
(204,'Economia del Turismo'),
(205,'Geografia del Turismo'),
(206,'Marketing Turistico'),
(207,'Management delle Imprese Turistiche'),
(208,'Legislazione Turistica'),
(209,'Sociologia del Turismo'),
(210,'Gestione degli Eventi'),
(211,'Scienza Politica'),
(212,'Sociologia Politica'),
(213,'Relazioni Internazionali'),
(214,'Storia delle Dottrine Politiche'),
(215,'Istituzioni di Diritto Pubblico'),
(216,'Politica Comparata'),
(217,'Comunicazione Politica'),
(218,'Diritto Amministrativo Pubblico'),
(219,'Scienza dell\'Amministrazione'),
(220,'Contabilità Pubblica'),
(221,'Organizzazione delle Amministrazioni Pubbliche'),
(222,'Management Pubblico'),
(223,'Diritto degli Enti Locali'),
(224,'E-Government');
/*!40000 ALTER TABLE `insegnamento` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `insegnamentoindirizzo`
--

DROP TABLE IF EXISTS `insegnamentoindirizzo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `insegnamentoindirizzo` (
  `IdInsegnamento` int(11) NOT NULL,
  `IdCorsoLaurea` int(11) NOT NULL,
  `Crediti` int(11) NOT NULL,
  `Anno` int(11) NOT NULL,
  `Semestre` int(11) NOT NULL,
  PRIMARY KEY (`IdInsegnamento`,`IdCorsoLaurea`),
  KEY `fk_insegnamento_indirizzo_corso` (`IdCorsoLaurea`),
  CONSTRAINT `fk_insegnamento_indirizzo_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`),
  CONSTRAINT `fk_insegnamento_indirizzo_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `insegnamentoindirizzo`
--

LOCK TABLES `insegnamentoindirizzo` WRITE;
/*!40000 ALTER TABLE `insegnamentoindirizzo` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `insegnamentoindirizzo` VALUES
(1,1,12,1,1),
(2,1,12,1,2),
(3,1,9,1,1),
(4,1,9,1,2),
(5,1,9,2,1),
(6,1,9,2,2),
(7,1,9,3,1),
(8,2,12,1,1),
(9,2,12,1,2),
(10,2,9,2,1),
(11,2,9,2,2),
(12,2,9,2,1),
(13,2,9,3,1),
(14,2,9,3,2),
(15,3,9,1,1),
(16,3,9,1,2),
(17,3,9,1,1),
(18,3,12,2,1),
(19,3,9,2,2),
(20,3,9,2,1),
(21,3,9,3,1),
(22,4,9,1,1),
(23,4,9,1,2),
(24,4,12,1,1),
(25,4,12,2,1),
(26,4,9,2,2),
(27,4,6,3,1),
(28,4,6,3,2),
(29,5,12,1,1),
(30,5,9,1,2),
(31,5,9,2,1),
(32,5,9,2,2),
(33,5,9,2,1),
(34,5,9,3,1),
(35,5,9,3,2),
(36,6,12,1,1),
(37,6,9,1,2),
(38,6,9,1,1),
(39,6,9,2,1),
(40,6,9,2,2),
(41,6,9,3,1),
(42,6,9,3,2),
(43,7,12,1,2),
(44,7,12,2,1),
(45,7,9,1,1),
(46,7,12,1,2),
(47,7,9,2,2),
(48,7,6,3,1),
(49,7,9,3,2),
(50,8,12,1,1),
(51,8,12,1,2),
(52,8,12,2,1),
(53,8,9,1,1),
(54,8,9,2,1),
(55,8,9,2,2),
(56,8,9,3,1),
(57,9,12,1,1),
(58,9,12,1,2),
(59,9,12,2,1),
(60,9,9,1,1),
(61,9,9,2,2),
(62,9,9,3,1),
(63,9,9,3,2),
(64,10,12,1,1),
(65,10,12,1,2),
(66,10,9,2,1),
(67,10,9,2,2),
(68,10,9,2,1),
(69,10,9,3,1),
(70,10,6,3,2),
(71,11,12,1,1),
(72,11,12,1,2),
(73,11,12,2,1),
(74,11,9,2,2),
(75,11,9,2,1),
(76,11,9,3,1),
(77,11,6,3,2),
(78,12,12,1,1),
(79,12,9,1,2),
(80,12,9,1,1),
(81,12,9,2,1),
(82,12,9,2,2),
(83,12,9,3,1),
(84,12,6,3,2),
(85,13,12,1,1),
(86,13,9,1,2),
(87,13,9,2,1),
(88,13,9,2,2),
(89,13,9,1,2),
(90,13,9,3,1),
(91,13,6,3,2),
(92,14,9,1,1),
(93,14,9,1,2),
(94,14,12,1,1),
(95,14,9,1,2),
(96,14,9,2,1),
(97,14,9,2,2),
(98,14,9,3,1),
(99,15,9,1,1),
(100,15,9,1,2),
(101,15,12,2,1),
(102,15,9,2,2),
(103,15,9,3,1),
(104,15,12,1,1),
(105,15,9,3,2),
(106,16,12,2,1),
(107,16,12,2,2),
(108,16,9,3,1),
(109,16,9,3,2),
(110,16,9,2,2),
(111,16,6,3,1),
(112,16,6,3,2),
(113,17,12,1,1),
(114,17,12,2,1),
(115,17,12,2,2),
(116,17,9,1,2),
(117,17,9,2,1),
(118,17,9,1,1),
(119,17,6,3,1),
(120,18,9,1,1),
(121,18,12,1,2),
(122,18,12,2,1),
(123,18,12,2,2),
(124,18,9,3,1),
(125,18,9,3,2),
(126,18,6,1,1),
(127,19,12,2,1),
(128,19,12,3,1),
(129,19,12,3,2),
(130,19,9,2,2),
(131,19,9,3,1),
(132,19,9,2,1),
(133,19,9,3,2),
(134,20,12,1,1),
(135,20,12,1,2),
(136,20,12,2,1),
(137,20,9,2,2),
(138,20,9,3,1),
(139,20,9,2,1),
(140,20,6,3,2),
(141,21,12,2,1),
(142,21,12,2,2),
(143,21,9,2,2),
(144,21,9,1,2),
(145,21,9,1,1),
(146,21,9,3,1),
(147,21,9,3,2),
(148,22,12,2,1),
(149,22,9,2,2),
(150,22,9,2,1),
(151,22,9,3,1),
(152,22,9,3,2),
(153,22,9,2,2),
(154,22,9,3,1),
(155,23,12,1,1),
(156,23,12,1,2),
(157,23,9,2,1),
(158,23,9,2,2),
(159,23,9,2,1),
(160,23,6,3,1),
(161,23,9,3,2),
(162,24,9,1,1),
(163,24,9,2,1),
(164,24,9,2,2),
(165,24,12,2,1),
(166,24,9,3,1),
(167,24,9,3,2),
(168,24,9,3,1),
(169,25,12,1,1),
(170,25,12,1,2),
(171,25,9,2,1),
(172,25,9,2,2),
(173,25,9,2,1),
(174,25,9,3,1),
(175,25,6,3,2),
(176,26,12,2,1),
(177,26,9,1,1),
(178,26,9,2,2),
(179,26,9,2,1),
(180,26,9,3,1),
(181,26,9,1,2),
(182,26,9,3,2),
(183,27,9,2,1),
(184,27,9,2,2),
(185,27,9,2,1),
(186,27,12,1,1),
(187,27,9,3,1),
(188,27,9,3,2),
(189,27,9,1,2),
(190,28,12,1,1),
(191,28,12,1,2),
(192,28,12,2,1),
(193,28,9,2,2),
(194,28,9,2,1),
(195,28,9,3,1),
(196,28,9,3,2),
(197,29,12,1,1),
(198,29,12,1,2),
(199,29,12,2,1),
(200,29,12,2,2),
(201,29,9,3,1),
(202,29,9,3,2),
(203,29,9,3,1),
(204,30,12,1,1),
(205,30,9,1,2),
(206,30,9,2,1),
(207,30,9,2,2),
(208,30,9,2,1),
(209,30,9,3,1),
(210,30,6,3,2),
(211,31,12,1,1),
(212,31,9,1,2),
(213,31,9,2,1),
(214,31,9,1,1),
(215,31,12,1,2),
(216,31,9,2,2),
(217,31,9,3,1),
(218,32,12,1,1),
(219,32,12,1,2),
(220,32,9,2,1),
(221,32,12,2,2),
(222,32,9,3,1),
(223,32,9,2,1),
(224,32,6,3,2);
/*!40000 ALTER TABLE `insegnamentoindirizzo` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `iscrizione`
--

DROP TABLE IF EXISTS `iscrizione`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `iscrizione` (
  `Matricola` int(11) NOT NULL,
  `AnnoAccademico` year(4) NOT NULL,
  `ProgressivoAnno` int(11) NOT NULL,
  `DataIscrizione` date NOT NULL,
  `Tipo` enum('Regolare','Non Regolare','Fuori Corso') DEFAULT NULL,
  PRIMARY KEY (`Matricola`,`AnnoAccademico`),
  CONSTRAINT `fk_iscrizione_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `iscrizione`
--

LOCK TABLES `iscrizione` WRITE;
/*!40000 ALTER TABLE `iscrizione` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `iscrizione` VALUES
(1,2025,2,'2024-06-10','Regolare'),
(2,2024,1,'2024-07-19','Regolare'),
(3,2020,5,'2020-09-14','Fuori Corso'),
(4,2020,5,'2020-10-02','Fuori Corso'),
(5,2021,4,'2021-02-18','Regolare'),
(6,2023,2,'2023-03-05','Regolare'),
(7,2024,1,'2024-09-27','Non Regolare'),
(8,2024,1,'2024-01-11','Regolare'),
(9,2022,3,'2022-03-22','Regolare'),
(10,2025,1,'2025-10-06','Regolare'),
(11,2020,5,'2020-11-19','Fuori Corso'),
(12,2024,1,'2024-12-03','Regolare'),
(13,2023,2,'2023-04-14','Regolare'),
(14,2025,1,'2025-03-09','Regolare'),
(15,2023,2,'2023-05-21','Regolare'),
(16,2020,5,'2020-07-30','Fuori Corso'),
(17,2023,2,'2023-08-16','Regolare'),
(18,2025,1,'2025-02-27','Regolare'),
(19,2024,1,'2024-01-15','Non Regolare'),
(20,2022,3,'2022-09-08','Regolare'),
(21,2023,2,'2023-11-12','Regolare'),
(22,2024,1,'2024-02-04','Regolare'),
(23,2025,1,'2025-12-29','Regolare'),
(24,2023,2,'2023-06-17','Regolare'),
(25,2024,1,'2024-04-23','Regolare'),
(26,2024,1,'2024-06-02','Regolare'),
(27,2024,1,'2024-03-10','Regolare'),
(28,2020,5,'2020-08-25','Fuori Corso'),
(29,2025,1,'2025-05-18','Regolare'),
(30,2023,2,'2023-07-02','Regolare'),
(31,2025,1,'2025-11-28','Non Regolare'),
(32,2024,1,'2024-04-15','Regolare'),
(33,2023,2,'2023-01-19','Regolare'),
(34,2022,3,'2022-02-07','Regolare'),
(35,2021,4,'2021-05-31','Regolare'),
(36,2024,1,'2024-06-26','Regolare'),
(37,2025,1,'2025-03-12','Regolare'),
(38,2022,3,'2022-11-03','Non Regolare'),
(39,2025,1,'2025-09-20','Regolare'),
(40,2024,1,'2024-07-08','Regolare');
/*!40000 ALTER TABLE `iscrizione` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `laurea`
--

DROP TABLE IF EXISTS `laurea`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `laurea` (
  `Matricola` int(11) NOT NULL,
  `AnnoAccademico` year(4) NOT NULL,
  `Voto` int(11) NOT NULL CHECK (`Voto` >= 66 and `Voto` <= 110),
  `Lode` tinyint(1) NOT NULL,
  `DataLaurea` date NOT NULL,
  `Titolo` varchar(100) NOT NULL,
  `IdControRelatore` int(11) DEFAULT NULL,
  PRIMARY KEY (`Matricola`),
  KEY `fk_laurea_controrelatore` (`IdControRelatore`),
  CONSTRAINT `fk_laurea_controrelatore` FOREIGN KEY (`IdControRelatore`) REFERENCES `docente` (`IdDocente`),
  CONSTRAINT `fk_laurea_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `laurea`
--

LOCK TABLES `laurea` WRITE;
/*!40000 ALTER TABLE `laurea` DISABLE KEYS */;
set autocommit=0;
/*!40000 ALTER TABLE `laurea` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `matricolastudente`
--

DROP TABLE IF EXISTS `matricolastudente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `matricolastudente` (
  `Matricola` int(11) NOT NULL AUTO_INCREMENT,
  `DataImmatricolazione` date NOT NULL,
  `IdStudente` int(11) DEFAULT NULL,
  `IdCorsoLaurea` int(11) DEFAULT NULL,
  PRIMARY KEY (`Matricola`),
  UNIQUE KEY `Matricola` (`Matricola`),
  KEY `fk_matricola_studente` (`IdStudente`),
  KEY `fk_matricola_corso` (`IdCorsoLaurea`),
  CONSTRAINT `fk_matricola_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`),
  CONSTRAINT `fk_matricola_studente` FOREIGN KEY (`IdStudente`) REFERENCES `studente` (`IdStudente`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `matricolastudente`
--

LOCK TABLES `matricolastudente` WRITE;
/*!40000 ALTER TABLE `matricolastudente` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `matricolastudente` VALUES
(1,'2024-06-10',1,2),
(2,'2024-07-19',2,7),
(3,'2020-09-14',3,12),
(4,'2020-10-02',4,7),
(5,'2021-02-18',5,18),
(6,'2023-03-05',6,4),
(7,'2024-09-27',7,25),
(8,'2024-01-11',8,9),
(9,'2022-03-22',9,31),
(10,'2025-10-06',10,15),
(11,'2020-11-19',11,2),
(12,'2024-12-03',12,28),
(13,'2023-04-14',13,6),
(14,'2025-03-09',14,22),
(15,'2023-05-21',15,13),
(16,'2020-07-30',16,32),
(17,'2023-08-16',17,5),
(18,'2025-02-27',18,19),
(19,'2024-01-15',19,11),
(20,'2022-09-08',20,26),
(21,'2023-11-12',21,8),
(22,'2024-02-04',22,30),
(23,'2025-12-29',23,1),
(24,'2023-06-17',24,17),
(25,'2024-04-23',25,20),
(26,'2024-06-02',26,14),
(27,'2024-03-10',27,29),
(28,'2020-08-25',28,3),
(29,'2025-05-18',29,23),
(30,'2023-07-02',30,10),
(31,'2025-11-28',31,24),
(32,'2024-04-15',32,16),
(33,'2023-01-19',33,27),
(34,'2022-02-07',34,21),
(35,'2021-05-31',35,12),
(36,'2024-06-26',36,7),
(37,'2025-03-12',37,18),
(38,'2022-11-03',38,4),
(39,'2025-09-20',39,25),
(40,'2024-07-08',40,9);
/*!40000 ALTER TABLE `matricolastudente` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `relatore`
--

DROP TABLE IF EXISTS `relatore`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `relatore` (
  `IdDocente` int(11) NOT NULL,
  `Matricola` int(11) NOT NULL,
  PRIMARY KEY (`IdDocente`,`Matricola`),
  KEY `fk_relatore_matricola` (`Matricola`),
  CONSTRAINT `fk_relatore_docente` FOREIGN KEY (`IdDocente`) REFERENCES `docente` (`IdDocente`),
  CONSTRAINT `fk_relatore_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `relatore`
--

LOCK TABLES `relatore` WRITE;
/*!40000 ALTER TABLE `relatore` DISABLE KEYS */;
set autocommit=0;
/*!40000 ALTER TABLE `relatore` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `studente`
--

DROP TABLE IF EXISTS `studente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `studente` (
  `IdStudente` int(11) NOT NULL AUTO_INCREMENT,
  `CodiceFiscale` char(16) NOT NULL,
  `Nome` varchar(100) NOT NULL,
  `Cognome` varchar(100) NOT NULL,
  `DataNascita` date NOT NULL,
  `Sesso` enum('M','F') NOT NULL,
  `Straniero` tinyint(1) NOT NULL,
  `IdResidenza` int(11) DEFAULT NULL,
  `IdDomicilio` int(11) NOT NULL,
  PRIMARY KEY (`IdStudente`),
  UNIQUE KEY `IdStudente` (`IdStudente`),
  UNIQUE KEY `CodiceFiscale` (`CodiceFiscale`),
  KEY `fk_studente_residenza` (`IdResidenza`),
  KEY `fk_studente_domicilio` (`IdDomicilio`),
  CONSTRAINT `fk_studente_domicilio` FOREIGN KEY (`IdDomicilio`) REFERENCES `comune` (`IdComune`),
  CONSTRAINT `fk_studente_residenza` FOREIGN KEY (`IdResidenza`) REFERENCES `comune` (`IdComune`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `studente`
--

LOCK TABLES `studente` WRITE;
/*!40000 ALTER TABLE `studente` DISABLE KEYS */;
set autocommit=0;
INSERT INTO `studente` VALUES
(1,'MLNMHL05R26M208A','Michele','Molinaro','2005-10-26','M',0,2,4),
(2,'MRARSS04H14D086M','Mario','Rossi','2004-06-14','M',0,4,4),
(3,'BNCLCU01C12F205Z','Luca','Bianchi','2001-03-12','M',0,2,1),
(4,'VRDLRA02E22H224T','Laura','Verdi','2002-05-22','F',0,3,3),
(5,'KMLSRB99D15Z404Y','Sara','Kim','1999-04-15','F',1,NULL,4),
(6,'HNGJHN03B09Z210Q','John','Hung','2003-02-09','M',1,NULL,3),
(7,'FRNGPP00D30H501C','Giuseppe','Ferrini','2000-04-30','M',0,2,4),
(8,'PLLMNL01H11L781P','Manuela','Pellegrini','2001-08-11','F',0,3,2),
(9,'NVLCHL02A25Z129B','Chloé','Naville','2002-01-25','F',1,NULL,1),
(10,'MLNFNC11C11M208P','Francesco','Molinaro','2011-03-11','M',0,2,3),
(11,'RSSMRC01A12H501T','Marco','Rossi','2001-01-12','M',0,5,12),
(12,'BNCFRA02C23F205X','Francesca','Bianchi','2002-03-23','F',0,7,18),
(13,'VRDLGU00D09H224P','Luigi','Verdi','2000-04-09','M',0,12,8),
(14,'CNTMNL03E17L736S','Manuela','Conti','2003-05-17','F',0,14,21),
(15,'PLLGNN99H03L781C','Gennaro','Pellegrini','1999-08-03','M',0,3,30),
(16,'KMLHNS04B14Z404Q','Hans','Kamil','2004-02-14','M',1,NULL,11),
(17,'HNGCHR02F27Z210N','Chiara','Hung','2002-06-27','F',1,NULL,6),
(18,'FRRGPP01C10H501M','Giuseppe','Ferraro','2001-03-10','M',0,9,15),
(19,'DLLSRA00A01L219W','Sara','Dalle','2000-01-01','F',0,16,35),
(20,'GLLMRC03D28L736A','Marco','Gallo','2003-04-28','M',0,4,37),
(21,'SSNNCL99E06H224H','Nicola','Sassi','1999-05-06','M',0,18,9),
(22,'HNSMRK02B22Z210U','Mark','Hansson','2002-02-22','M',1,NULL,13),
(23,'KMPLSN04G18Z404D','Alison','Kemper','2004-07-18','F',1,NULL,10),
(24,'RSSFDB01H02H118C','Fabio','Rossi','2001-08-02','M',0,33,5),
(25,'BNCSLV00C29F205B','Silvia','Benco','2000-03-29','F',0,2,32),
(26,'VRDMNL03E14H224L','Manuel','Verdi','2003-05-14','M',0,6,19),
(27,'HNGKTL02A20Z210E','Katrin','Hung','2002-01-20','F',1,NULL,1),
(28,'PLLMRC99F27L781V','Marco','Pilla','1999-06-27','M',0,11,26),
(29,'NVLCHR01B04Z129Y','Christian','Naville','2001-02-04','M',1,NULL,3),
(30,'RCCSLL04C12H501F','Stella','Rocchi','2004-03-12','F',0,21,34),
(31,'BRSTMR00D08L219Z','Tamara','Bertini','2000-04-08','F',0,10,20),
(32,'DLCMRC02E11H118T','Marco','De Luca','2002-05-11','M',0,35,14),
(33,'GLLLRA03G13L736H','Lara','Gallo','2003-07-13','F',0,19,27),
(34,'SSNRBL01A30H501R','Roberto','Sassi','2001-01-30','M',0,26,2),
(35,'HNDJHN99G19Z210K','John','Henderson','1999-07-19','M',1,NULL,17),
(36,'KMLSRB04F04Z404P','Serena','Kim','2004-06-04','F',1,NULL,28),
(37,'FRRNCL00C21H501S','Nicole','Ferrini','2000-03-21','F',0,23,4),
(38,'BLLMRL02H29L219D','Marilena','Bella','2002-08-29','F',0,8,33),
(39,'GNTCRL01D10H118V','Carlo','Giunti','2001-04-10','M',0,30,24),
(40,'PLLELV03B05L781J','Elvira','Pelletti','2003-02-05','F',0,27,16);
/*!40000 ALTER TABLE `studente` ENABLE KEYS */;
UNLOCK TABLES;
commit;

--
-- Table structure for table `verifichefinali`
--

DROP TABLE IF EXISTS `verifichefinali`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `verifichefinali` (
  `Matricola` int(11) NOT NULL,
  `IdInsegnamento` int(11) NOT NULL,
  `IdCorsoLaurea` int(11) NOT NULL,
  `DataVerifica` date NOT NULL,
  `Voto` int(11) DEFAULT NULL CHECK (`Voto` >= 18 and `Voto` <= 30),
  `Lode` tinyint(1) DEFAULT NULL,
  `Validita` tinyint(1) DEFAULT NULL,
  `AnnoAccademico` year(4) DEFAULT NULL,
  PRIMARY KEY (`Matricola`,`IdInsegnamento`,`IdCorsoLaurea`,`DataVerifica`),
  KEY `fk_verifiche_insegnamento` (`IdInsegnamento`),
  KEY `fk_verifiche_corso` (`IdCorsoLaurea`),
  CONSTRAINT `fk_verifiche_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`),
  CONSTRAINT `fk_verifiche_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`),
  CONSTRAINT `fk_verifiche_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `verifichefinali`
--

LOCK TABLES `verifichefinali` WRITE;
/*!40000 ALTER TABLE `verifichefinali` DISABLE KEYS */;
set autocommit=0;
/*!40000 ALTER TABLE `verifichefinali` ENABLE KEYS */;
UNLOCK TABLES;
commit;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_unicode_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'IGNORE_SPACE,STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER check_iscrizione_regolare
BEFORE INSERT ON VerificheFinali
FOR EACH ROW
BEGIN
    DECLARE iscrizione_regolare INT DEFAULT 0;

    SELECT COUNT(*)
        INTO iscrizione_regolare
        FROM Iscrizione
        WHERE Matricola = NEW.Matricola
        AND AnnoAccademico = NEW.AnnoAccademico
        AND Tipo = 'Regolare';

    IF iscrizione_regolare = 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Studente non regolarmente iscritto: esame non consentito.';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

-- Dump completed on 2025-11-23 22:58:30
