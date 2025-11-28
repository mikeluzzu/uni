-- Tabella comune (nessuna dipendenza)
CREATE TABLE IF NOT EXISTS `comune` (
  `IdComune` int(11) NOT NULL AUTO_INCREMENT,
  `NomeComune` varchar(150) DEFAULT NULL,
  `NumeroAbitanti` int(11) DEFAULT NULL,
  PRIMARY KEY (`IdComune`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella studente (dipende da comune)
CREATE TABLE IF NOT EXISTS `studente` (
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
  CONSTRAINT `fk_studente_domicilio` FOREIGN KEY (`IdDomicilio`) REFERENCES `comune` (`IdComune`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `fk_studente_residenza` FOREIGN KEY (`IdResidenza`) REFERENCES `comune` (`IdComune`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella dipartimento (nessuna dipendenza)
CREATE TABLE IF NOT EXISTS `dipartimento` (
  `IdDipartimento` int(11) NOT NULL AUTO_INCREMENT,
  `NomeDipartimento` varchar(150) NOT NULL,
  PRIMARY KEY (`IdDipartimento`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella corsolaurea (dipende da dipartimento)
CREATE TABLE IF NOT EXISTS `corsolaurea` (
  `IdCorsoLaurea` int(11) NOT NULL AUTO_INCREMENT,
  `NomeCorsoLaurea` varchar(150) NOT NULL,
  `IdDipartimento` int(11) DEFAULT NULL,
  PRIMARY KEY (`IdCorsoLaurea`),
  UNIQUE KEY `IdCorsoLaurea` (`IdCorsoLaurea`),
  KEY `fk_corso_dipartimento` (`IdDipartimento`),
  CONSTRAINT `fk_corso_dipartimento` FOREIGN KEY (`IdDipartimento`) REFERENCES `dipartimento` (`IdDipartimento`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella matricolastudente (dipende da studente e corsolaurea)
CREATE TABLE IF NOT EXISTS`matricolastudente` (
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella iscrizione (dipende da matricolastudente)
CREATE TABLE IF NOT EXISTS`iscrizione` (
  `Matricola` int(11) NOT NULL,
  `AnnoAccademico` year(4) NOT NULL,
  `ProgressivoAnno` int(11) NOT NULL,
  `DataIscrizione` date NOT NULL,
  `Tipo` enum('Regolare','Non Regolare','Fuori Corso') DEFAULT NULL,
  PRIMARY KEY (`Matricola`,`AnnoAccademico`),
  CONSTRAINT `fk_iscrizione_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella insegnamento (nessuna dipendenza)
CREATE TABLE IF NOT EXISTS`insegnamento` (
  `IdInsegnamento` int(11) NOT NULL AUTO_INCREMENT,
  `NomeInsegnamento` varchar(150) NOT NULL,
  PRIMARY KEY (`IdInsegnamento`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella insegnamentoindirizzo (dipende da insegnamento e corsolaurea)
CREATE TABLE IF NOT EXISTS`insegnamentoindirizzo` (
  `IdInsegnamento` int(11) NOT NULL,
  `IdCorsoLaurea` int(11) NOT NULL,
  `Crediti` int(11) NOT NULL,
  `Anno` int(11) NOT NULL,
  `Semestre` int(11) NOT NULL,
  PRIMARY KEY (`IdInsegnamento`,`IdCorsoLaurea`),
  KEY `fk_insegnamento_indirizzo_corso` (`IdCorsoLaurea`),
  CONSTRAINT `fk_insegnamento_indirizzo_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_insegnamento_indirizzo_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella docente (nessuna dipendenza)
CREATE TABLE IF NOT EXISTS`docente` (
  `IdDocente` int(11) NOT NULL AUTO_INCREMENT,
  `CodiceFiscale` char(16) NOT NULL,
  `Nome` varchar(100) NOT NULL,
  `Cognome` varchar(100) NOT NULL,
  `Tipo` enum('Docente di ruolo','Collaboratore') DEFAULT NULL,
  PRIMARY KEY (`IdDocente`),
  UNIQUE KEY `CodiceFiscale` (`CodiceFiscale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella laurea (dipende da matricolastudente e docente)
CREATE TABLE IF NOT EXISTS`laurea` (
  `Matricola` int(11) NOT NULL,
  `AnnoAccademico` year(4) NOT NULL,
  `Voto` int(11) NOT NULL CHECK (`Voto` >= 66 AND `Voto` <= 110),
  `Lode` tinyint(1) NOT NULL,
  `DataLaurea` date NOT NULL,
  `Titolo` varchar(100) NOT NULL,
  `IdControRelatore` int(11) DEFAULT NULL,
  PRIMARY KEY (`Matricola`),
  KEY `fk_laurea_controrelatore` (`IdControRelatore`),
  CONSTRAINT `fk_laurea_controrelatore` FOREIGN KEY (`IdControRelatore`) REFERENCES `docente` (`IdDocente`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `fk_laurea_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella edizioneinsegnamento (dipende da insegnamento e corsolaurea)
-- SPOSTATA PRIMA DI docenza per risolvere dipendenze circolari
CREATE TABLE IF NOT EXISTS`edizioneinsegnamento` (
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella docenza (dipende da docente e edizioneinsegnamento)
CREATE TABLE IF NOT EXISTS`docenza` (
  `IdDocente` int(11) NOT NULL,
  `IdEdizioneInsegnamento` int(11) NOT NULL,
  PRIMARY KEY (`IdDocente`,`IdEdizioneInsegnamento`),
  KEY `fk_docenza_edizione` (`IdEdizioneInsegnamento`),
  CONSTRAINT `fk_docenza_docente` FOREIGN KEY (`IdDocente`) REFERENCES `docente` (`IdDocente`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_docenza_edizione` FOREIGN KEY (`IdEdizioneInsegnamento`) REFERENCES `edizioneinsegnamento` (`IdEdizioneInsegnamento`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella verifichefinali (dipende da matricolastudente, insegnamento e corsolaurea)
CREATE TABLE IF NOT EXISTS`verifichefinali` (
  `Matricola` int(11) NOT NULL,
  `IdInsegnamento` int(11) NOT NULL,
  `IdCorsoLaurea` int(11) NOT NULL,
  `DataVerifica` date NOT NULL,
  `Voto` int(11) DEFAULT NULL CHECK (`Voto` >= 18 AND `Voto` <= 30),
  `Lode` tinyint(1) DEFAULT NULL,
  `Validita` tinyint(1) DEFAULT NULL,
  `AnnoAccademico` year(4) DEFAULT NULL,
  PRIMARY KEY (`Matricola`,`IdInsegnamento`,`IdCorsoLaurea`,`DataVerifica`),
  KEY `fk_verifiche_insegnamento` (`IdInsegnamento`),
  KEY `fk_verifiche_corso` (`IdCorsoLaurea`),
  CONSTRAINT `fk_verifiche_corso` FOREIGN KEY (`IdCorsoLaurea`) REFERENCES `corsolaurea` (`IdCorsoLaurea`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_verifiche_insegnamento` FOREIGN KEY (`IdInsegnamento`) REFERENCES `insegnamento` (`IdInsegnamento`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_verifiche_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabella relatore (dipende da docente e matricolastudente)
CREATE TABLE IF NOT EXISTS`relatore` (
  `IdDocente` int(11) NOT NULL,
  `Matricola` int(11) NOT NULL,
  PRIMARY KEY (`IdDocente`,`Matricola`),
  KEY `fk_relatore_matricola` (`Matricola`),
  CONSTRAINT `fk_relatore_docente` FOREIGN KEY (`IdDocente`) REFERENCES `docente` (`IdDocente`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_relatore_matricola` FOREIGN KEY (`Matricola`) REFERENCES `matricolastudente` (`Matricola`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;