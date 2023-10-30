--TEMA EX 1 SI 2


SET SERVEROUTPUT ON;
DECLARE
    TYPE t_tablou_indexat IS
        TABLE OF number(10)   --valoare
        INDEX BY PLS_INTEGER; --cheie
    t t_tablou_indexat;

BEGIN 
    t(5) := 10;
    DBMS_OUTPUT.PUT_LINE(t(5));

END;
/


DECLARE
    TYPE tablou_indexat IS TABLE OF NUMBER INDEX BY PLS_INTEGER;
    t tablou_indexat;
BEGIN
-- punctul a
    FOR i IN 1..10 LOOP
        t(i):=i;
    END LOOP;
    DBMS_OUTPUT.PUT('Tabloul are ' || t.COUNT ||' elemente: ');
    FOR i IN t.FIRST..t.LAST LOOP
        DBMS_OUTPUT.PUT(t(i) || ' '); 
    END LOOP;
    DBMS_OUTPUT.NEW_LINE;
-- punctul b
    FOR i IN 1..10 LOOP
        IF i mod 2 = 1 THEN t(i):=null;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT('Tabloul are ' || t.COUNT ||' elemente: ');
    
    FOR i IN t.FIRST..t.LAST LOOP
        DBMS_OUTPUT.PUT(nvl(t(i), 0) || ' '); 
    END LOOP;
    DBMS_OUTPUT.NEW_LINE;
-- punctul c
    t.DELETE(t.first);
    t.DELETE(5,7);
    t.DELETE(t.last);
    DBMS_OUTPUT.PUT_LINE('Primul element are indicele ' || t.first ||
                        ' si valoarea ' || nvl(t(t.first),0));
    DBMS_OUTPUT.PUT_LINE('Ultimul element are indicele ' || t.last ||
                        ' si valoarea ' || nvl(t(t.last),0));
 
    DBMS_OUTPUT.PUT('Tabloul are ' || t.COUNT ||' elemente: ');
    FOR i IN t.FIRST..t.LAST LOOP
        IF t.EXISTS(i) THEN 
            DBMS_OUTPUT.PUT(nvl(t(i), 0)|| ' '); 
        END IF;
    END LOOP;
    DBMS_OUTPUT.NEW_LINE;
-- punctul d
    t.delete;
    DBMS_OUTPUT.PUT_LINE('Tabloul are ' || t.COUNT ||' elemente.');
END;
/



DECLARE
    TYPE t_ang IS TABLE OF
        EMPLOYEES%ROWTYPE
    INDEX BY PLS_INTEGER;
    v_ang t_ang;
BEGIN
    SELECT * 
    BULK COLLECT INTO
    FROM employees;
END;
/

DECLARE
    TYPE t_tablou_imbricat IS
        TABLE OF NUMBER(10);
    
    t t_tablout_imbricat := t_tablou_imbricat();
BEGIN
    --t.extend(10);
    FOR i in 1..10 LOOP
        --sau extindem aici cu t.EXTEND;
        t.EXTEND;
        t(i) := i;
    END LOOP;
END;
/
