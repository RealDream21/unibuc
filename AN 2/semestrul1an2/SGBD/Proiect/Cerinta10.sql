CREATE TABLE istoric_inserturi
(
    utilizator VARCHAR2(30),
    data_actualizare date
);

CREATE OR REPLACE TRIGGER trigger_cerinta_10
BEFORE INSERT ON PRIMARIE_EVENIMENT
BEGIN
    INSERT INTO ISTORIC_INSERTURI
    VALUES(SYS.LOGIN_USER, sysdate);
END;
/

SELECT * FROM primarie_eveniment;
INSERT INTO PRIMARIE_EVENIMENT
VALUES(1, 1, '12-Jan-2023');

SELECT * FROM istoric_inserturi;
ROLLBACK;

