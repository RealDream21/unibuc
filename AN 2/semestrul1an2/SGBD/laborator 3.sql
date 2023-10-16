--SET SERVER.OUTPU ON; --> in caz ca nu apare output la PLSQL

--LABORATOR 3 TEMA EX 9 10 11 DIN LAB 2
SET SERVEROUTPUT ON;
DECLARE
    v_nr NUMBER(1) := 5;
BEGIN
    DBMS_OUTPUT.PUT_LINE(v_nr);
END;
/

BEGIN
    DBMS_OUTPUT.PUT_LINE('Salut');
END;
/