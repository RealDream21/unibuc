--Tema; Ex 1 -> d, Ex2, Ex6
DECLARE
    v_departamente departments%rowtype;
    v_angajati employees%rowtype;

    CURSOR c_cursor_departamente is 
        SELECT * FROM DEPARTMENTS
        WHERE department_id IN (10, 20, 30, 40);
    CURSOR c_cursor_angajati IS
        SELECT * FROM EMPLOYEES;
BEGIN
    OPEN c_cursor_departamente;
    LOOP
        EXIT WHEN c_cursor_departamente%NOTFOUND;
        FETCH c_cursor_departamente INTO v_departamente;
        DBMS_OUTPUT.PUT_LINE('Afisez pentru departamentul: ' || v_departamente.department_name);
        OPEN c_cursor_angajati;
            LOOP
                EXIT WHEN c_cursor_angajati%NOTFOUND;
                FETCH c_cursor_angajati INTO v_angajati;
                IF v_angajati.department_id = v_departamente.department_id 
                THEN
                    DBMS_OUTPUT.PUT_LINE('Nume: ' || v_angajati.last_name);
                END IF;
            END LOOP;
            CLOSE c_cursor_angajati;
    END LOOP;
END;
/

SELECT * FROM EMPLOYEES;