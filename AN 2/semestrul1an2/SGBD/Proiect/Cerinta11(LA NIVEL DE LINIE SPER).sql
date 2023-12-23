--Fac un declansator care nu las ca valoarea unui contract sa fie marita cu mai mult de 50% din valoarea acestuia
CREATE OR REPLACE TRIGGER trigger_cerinta_11
    BEFORE UPDATE ON contract_cumparare
    FOR EACH ROW
DECLARE
    v_exceptie EXCEPTION;
BEGIN
    IF(:OLD.suma + :OLD.suma*0.5) > :NEW.suma THEN
        RAISE v_exceptie;
    END IF;
EXCEPTION
    WHEN v_exceptie THEN
        RAISE_APPLICATION_ERROR(-20001, 'Suma noua a crescut cu mai mult de 50%');
    DBMS_OUTPUT.PUT_LINE('sal');
END;
/

UPDATE contract_cumparare
SET suma = suma*0.5 + 1000
WHERE id_primarie = 1;
ROLLBACK;
