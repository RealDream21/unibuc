Ex 1)
a)2
b)'text 2'
c)'text 3 agaugat in sub-bloc'
d)101
e)'text 1 adaugat in blocul principal'
f)'text 2 adaugat in blocul principal'

TEMA -> ex2, 4, 5, 6


set SERVEROUTPUT on;
DECLARE
	v_nume varchar2(50) := 'A1';
    v_prenume v_nume%type;

BEGIN
	v_nume := ' A2';
	DBMS_output.put_line('Hello' || v_nume);	

END;
/

describe employees;


DECLARE
    v_dep departments.department_name%TYPE;
    v_nrAng number(5);
BEGIN
     SELECT department_name, count(e.employee_id)
     INTO v_dep, v_nrAng
     FROM employees e, departments d
     WHERE e.department_id=d.department_id
     GROUP BY department_name
     HAVING COUNT(*) = (SELECT MAX(COUNT(*))
                        FROM employees
                        GROUP BY department_id);
    DBMS_OUTPUT.PUT_LINE('Departamentul '|| v_dep || ', nr angajati: ' || v_nrAng);
END;

SET VERIFY OFF
DECLARE
    v_cod employees.employee_id%TYPE:=&p_cod;
    v_bonus NUMBER(8);
    v_salariu_anual NUMBER(8);
BEGIN
    SELECT salary*12 
    INTO v_salariu_anual
    FROM employees 
    WHERE employee_id = v_cod;
    IF v_salariu_anual>=200001
        THEN v_bonus:=20000;
    ELSIF v_salariu_anual BETWEEN 100001 AND 200000
        THEN v_bonus:=10000;
    ELSE v_bonus:=5000;
END IF;
DBMS_OUTPUT.PUT_LINE('Bonusul este ' || v_bonus);
END;
/
SET VERIFY ON


DECLARE
    v_nrFilme number(10);
    v_nume member.last_name%type := &nume;
    v_prenume member.first_name%type := &prenume;
    v_memID member.member_id%type;
BEGIN
    SELECT member_id 
    INTO v_memID
    FROM member
    WHERE lower(last_name) = lower(v_nume) AND lower(first_name) = lower(v_prenume);
    
    SELECT count(copy_id)
    INTO v_nrFilme
    FROM rental
    GROUP BY member_id
    HAVING member_id = v_memID;
    DBMS_OUTPUT.PUT_LINE(v_nrFilme);
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_output.put_line('Nu exista membrul');
    WHEN TOO_MANY_ROWS THEN
        DBMS_output.put_line('Eroare');
    WHEN OTHERS
        DBMS_output.put_line('Alta');
END;
/

SELECT * FROM member;
SELECT * FROM rental;
