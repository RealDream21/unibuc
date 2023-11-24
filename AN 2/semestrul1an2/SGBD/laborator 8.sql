--Tema: ex lab 7 -> 3, 4, 5 (cursoare)

DECLARE
    v_nume employees.last_name%TYPE := Initcap('&p_nume'); 
    FUNCTION f1_ffa RETURN NUMBER IS
    salariu employees.salary%type; 
BEGIN
    SELECT salary INTO salariu 
    FROM employees
    WHERE last_name = v_nume;
    RETURN salariu;
EXCEPTION
   WHEN NO_DATA_FOUND THEN
       DBMS_OUTPUT.PUT_LINE('Nu exista angajati cu numele dat');
   WHEN TOO_MANY_ROWS THEN
        RAISE_APPLICATION_ERROR(-20001, 'Exista mai multi angajati cu numele dat');
       --DBMS_OUTPUT.PUT_LINE('Exista mai multi angajati '|| ' cu numele dat');
WHEN OTHERS THEN
DBMS_OUTPUT.PUT_LINE('Alta eroare!');
END f1_ffa;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Salariul este '|| f1_ffa);
END;
/

SELECT * FROM EMPLOYEES;