/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19-11.7.2-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: progetto_db
-- ------------------------------------------------------
-- Server version	11.8.5-MariaDB

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
  PRIMARY KEY (`IdComune`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comune`
--

LOCK TABLES `comune` WRITE;
/*!40000 ALTER TABLE `comune` DISABLE KEYS */;
INSERT INTO `comune` VALUES
(1,'Rende',180),
(2,'Lamezia Terme',140),
(3,'Cosenza',100),
(4,'Crotone',120),
(5,'Catanzaro',80),
(6,'Reggio Calabria',270);
/*!40000 ALTER TABLE `comune` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_corso_dipartimento` FOREIGN KEY (`IdDipartimento`) REFERENCES `dipartimento` (`IdDipartimento`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `corsolaurea`
--

LOCK TABLES `corsolaurea` WRITE;
/*!40000 ALTER TABLE `corsolaurea` DISABLE KEYS */;
INSERT INTO `corsolaurea` VALUES
(1,'Informatica',1),
(2,'Matematica',1),
(3,'Ingegneria Informatica',2),
(4,'Ingegneria Elettronica',2),
(5,'Storia',3),
(6,'Lettere',3),
(7,'Medicina e Chirurgia',4),
(8,'Infermieristica',4);
/*!40000 ALTER TABLE `corsolaurea` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dipartimento`
--

DROP TABLE IF EXISTS `dipartimento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `dipartimento` (
  `IdDipartimento` int(11) NOT NULL AUTO_INCREMENT,
  `NomeDipartimento` varchar(150) NOT NULL,
  PRIMARY KEY (`IdDipartimento`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dipartimento`
--

LOCK TABLES `dipartimento` WRITE;
/*!40000 ALTER TABLE `dipartimento` DISABLE KEYS */;
INSERT INTO `dipartimento` VALUES
(1,'Dipartimento di Matematica e Informatica'),
(2,'Dipartimento di Ingegneria Informatica ed Elettronica'),
(3,'Dipartimento di Studi Umanistici'),
(4,'Dipartimento di Scienze della Salute');
/*!40000 ALTER TABLE `dipartimento` ENABLE KEYS */;
UNLOCK TABLES;

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
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `docente`
--

LOCK TABLES `docente` WRITE;
/*!40000 ALTER TABLE `docente` DISABLE KEYS */;
INSERT INTO `docente` VALUES
(1,'RSSLGI65A01H501A','Luigi','Russo','Docente di ruolo'),
(2,'FRRGPP70B15F839B','Giuseppe','Ferri','Docente di ruolo'),
(3,'GRCPLA68C20D086C','Paola','Greco','Docente di ruolo'),
(4,'MRTANT72D10H224D','Antonio','Martini','Docente di ruolo'),
(5,'CLMFRN75E05F839E','Francesca','Colombo','Collaboratore'),
(6,'BNCCRL69F12H501F','Carlo','Bianchi','Docente di ruolo'),
(7,'VRDMRA73G08D086G','Maria','Verdi','Collaboratore'),
(8,'RSSNDR71H25F839H','Andrea','Rossi','Docente di ruolo'),
(9,'FRRELT76I18H224I','Elena','Ferrari','Collaboratore'),
(10,'CNTRCR68J30H501J','Riccardo','Conti','Docente di ruolo');
/*!40000 ALTER TABLE `docente` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_docenza_docente` FOREIGN KEY (`IdDocente`) REFERENCES `docente` (`IdDocente`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_docenza_edizione` FOREIGN KEY (`IdEdizioneInsegnamento`) REFERENCES `edizioneinsegnamento` (`IdEdizioneInsegnamento`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `docenza`
--

LOCK TABLES `docenza` WRITE;
/*!40000 ALTER TABLE `docenza` DISABLE KEYS */;
INSERT INTO `docenza` VALUES
(1,1),
(2,2),
(3,3),
(4,4),
(5,5),
(6,6),
(7,7),
(8,8),
(9,9),
(10,10),
(1,11),
(2,12),
(3,13),
(4,14),
(5,15),
(1,16),
(2,17),
(3,18),
(5,19),
(7,20),
(1,21);
/*!40000 ALTER TABLE `docenza` ENABLE KEYS */;
UNLOCK TABLES;

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
  `Semestre` enum('1','2') NOT NULL,
  `DataInizio` date NOT NULL,
  `DataFine` date NOT NULL,
  PRIMARY KEY (`IdEdizioneInsegnamento`),
  UNIQUE KEY `IdEdizioneInsegnamento` (`IdEdizioneInsegnamento`),
  KEY `fk_edizione_insegnamento` (`IdInsegnamento`),
  KEY `fk_edizione_corso` (`IdCorsoLaurea`),
  CONSTRAINT `fk_edizione_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_edizione_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `edizioneinsegnamento`
--

LOCK TABLES `edizioneinsegnamento` WRITE;
/*!40000 ALTER TABLE `edizioneinsegnamento` DISABLE KEYS */;
INSERT INTO `edizioneinsegnamento` VALUES
(1,1,1,2023,'1','2023-10-01','2024-01-31'),
(2,2,1,2023,'2','2024-03-01','2024-06-30'),
(3,3,1,2023,'1','2023-10-01','2024-01-31'),
(4,4,1,2023,'2','2024-03-01','2024-06-30'),
(5,6,2,2023,'1','2023-10-01','2024-01-31'),
(6,7,2,2023,'2','2024-03-01','2024-06-30'),
(7,10,3,2023,'1','2023-10-01','2024-01-31'),
(8,11,3,2023,'1','2023-10-01','2024-01-31'),
(9,13,4,2023,'1','2023-10-01','2024-01-31'),
(10,14,4,2023,'1','2023-10-01','2024-01-31'),
(11,16,5,2023,'1','2023-10-01','2024-01-31'),
(12,19,6,2023,'1','2023-10-01','2024-01-31'),
(13,22,7,2023,'1','2023-10-01','2024-01-31'),
(14,23,7,2023,'2','2024-03-01','2024-06-30'),
(15,25,8,2023,'1','2023-10-01','2024-01-31'),
(16,1,1,2024,'1','2024-10-01','2025-01-31'),
(17,2,1,2024,'2','2025-03-01','2025-06-30'),
(18,3,1,2024,'1','2024-10-01','2025-01-31'),
(19,6,2,2024,'1','2024-10-01','2025-01-31'),
(20,10,3,2024,'1','2024-10-01','2025-01-31'),
(21,16,5,2024,'1','2024-10-01','2025-01-31');
/*!40000 ALTER TABLE `edizioneinsegnamento` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `insegnamento`
--

DROP TABLE IF EXISTS `insegnamento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `insegnamento` (
  `IdInsegnamento` int(11) NOT NULL AUTO_INCREMENT,
  `NomeInsegnamento` varchar(150) NOT NULL,
  PRIMARY KEY (`IdInsegnamento`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `insegnamento`
--

LOCK TABLES `insegnamento` WRITE;
/*!40000 ALTER TABLE `insegnamento` DISABLE KEYS */;
INSERT INTO `insegnamento` VALUES
(1,'Programmazione I'),
(2,'Programmazione II'),
(3,'Basi di Dati'),
(4,'Algoritmi e Strutture Dati'),
(5,'Reti di Calcolatori'),
(6,'Analisi Matematica I'),
(7,'Analisi Matematica II'),
(8,'Algebra Lineare'),
(9,'Geometria'),
(10,'Fondamenti di Informatica'),
(11,'Sistemi Operativi'),
(12,'Ingegneria del Software'),
(13,'Elettrotecnica'),
(14,'Elettronica Analogica'),
(15,'Elettronica Digitale'),
(16,'Storia Antica'),
(17,'Storia Medievale'),
(18,'Storia Moderna'),
(19,'Letteratura Italiana'),
(20,'Filologia Romanza'),
(21,'Linguistica Generale'),
(22,'Anatomia Umana'),
(23,'Fisiologia'),
(24,'Patologia Generale'),
(25,'Infermieristica Generale'),
(26,'Infermieristica Clinica');
/*!40000 ALTER TABLE `insegnamento` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_insegnamento_indirizzo_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_insegnamento_indirizzo_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `insegnamentoindirizzo`
--

LOCK TABLES `insegnamentoindirizzo` WRITE;
/*!40000 ALTER TABLE `insegnamentoindirizzo` DISABLE KEYS */;
INSERT INTO `insegnamentoindirizzo` VALUES
(1,1,9,1,1),
(2,1,9,1,2),
(3,1,9,2,1),
(4,1,12,2,2),
(5,1,6,3,1),
(6,2,12,1,1),
(6,3,12,1,1),
(6,4,12,1,1),
(7,2,12,1,2),
(8,2,9,2,1),
(9,2,9,2,2),
(10,3,9,1,1),
(11,3,9,2,1),
(12,3,12,2,2),
(13,4,9,1,1),
(14,4,9,2,1),
(15,4,9,2,2),
(16,5,12,1,1),
(17,5,12,2,1),
(18,5,12,3,1),
(19,6,12,1,1),
(20,6,9,2,1),
(21,6,9,2,2),
(22,7,15,1,1),
(23,7,12,1,2),
(24,7,12,2,1),
(25,8,12,1,1),
(26,8,12,2,1);
/*!40000 ALTER TABLE `insegnamentoindirizzo` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_iscrizione_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `iscrizione`
--

LOCK TABLES `iscrizione` WRITE;
/*!40000 ALTER TABLE `iscrizione` DISABLE KEYS */;
INSERT INTO `iscrizione` VALUES
(1,2021,1,'2021-09-15','Regolare'),
(1,2022,2,'2022-09-15','Regolare'),
(1,2023,3,'2023-09-15','Regolare'),
(1,2024,4,'2024-09-15','Fuori Corso'),
(2,2021,1,'2021-09-15','Regolare'),
(2,2022,2,'2022-09-15','Regolare'),
(2,2023,3,'2023-09-15','Regolare'),
(3,2022,1,'2022-09-20','Regolare'),
(3,2023,2,'2023-09-20','Regolare'),
(3,2024,3,'2024-09-20','Regolare'),
(4,2020,1,'2020-09-10','Regolare'),
(4,2021,2,'2021-09-10','Regolare'),
(4,2022,3,'2022-09-10','Regolare'),
(5,2023,1,'2023-09-18','Regolare'),
(5,2024,2,'2024-09-18','Regolare'),
(6,2021,1,'2021-09-15','Regolare'),
(6,2022,2,'2022-09-15','Regolare'),
(6,2023,3,'2023-09-15','Regolare'),
(6,2024,4,'2024-09-15','Fuori Corso'),
(7,2022,1,'2022-09-20','Regolare'),
(7,2023,2,'2023-09-20','Regolare'),
(7,2024,3,'2024-09-20','Regolare'),
(8,2021,1,'2021-09-15','Regolare'),
(8,2022,2,'2022-09-15','Regolare'),
(8,2023,3,'2023-09-15','Regolare'),
(9,2021,1,'2021-09-15','Regolare'),
(9,2022,2,'2022-09-15','Regolare'),
(9,2023,3,'2023-09-15','Regolare'),
(10,2022,1,'2022-09-20','Regolare'),
(10,2023,2,'2023-09-20','Regolare'),
(10,2024,3,'2024-09-20','Regolare'),
(11,2023,1,'2023-09-18','Regolare'),
(11,2024,2,'2024-09-18','Regolare'),
(12,2020,1,'2020-09-10','Regolare'),
(12,2021,2,'2021-09-10','Regolare'),
(12,2022,3,'2022-09-10','Regolare'),
(12,2023,4,'2023-09-10','Fuori Corso'),
(13,2021,1,'2021-09-15','Regolare'),
(13,2022,2,'2022-09-15','Regolare'),
(13,2023,3,'2023-09-15','Regolare'),
(13,2024,4,'2024-09-15','Fuori Corso'),
(14,2022,1,'2022-09-20','Regolare'),
(14,2023,2,'2023-09-20','Regolare'),
(14,2024,3,'2024-09-20','Regolare'),
(15,2020,1,'2020-09-10','Regolare'),
(15,2021,2,'2021-09-10','Regolare'),
(15,2022,3,'2022-09-10','Regolare'),
(15,2023,4,'2023-09-10','Regolare'),
(15,2024,5,'2024-09-10','Regolare');
/*!40000 ALTER TABLE `iscrizione` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_laurea_controrelatore` FOREIGN KEY (`IdControRelatore`) REFERENCES `docente` (`IdDocente`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `fk_laurea_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `laurea`
--

LOCK TABLES `laurea` WRITE;
/*!40000 ALTER TABLE `laurea` DISABLE KEYS */;
INSERT INTO `laurea` VALUES
(1,2024,100,0,'2024-12-10','Sviluppo di applicazioni web scalabili',2),
(4,2022,105,0,'2023-03-20','Progettazione di sistemi elettronici avanzati',4),
(6,2024,108,0,'2024-12-12','La filologia romanza nel contesto mediterraneo',1),
(12,2023,110,1,'2023-12-15','Analisi critica della letteratura del Novecento',3),
(15,2024,110,1,'2024-10-18','Nuove frontiere nella terapia oncologica',5);
/*!40000 ALTER TABLE `laurea` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_matricola_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `fk_matricola_studente` FOREIGN KEY (`IdStudente`) REFERENCES `studente` (`IdStudente`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `matricolastudente`
--

LOCK TABLES `matricolastudente` WRITE;
/*!40000 ALTER TABLE `matricolastudente` DISABLE KEYS */;
INSERT INTO `matricolastudente` VALUES
(1,'2021-09-15',1,1),
(2,'2021-09-15',2,2),
(3,'2022-09-20',3,3),
(4,'2020-09-10',4,4),
(5,'2023-09-18',5,5),
(6,'2021-09-15',6,6),
(7,'2022-09-20',7,7),
(8,'2021-09-15',8,1),
(9,'2021-09-15',9,3),
(10,'2022-09-20',10,2),
(11,'2023-09-18',11,8),
(12,'2020-09-10',12,6),
(13,'2021-09-15',13,1),
(14,'2022-09-20',14,4),
(15,'2020-09-10',15,7);
/*!40000 ALTER TABLE `matricolastudente` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_relatore_docente` FOREIGN KEY (`IdDocente`) REFERENCES `docente` (`IdDocente`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_relatore_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `relatore`
--

LOCK TABLES `relatore` WRITE;
/*!40000 ALTER TABLE `relatore` DISABLE KEYS */;
INSERT INTO `relatore` VALUES
(1,1),
(3,4),
(6,6),
(2,12),
(4,15);
/*!40000 ALTER TABLE `relatore` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_studente_domicilio` FOREIGN KEY (`IdDomicilio`) REFERENCES `comune` (`IdComune`) ON UPDATE CASCADE,
  CONSTRAINT `fk_studente_residenza` FOREIGN KEY (`IdResidenza`) REFERENCES `comune` (`IdComune`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `studente`
--

LOCK TABLES `studente` WRITE;
/*!40000 ALTER TABLE `studente` DISABLE KEYS */;
INSERT INTO `studente` VALUES
(1,'MLNMHL05R26M208A','Michele','Molinaro','2000-01-01','M',0,1,1),
(2,'VRDGLL99B42F839K','Giulia','Verdi','1999-02-02','F',0,3,3),
(3,'BNCLCU01C15D086M','Luca','Bianchi','2001-03-15','M',0,2,2),
(4,'FRNMRT98D50H224L','Marta','Ferrari','1998-04-10','F',0,5,5),
(5,'CNTGVN02E20F839A','Giovanni','Conti','2002-05-20','M',0,3,1),
(6,'GRCLRA00F55H501B','Laura','Greco','2000-06-15','F',0,1,1),
(7,'MRNSFN01G12D086C','Stefano','Marino','2001-07-12','M',0,2,3),
(8,'CLMSLV99H48F839D','Silvia','Colombo','1999-08-08','F',0,3,3),
(9,'SMITHJHN00A01Z40','John','Smith','2000-01-01','M',1,NULL,1),
(10,'MLLRANA01B42Z100','Anna','Mueller','2001-02-02','F',1,NULL,2),
(11,'KHNMHMD02C15Z200','Mohamed','Khan','2002-03-15','M',1,NULL,5),
(12,'PTRSOFA99D50Z300','Sofia','Petrov','1999-04-10','F',1,NULL,6),
(13,'RCCFRN00E20H501I','Francesco','Molinaro','2002-05-20','M',0,1,2),
(14,'BRNGRT01F55D086J','Margherita','Bruno','2001-06-15','F',0,2,2),
(15,'GLLMRC98G12F839K','Marco','Gallo','1998-07-12','M',0,3,4);
/*!40000 ALTER TABLE `studente` ENABLE KEYS */;
UNLOCK TABLES;

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
  CONSTRAINT `fk_verifiche_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_verifiche_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_verifiche_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `verifichefinali`
--

LOCK TABLES `verifichefinali` WRITE;
/*!40000 ALTER TABLE `verifichefinali` DISABLE KEYS */;
INSERT INTO `verifichefinali` VALUES
(1,1,1,'2022-02-15',28,0,1,2021),
(1,2,1,'2022-07-10',30,1,1,2021),
(1,3,1,'2023-02-20',27,0,1,2022),
(1,4,1,'2023-07-15',26,0,1,2022),
(1,5,1,'2024-02-10',29,0,1,2023),
(2,6,2,'2022-02-10',30,1,1,2021),
(2,7,2,'2022-07-05',28,0,1,2021),
(2,8,2,'2023-02-15',29,0,1,2022),
(2,9,2,'2023-07-12',27,0,1,2022),
(3,6,3,'2023-07-20',28,0,1,2022),
(3,10,3,'2023-02-18',25,0,1,2022),
(3,11,3,'2024-02-15',26,0,1,2023),
(4,6,4,'2021-07-08',30,0,1,2020),
(4,13,4,'2021-02-10',27,0,1,2020),
(4,14,4,'2022-02-12',28,0,1,2021),
(4,15,4,'2022-07-10',29,0,1,2021),
(5,16,5,'2024-02-20',26,0,1,2023),
(6,19,6,'2022-02-15',30,1,1,2021),
(6,20,6,'2023-02-18',28,0,1,2022),
(6,21,6,'2023-07-14',27,0,1,2022),
(7,22,7,'2023-02-20',29,0,1,2022),
(7,23,7,'2023-07-15',28,0,1,2022),
(7,24,7,'2024-02-18',30,0,1,2023),
(8,1,1,'2022-02-12',24,0,1,2021),
(8,2,1,'2022-09-15',26,0,1,2021),
(8,3,1,'2023-02-18',25,0,1,2022),
(9,6,3,'2022-07-12',27,0,1,2021),
(9,10,3,'2022-02-15',28,0,1,2021),
(9,11,3,'2023-02-20',29,0,1,2022),
(10,6,2,'2023-02-10',30,1,1,2022),
(10,7,2,'2023-07-08',29,0,1,2022),
(10,8,2,'2024-02-15',28,0,1,2023),
(11,25,8,'2024-02-20',27,0,1,2023),
(12,19,6,'2021-02-10',28,0,1,2020),
(12,20,6,'2022-02-12',30,1,1,2021),
(12,21,6,'2022-07-10',29,0,1,2021),
(13,1,1,'2022-02-18',26,0,1,2021),
(13,2,1,'2022-07-15',27,0,1,2021),
(13,3,1,'2023-02-20',28,0,1,2022),
(13,4,1,'2023-07-18',25,0,1,2022),
(14,6,4,'2023-07-10',30,0,1,2022),
(14,13,4,'2023-02-15',29,0,1,2022),
(14,14,4,'2024-02-12',28,0,1,2023),
(15,22,7,'2021-02-10',30,1,1,2020),
(15,23,7,'2021-07-08',29,0,1,2020),
(15,24,7,'2022-02-15',28,0,1,2021);
/*!40000 ALTER TABLE `verifichefinali` ENABLE KEYS */;
UNLOCK TABLES;
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

--
-- Dumping routines for database 'progetto_db'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

-- Dump completed on 2026-02-04 13:09:20
