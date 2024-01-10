--Fac un declansator prin care nu las ca valoarea unui contract sa fie marita cu mai mult de 50% din valoarea acestuia
--sau sa scada cu mai mult de 2500 RON sub cat era inainte
CREATE OR REPLACE TRIGGER trigger_cerinta_11
    BEFORE UPDATE ON contract_cumparare
    FOR EACH ROW
DECLARE
    v_exceptie EXCEPTION;
BEGIN
    IF (:OLD.suma + :OLD.suma*0.5) < :NEW.suma AND (:NEW.suma - :OLD.suma > 0) THEN
        RAISE v_exceptie;
	ELSIF ((:NEW.suma - :OLD.suma) < -2500) THEN
        RAISE_APPLICATION_ERROR(-20001, 'Suma a scazut cu mai mult de 2500 lei');
    END IF;
EXCEPTION
    WHEN v_exceptie THEN
        RAISE_APPLICATION_ERROR(-20002, 'Suma noua a crescut cu mai mult de 50%');
    DBMS_OUTPUT.PUT_LINE('Suma a fost schimbata');
END;
/

UPDATE contract_cumparare
SET suma = suma + suma*0.5 + 1000
WHERE id_primarie = 1;
ROLLBACK;

UPDATE contract_cumparare
SET suma = suma - 2530
WHERE id_primarie = 1;
ROLLBACK;

UPDATE contract_cumparare
SET suma = suma + suma*0.1
WHERE id_primarie = 1;
ROLLBACK;
