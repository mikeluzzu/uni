/*!50003 CREATE*/ 
/*!50017 DEFINER=`root`@`localhost`*/ 
/*!50003 TRIGGER check_iscrizione_regolare
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









