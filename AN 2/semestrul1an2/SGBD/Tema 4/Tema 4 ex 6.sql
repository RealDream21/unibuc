--ex6 -> ex 5 adaptat
--Sa se afle numele primariei cu cele mai multe familii

SET SERVEROUTPUT ON;
DECLARE 
    v_numePrimarie primarie.nume%TYPE;
BEGIN
    WITH nr_primarii AS(
        SELECT id_primarie, count(id_familie) nr_familii
        FROM familie
        GROUP BY id_primarie
        ORDER BY nr_familii desc
    )
    SELECT nume
    INTO v_numePrimarie
    FROM primarie
    WHERE id_primarie IN (SELECT id_primarie FROM nr_primarii WHERE rownum = 1);
    DBMS_OUTPUT.PUT_LINE('Primaria cu cei mai multi locuitori este ' || v_numePrimarie);
END;
/

--ex6 -> ex 7 adaptat
-- determinati suma contractului maxim de cumparare si bonusul pe care il primeste o familie al carui cod este dat de la tastatura
--bonusul este calculat mai jos
DECLARE
    v_idFamilie familie.id_familie%TYPE := '&id';
    v_sumaContract contract_cumparare.suma%TYPE;
BEGIN
    SELECT max(suma)
    INTO v_sumaContract
    FROM contract_cumparare
    GROUP BY id_familie
    HAVING id_familie = v_idFamilie;
    
    IF v_sumaContract >= 50000 THEN
        DBMS_OUTPUT.PUT_LINE('Bonusul este de 10000');
    ELSIF v_sumaContract >= 25000 THEN 
        DBMS_OUTPUT.PUT_LINE('Bonusul este de 5000');
    ELSE
        DBMS_OUTPUT.PUT_LINE('BOnusul este de 1000');
    END IF;
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Nu a fost gasita familie');
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Au fost gasite mai multe familii cu acelasi ID');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Alta eroare');
END;
/

--ex 6 -> ex 9 adaptat
--sa se adauge o noua scoala absolvita unei persoane cu ID dat de la tastatura drept scoala declarata ca valoare de substitutie
--anul de invatamant este anul curent
DEFINE v_id_scoala_noua = 1
DECLARE
    v_id_locuitor ciclu_invatamant.id_locuitor%TYPE := '&id';
    v_id_scoala ciclu_invatamant.id_forma%TYPE := &v_id_scoala_noua;
BEGIN
    INSERT INTO ciclu_invatamant
    VALUES (v_id_scoala, v_id_locuitor, SYSDATE);
END;
/


