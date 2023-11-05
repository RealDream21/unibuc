--EX 1
CREATE TABLE employees_ffa AS SELECT * FROM employees;
DECLARE
    TYPE ang_sal IS RECORD
        (cod employees.employee_id%TYPE, salariu employees.salary%TYPE);
    TYPE vector IS VARRAY(5) OF ang_sal;
    t vector := vector();
    
    TYPE ang_sal_marit IS RECORD
        (cod employees.employee_id%TYPE, salariu employees.salary%TYPE);
    TYPE vector_updatati IS VARRAY(5) OF ang_sal_marit;
    v_up vector_updatati := vector_updatati();

BEGIN
    WITH ordine AS(
        SELECT employee_id, salary
        FROM employees
        WHERE commission_pct is NULL
        ORDER BY SALARY ASC)
    SELECT employee_id, salary
    BULK COLLECT INTO t
    FROM ordine
    WHERE ROWNUM <= 5;
    
    FOR i IN 1..5 LOOP
        dbms_output.put_line('INAINTE: Cod: ' || t(i).cod ||' salariu: ' || t(i).salariu);
    END LOOP;
    
    FORALL i IN 1..5
        UPDATE employees_ffa ef
        SET ef.salary = ef.salary + 0.05 * ef.salary
        WHERE ef.employee_id = t(i).cod
        RETURNING ef.employee_id, ef.salary
        BULK COLLECT INTO v_up;
    
    FOR i IN 1..5 LOOP
        dbms_output.put_line('DUPA: Cod: ' || v_up(i).cod || ' salariu: ' || v_up(i).salariu);
    END LOOP;
END;
/
DROP TABLE employees_ffa;

--EX 2
DROP TABLE excursie_ffa;
CREATE OR REPLACE TYPE tip_orase_ffa AS VARRAY(10) OF VARCHAR(20);
/
CREATE TABLE excursie_ffa(
    cod_excursie NUMBER(4),
    denumire VARCHAR2(20),
    orase tip_orase_ffa,
    status NUMBER(1)
    );

--a
INSERT INTO excursie_ffa
VALUES (1, 'Excursie 1', tip_orase_ffa('Oras1', 'Oras2', 'Oras3'), 1);

INSERT INTO excursie_ffa (cod_excursie, denumire, orase, status)
VALUES (2, 'Excursie 2', tip_orase_ffa('Oras4', 'Oras5'), 1);

INSERT INTO excursie_ffa (cod_excursie, denumire, orase, status)
VALUES (3, 'Excursie 3', tip_orase_ffa('Oras6', 'Oras7', 'Oras8'), 0);

INSERT INTO excursie_ffa (cod_excursie, denumire, orase, status)
VALUES (4, 'Excursie 4', tip_orase_ffa('Oras9', 'Oras10', 'Oras11', 'Oras12'), 0);

INSERT INTO excursie_ffa (cod_excursie, denumire, orase, status)
VALUES (5, 'Excursie 5', tip_orase_ffa('Oras2', 'Oras1', 'Oras3'), 1);

--b
DECLARE
    v_orase tip_orase_ffa;
    v_orasSwap VARCHAR(20);
    v_n NUMBER(5);
    
    v_index1 NUMBER(2);
    V_index2 NUMBER(2);
BEGIN
    --adaugare ultimul oras
    SELECT orase INTO v_orase
    FROM excursie_ffa
    WHERE cod_excursie = 1;
    v_orase.extend;
    v_orase (v_orase.last) := 'Oras420';
    UPDATE excursie_ffa
    SET orase = v_orase
    WHERE cod_excursie = 1;
    
    --adaugare al doilea oras
    SELECT orase INTO v_orase
    FROM excursie_ffa
    WHERE cod_excursie = 1;
    v_n := v_orase.COUNT;
    FOR i in 2..v_n - 2 LOOP
        v_orase(v_n - i + 1) := v_orase(v_n - i);
    END LOOP;
    v_orase(2) := 'Oras8318';
    UPDATE excursie_ffa
    SET orase = v_orase
    WHERE cod_excursie = 1;
    
    --inversare ordine orase
    SELECT orase INTO v_orase
    FROM excursie_ffa
    WHERE cod_excursie = 1;
    
    FOR i in v_orase.first..v_orase.last LOOP
        IF lower(v_orase(i)) = 'oras1' THEN
            dbms_output.put_line('da');
            v_index1 := i;
        ELSIF lower(v_orase(i)) = 'oras2' THEN
            v_index2 := i;
        END if;
    END LOOP;
    
    v_orasSwap := v_orase(v_index1);
    v_orase(v_index1) := v_orase(v_index2);
    v_orase(v_index2) := v_orasSwap;
    UPDATE excursie_ffa
    SET orase = v_orase
    WHERE cod_excursie = 1;
    
    --eliminare oras
    SELECT orase INTO v_orase
    FROM excursie_ffa
    WHERE cod_excursie = 1;
    FOR i in v_orase.first..v_orase.last LOOP
        IF lower(v_orase(i)) = 'oras1' THEN
            v_index1 := i;
        END IF;
    END LOOP;
    
    FOR i in v_index1..v_orase.last - 1 LOOP
        v_orase(i) := v_orase(i + 1);
    END LOOP;
    
    UPDATE excursie_ffa
    SET orase = v_orase
    WHERE cod_excursie = 1;
END;
/

--c
DECLARE
    v_orase tip_orase_ffa;
    v_cod excursie_ffa.cod_excursie%TYPE := '&cod';

BEGIN
    SELECT orase INTO v_orase
    FROM excursie_ffa
    WHERE cod_excursie = v_cod;
    DBMS_OUTPUT.PUT_LINE('Numar orase: ' || v_orase.COUNT || ', Ordine parcurgere: ');
    
    FOR i in v_orase.first..v_orase.last LOOP
        DBMS_OUTPUT.PUT_LINE(v_orase(i));
    END LOOP;
END;
/

--d
DECLARE
    v_orase tip_orase_ffa;
    TYPE coduri IS VARRAY(20) OF NUMBER(3);
    v_coduri coduri := coduri();
BEGIN
    
    SELECT cod_excursie
    BULK COLLECT INTO v_coduri
    FROM excursie_ffa;
    
    FOR i in v_coduri.first..v_coduri.last LOOP
        SELECT orase INTO v_orase
        FROM excursie_ffa
        WHERE cod_excursie = v_coduri(i);
        DBMS_OUTPUT.PUT_LINE('Cod excursie: ' || v_coduri(i) || ' Numar orase: ' || v_orase.COUNT || ', Ordine parcurgere: ');
    
        FOR i in v_orase.first..v_orase.last LOOP
            DBMS_OUTPUT.PUT_LINE(v_orase(i));
        END LOOP;
    END LOOP;
END;
/
