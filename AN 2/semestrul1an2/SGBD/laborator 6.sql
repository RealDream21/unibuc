--SE DROPEAZA TIPURI CU DROP TYPE subordonati_ffa;
--tema ex 2 si 4
--ex 1 a, b, c cu 2 cursoare: 
--DECLARE
	CURSOR C1 IS
		(...)
	CURSOR C2 (JOB_ID, employees.job_id)
	BEGIN
		fOR i in C1
			for j in c2

CREATE TABLE emp_test_ffa AS 
 SELECT employee_id, last_name FROM employees
 WHERE ROWNUM <= 2;
/

CREATE OR REPLACE TYPE tip_telefon_ffa IS TABLE OF VARCHAR(12);
/

ALTER TABLE emp_test_ffa
ADD (telefon tip_telefon_ffa) 
NESTED TABLE telefon STORE AS tabel_telefon_ffa;


INSERT INTO emp_test_ffa
VALUES (500, 'XYZ',tip_telefon_ffa('074XXX', '0213XXX', '037XXX'));
UPDATE emp_test_ffa
SET telefon = tip_telefon_ffa('073XXX', '0214XXX')
WHERE employee_id=100;

SELECT a.employee_id, b.*
FROM emp_test_ffa a, TABLE (a.telefon) b;

DROP TABLE emp_test_ffa;
DROP TYPE tip_telefon_ffa;



---------------------LAB 6 ------------------

DECLARE
    CURSOR C IS
        (SELECT * FROM employees);
    v_ang EMPLOYEES%ROWTYPE;
BEGIN
    OPEN C;
    LOOP
        FETCH C INTO v_ang;
        EXIT WHEN C%NOTFOUND;
    END LOOP;
    CLOSE C;
END;
/

DECLARE
    CURSOR C IS
        (SELECT * FROM employees);
    v_ang EMPLOYEES%ROWTYPE;
BEGIN
    FOR I IN C LOOP
        DBMS_OUTPUT.PUT_LINE(I.last_name);
    END LOOP;
END;
/

BEGIN
    FOR I IN (SELECT * FROM EMPLOYEES) LOOP
        DBMS_OUTPUT.PUT_LINE(I.last_name);
    END LOOP;
END;
/



