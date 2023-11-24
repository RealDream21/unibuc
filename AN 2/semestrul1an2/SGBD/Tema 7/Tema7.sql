--Ex 1 -> d
DECLARE
    TYPE refcursor IS REF CURSOR;
    CURSOR c_joburi IS
        SELECT DISTINCT job_id,
                CURSOR (SELECT last_name, salary
                        FROM employees e
                        WHERE e.job_id = e1.job_id)
        FROM employees e1;

    v_cursor refcursor;

    v_job employees.job_id%TYPE;
    v_nume employees.last_name%TYPE;
    v_salary employees.salary%TYPE;
BEGIN
    OPEN c_joburi;
    LOOP
        FETCH c_joburi INTO v_job, v_cursor;
        EXIT WHEN c_joburi%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Numele jobului: ' || v_job);
        LOOP
            FETCH v_cursor INTO v_nume, v_salary;
            EXIT WHEN v_cursor%NOTFOUND;
            DBMS_OUTPUT.PUT_LINE('Nume: ' || v_nume || ' salariu ' || v_salary);
        END LOOP;
    END LOOP;
    CLOSE c_joburi; 
END;
/

--Ex 2
DECLARE
    CURSOR c_joburi IS 
        SELECT job_id, count(*), avg(salary) medie, sum(salary) total
        FROM employees
        GROUP BY job_id;
    
    v_job employees.job_id%TYPE;
    v_emp_cnt NUMBER(5);
    v_counter NUMBER(5);
    v_medie NUMBER(10);
    v_total NUMBER(10);
    
BEGIN
    OPEN c_joburi;
    v_counter := 0;
        LOOP
            FETCH c_joburi INTO v_job, v_emp_cnt, v_medie, v_total;
            EXIT WHEN c_joburi%NOTFOUND;
            DBMS_OUTPUT.PUT_LINE('Job: ' || v_job || ' medie: ' || v_medie || ' total ' || v_total || ' nr angajati: ' || v_emp_cnt);
        END LOOP;
    CLOSE c_joburi;
END;
/

--Ex 6
--aflati locuitorii fiecarei familii folosind cursoare
DECLARE
    CURSOR c_familie IS 
        SELECT DISTINCT id_familie
        FROM familie;
    CURSOR c_locuitor IS 
        SELECT prenume, id_familie
        FROM locuitor;
    
    v_familie familie.id_familie%TYPE;
    v_prenume locuitor.prenume%TYPE;
    v_id_familie locuitor.id_familie%TYPE;
BEGIN
    OPEN c_familie;
    LOOP
        FETCH c_familie INTO v_familie;
        EXIT WHEN c_familie%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Familia: ' || v_familie);
        OPEN c_locuitor;
        LOOP
            FETCH c_locuitor INTO v_prenume, v_id_familie;
            EXIT WHEN c_locuitor%NOTFOUND;
            IF v_id_familie = v_familie THEN
                DBMS_OUTPUT.PUT_LINE('Prenumele persoanei: ' || v_prenume);
            END IF;
        END LOOP;
        CLOSE c_locuitor;
    END LOOP;
    CLOSE c_familie;
END;
/