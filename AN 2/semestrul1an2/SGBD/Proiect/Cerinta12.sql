--Trigger pe LDD care tine minte istoricul actiunilor

CREATE TABLE istoric_cerinta_11
    (utilizator VARCHAR2(30),
    actiune varchar2(50),
    data DATE);
    
CREATE OR REPLACE TRIGGER trigger_cerinta_11
    BEFORE CREATE OR DROP OR ALTER ON SCHEMA
BEGIN
    IF lower(SYS.SYSEVENT) = lower('create') THEN
        INSERT INTO ISTORIC_CERINTA_11
        VALUES(SYS.LOGIN_USER, 'Inserted in ' || SYS.DICTIONARY_OBJ_NAME, SYSDATE);
    ELSIF lower(SYS.SYSEVENT) = lower('alter') THEN
        INSERT INTO ISTORIC_CERINTA_11
        VALUES(SYS.LOGIN_USER, 'Altered table ' || SYS.DICTIONARY_OBJ_NAME, SYSDATE);
    ELSIF lower(SYS.SYSEVENT) = lower('drop') THEN
        INSERT INTO ISTORIC_CERINTA_11
        VALUES(SYS.LOGIN_USER, 'Dropped table ' || SYS.DICTIONARY_OBJ_NAME, SYSDATE);
    END IF;
END;
/
SET SERVEROUTPUT ON;

CREATE TABLE test1(atribut varchar2(30));
CREATE TABLE test2(atribut varchar2(30));
DROP TABLE test1;
DROP TABLE test2;
SELECT * FROM istoric_cerinta_11;
