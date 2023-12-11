CREATE OR REPLACE PACKAGE
    E1_ffa AS
    --c)
    FUNCTION nr_subalterni
        (v_last_name EMPLOYEES.LAST_NAME%TYPE,
        v_first_name EMPLOYEES.FIRST_NAME%TYPE)
        RETURN NUMBER;
    --f)
    CURSOR ang(v_job_id employees.job_id%type)
        RETURN employees%rowtype;
END e1_ffa;
/

CREATE OR REPLACE PACKAGE BODY
    E1_ffa AS
    CURSOR ang(v_job_id employees.job_id%type)
        return employees%rowtype
        IS(SELECT * FROM employees WHERE job_id = v_job_id);
    FUNCTION nr_subalterni
        (v_last_name EMPLOYEES.LAST_NAME%TYPE,
        v_first_name EMPLOYEES.FIRST_NAME%TYPE)
        RETURN NUMBER IS
            v_cnt NUMBER;
            v_aux_cnt NUMBER;
            v_id EMPLOYEES.employee_id%TYPE;
        BEGIN
            --subalterni directi + recursiv
            v_cnt := 0;
            SELECT employee_ID INTO v_id
            FROM employees
            WHERE lower(last_name) = lower(v_last_name) AND lower(first_name) = lower(v_first_name);
            
            SELECT count(*) INTO v_cnt
            FROM EMPLOYEES
            START WITH employee_id = v_id
            CONNECT BY PRIOR employee_id = manager_id;
            RETURN v_cnt - 1;
        EXCEPTION
            WHEN no_data_found THEN
                RETURN -1;
            WHEN too_many_rows THEN
                DBMS_OUTPUT.PUT_LINE('Prea multi oameni cu acest nume');
                RETURN -2;
    END nr_subalterni;
end E1_ffa;
/

BEGIN
    FOR i IN E1_ffa.ang(
