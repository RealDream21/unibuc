--Obtineti pentru fiecare familie numarul de persoane care apartin acesteia. Daca familia nu are persoane se va afisa
--mesajul "Familia nu are locuitori"

CREATE OR REPLACE PROCEDURE p_cerinta7
IS
    TYPE cursor_ref IS REF CURSOR;
    CURSOR c_familie IS SELECT id_familie, nume_familie,
                    CURSOR(SELECT l.id_locuitor, l.prenume
                            FROM locuitor l
                            WHERE l.id_familie = f.id_familie)
            FROM familie f;         
    v_id_familie familie.id_familie%type;
    v_nume_familie familie.nume_familie%type;
    v_id_locuitor locuitor.id_locuitor%type;
    v_prenume locuitor.prenume%type;
    v_cursor cursor_ref;
    v_cnt NUMBER(5);
BEGIN
    OPEN c_familie;
    LOOP
        FETCH c_familie INTO v_id_familie, v_nume_familie, v_cursor;
        EXIT WHEN c_familie%NOTFOUND;
        v_cnt := 0;
        DBMS_OUTPUT.PUT_LINE('Afisez date pentru familia: ' || v_nume_familie);
        LOOP
            FETCH v_cursor INTO v_id_locuitor, v_prenume;
            EXIT WHEN v_cursor%NOTFOUND;
            v_cnt := v_cnt + 1;
            DBMS_OUTPUT.PUT_LINE(v_prenume);
        END LOOP;
        IF v_cnt = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Familia nu are locuitori');
        ELSE
            DBMS_OUTPUT.PUT_LINE('Familia are ' || v_cnt || ' persoane');
        END IF;
    END LOOP;
    CLOSE c_familie;
END p_cerinta7;
/

BEGIN
    p_cerinta7();
END;
/