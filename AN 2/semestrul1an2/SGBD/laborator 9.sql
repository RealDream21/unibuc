--Tema 4, 7

CREATE TABLE info_ffa(
    UTILIZATOR VARCHAR2(50),
    DATA DATE,
    COMANDA VARCHAR2(50),
    NR_LINII NUMBER(5),
    EROARE VARCHAR2(200)
);

--utilizator -> select user from dual
--data -> sysdate
--comanda -> numele procedurii hardcodat
--nr_linii -> sql%rowcount
--eroare -> hardcodam eroarea -> la linii 0 sau null

CREATE OR REPLACE FUNCTION f2_ffa
    (v_nume employees.last_name%TYPE)
RETURN NUMBER IS
    v_last_name employees.last_name%type;
    BEGIN
        SELECT last_name INTO v_last_name
        FROM EMPLOYEES
        WHERE lower(last_name) = lower(v_nume);
        RETURN 0;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RETURN -1;
        WHEN TOO_MANY_ROWS THEN
            RETURN -2;
    END f2_ffa;
/

CREATE OR REPLACE PROCEDURE p4_ffa
    (v_nume employees.last_name%type)
    IS
        v_val_f2 NUMBER(5);
        v_user varchar2(50);
        v_rowcount NUMBER(5);
    BEGIN
        v_val_f2 := f2_ffa(v_nume);
        v_rowcount := sql%rowcount;
        SELECT user INTO v_user FROM dual;
        DBMS_OUTPUT.PUT_LINE(v_val_f2);
        IF v_val_f2 = 0 THEN
            INSERT INTO info_ffa
            VALUES(v_user, sysdate(), 'p4_ffa', v_rowcount, NULL);
        ELSE
            INSERT INTO info_ffa
            VALUES(v_user, sysdate(), 'p4_ffa', v_rowcount, '-10000');
        END IF;
        
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('A aparut o eroare');
    END p4_ffa;
/

BEGIN
    p4_ffa('Bell');
END;
/




CREATE OR REPLACE FUNCTION e3_ffa
    (v_oras locations.city%TYPE)
    IS
        v_numar NUMBER(5);
    WITH JOBURI_DIFERITE AS(
        SELECT employee_id, department_id
        FROM job_history
        GROUP BY employee_id,department_id
        HAVING count(job_id) >= 2
    )
    SELECT j.employee_id
    FROM joburi_diferite j JOIN departments d ON j.department_id = d.department_id JOIN
        locations l ON l.location_id = d.location_id
    WHERE lower(v_oras) = lower(l.city);
    
    EXCEPTION
        

END e3_ffa;
/


