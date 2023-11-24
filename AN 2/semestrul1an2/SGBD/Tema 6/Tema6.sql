--LABORATOR PLSQL3
--EX 1 -> a
DECLARE
    TYPE v_joburi IS VARRAY(30) OF employees.job_id%type;
    v v_joburi := v_joburi();
    
    v_angajat employees%rowtype;

    CURSOR c_cursor_job IS 
        SELECT * FROM EMPLOYEES;
BEGIN
    SELECT DISTINCT job_id
    BULK COLLECT INTO v
    FROM EMPLOYEES;
    
    FOR i in v.first..v.last LOOP
        DBMS_OUTPUT.PUT_LINE('Afisez angajatii pe postul: ' || v(i));
        OPEN c_cursor_job;
        LOOP
            FETCH c_cursor_job INTO v_angajat;
            EXIT WHEN c_cursor_job%NOTFOUND;
            IF lower(v_angajat.job_id) = lower(v(i)) THEN
                dbms_output.put_line('Nume angajat: ' || v_angajat.last_name || ', salariu: ' || v_angajat.salary);
            END IF;
        END LOOP;
        CLOSE c_cursor_job;
    END LOOP;
    
END;
/
--EX 1 -> b
DECLARE
    TYPE v_joburi IS VARRAY(30) OF employees.job_id%type;
    v v_joburi := v_joburi();

    CURSOR c_cursor_job IS 
        SELECT * FROM EMPLOYEES;
BEGIN
    SELECT DISTINCT job_id
    BULK COLLECT INTO v
    FROM EMPLOYEES;
    
    FOR i in v.first..v.last LOOP
        DBMS_OUTPUT.PUT_LINE('Afisez angajatii pe postul: ' || v(i));
        FOR v_angajat in C_cursor_job LOOP
            IF lower(v_angajat.job_id) = lower(v(i)) THEN
                dbms_output.put_line('Nume angajat: ' || v_angajat.last_name || ', salariu: ' || v_angajat.salary);
            END IF;
        END LOOP;
    END LOOP;
    
END;
/
--EX 1 -> c
DECLARE
    TYPE v_joburi IS VARRAY(30) OF employees.job_id%type;
    v v_joburi := v_joburi();

BEGIN
    SELECT DISTINCT job_id
    BULK COLLECT INTO v
    FROM EMPLOYEES;
    
    FOR i in v.first..v.last LOOP
        DBMS_OUTPUT.PUT_LINE('Afisez angajatii pe postul: ' || v(i));
        FOR v_angajat in (SELECT * FROM employees) LOOP
            IF lower(v_angajat.job_id) = lower(v(i)) THEN
                dbms_output.put_line('Nume angajat: ' || v_angajat.last_name || ', salariu: ' || v_angajat.salary);
            END IF;
        END LOOP;
    END LOOP;
    
END;
/

--Laborator PLSQL 2
--EX 4
--9
--definesc vectorul familie_ffa in care pun un nume de familie si niste copii
--EX 
SET SERVEROUTPUT ON;
CREATE OR REPLACE TYPE copii_ffa AS VARRAY(10) OF VARCHAR(20);
/
CREATE TABLE familie_ffa (cod_familie NUMBER(10) UNIQUE,
                            nume VARCHAR2(20),
                            lista_copii copii_ffa);
                            
DECLARE
    v_copii copii_ffa := copii_ffa('Costel', 'Marian', 'Ionel');
    v_lista familie_ffa.lista_copii%type;
BEGIN
    INSERT INTO familie_ffa
    VALUES (1, 'Popescu', copii_ffa('Andrei', 'Costelus'));
    
    INSERT INTO familie_ffa
    VALUES(2, 'Costea', null);
    
    INSERT INTO familie_ffa
    VALUES(3, 'Tudorescu', v_copii);
    
    SELECT lista_copii
    INTO v_lista
    FROM familie_ffa
    WHERE cod_familie = 1;
    
    FOR j in v_lista.first..v_lista.last LOOP
        dbms_output.put_line(v_lista(j));
    END LOOP;
    
END;
/

DROP TABLE FAMILIE_FFA;
DROP TYPE copii_ffa;

--10
--creati tabelul porcle_locuitor in care se insereaza o lista cu poreclele locuitorilor
CREATE OR REPLACE TYPE tip_porecle IS TABLE OF varchar(20);
/

CREATE TABLE test_locuitori AS (SELECT * FROM locuitor);
ALTER TABLE test_locuitori
ADD (porecla tip_porecle)
NESTED TABLE porecla STORE AS tabel_porecle;

UPDATE test_locuitori
SET porecla = tip_porecle('Piticu')
WHERE id_locuitor = 1;

UPDATE test_locuitori
SET porecla = tip_porecle('Ciungu', 'Cretu')
WHERE id_locuitor = 2;

INSERT INTO test_locuitori
VALUES(9, 30, 'Dorel',1 ,tip_porecle('Tiristu', 'Rapidu'));

DROP TABLE test_locuitori;
DROP TYPE tip_porecle;

