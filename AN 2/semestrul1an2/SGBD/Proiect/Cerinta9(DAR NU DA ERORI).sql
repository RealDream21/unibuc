SELECT * FROM USER_TABLES;
--Numele institutiilor de invatamant pe care le au absolvit membrii familiei cu cel mai mare contract la o companie data

CREATE OR REPLACE PROCEDURE procedura_cerinta_9
        (v_cumparator VARCHAR)
    IS
        TYPE info is RECORD
            (nume_institutie institutie_invatamant.nume%type,
            prenume locuitor.prenume%type,
            nume familie.nume_familie%type);
        TYPE tablou_indexat IS TABLE OF info INDEX BY pls_integer;
        t tablou_indexat;
    BEGIN
    SELECT ii.nume, l.prenume, f.nume_familie BULK COLLECT INTO t
    FROM CUMPARATOR c JOIN CONTRACT_CUMPARARE ccu ON c.id_cumparator = ccu.id_cumparator
        JOIN FAMILIE f ON f.id_familie = ccu.id_familie JOIN locuitor l ON l.id_familie = f.id_familie
        JOIN ciclu_invatamant ci ON ci.id_locuitor = l.id_locuitor JOIN institutie_invatamant ii ON ii.id_forma = ci.id_forma
    WHERE lower(c.nume) = lower(v_cumparator)
        AND ccu.suma = (SELECT max(suma) FROM contract_cumparare ccu2 WHERE ccu2.id_familie = l.id_familie AND ccu2.id_cumparator = c.id_cumparator);
    
    if(t.count > 0) THEN
        FOR i IN t.first..t.last LOOP
            DBMS_OUTPUT.PUT_LINE(t(i).nume || ' ' || t(i).prenume || ' a studiat la ' || t(i).nume_institutie);
        END LOOP;
    ELSE
        DBMS_OUTPUT.PUT_LINE('Nu a fost gasita vreo institutie de invatamant');
    END IF;
    
    ---NU DA ERORI??????????????---
    EXCEPTION
        WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('A aparut o eroare');
    
    END procedura_cerinta_9;
/

BEGIN
    procedura_cerinta_9('Global Solutions'); -- ar trebui sa dea eroare, dar nu da
END;
/
INSERT INTO CONTRACT_CUMPARARE
VALUES (2, 5, 25, '2-Jan-2024', 23, 800000);

SELECT * FROM contract_cumparare;

SELECT * FROM CUMPARATOR;
