--Creati un trigger care permite insert in tabela doar in zilele de luni si miercuri,
--update doar vinerea si delete doar in weekend


CREATE OR REPLACE TRIGGER trigger_cerinta_10
BEFORE INSERT OR UPDATE OR DELETE ON PRIMARIE_EVENIMENT
BEGIN
    DBMS_OUTPUT.PUT_LINE(lower(to_char(sysdate,'DAY')));
	IF (INSERTING AND (trim(lower(to_char(sysdate, 'DAY'))) != 'monday' AND trim(lower(to_char(sysdate, 'DAY'))) != 'tuesday')) THEN
    	RAISE_APPLICATION_ERROR(-20001, 'nu puteti introduce valori in zilele de luni sau miercuri');
	ELSIF (UPDATING AND (trim(lower(to_char(sysdate, 'DAY'))) != 'friday')) THEN
        RAISE_APPLICATION_ERROR(-2001, 'nu puteti face update decat vinerea');
	ELSIF (DELETING AND (trim(lower(to_char(sysdate, 'DAY'))) != 'saturday' AND trim(lower(to_char(sysdate, 'DAY'))) != 'sunday')) THEN
        RAISE_APPLICATION_ERROR(-20001, 'nu puteti face delete decat in week-end');
	END IF;
END;
/

--SELECT * FROM primarie_eveniment; -- testata pentru luni/miercuri-> merge
INSERT INTO PRIMARIE_EVENIMENT
VALUES(1, 1, '12-Jan-2023');
SELECT * FROM PRIMARIE_EVENIMENT;

rollback;



