9 teme la laborator
nota proiect + punct teme + activitate = 10
laborator saptamanal


2.
a -> adevarat3
+
b -> adevarat
c -> fals
d -> adevarat

3.
a -> adevarat
b -> adevarat
c -> adevarat
d -> adevarat

4. d

5. c

6. a

7. a

8. c

9. c

!!SELECT *
FROM tabel1 JOIN tabel2
USING (id);!!
^^^schema^^^

10. d

--11
CREATE TABLE EMP_FFA AS SELECT * FROM EMPLOYEES;
COMMENT ON TABLE EMP_FFA IS 'Salutare';

--12
SELECT * FROM USER_TAB_COMMENTS;

--13
SELECT SYSDATE FROM DUAL;
ALTER SESSION SET NLS_DATE_FORMAT = 'DD-MM-YYYY HH:MI:SS';
SELECT SYSDATE FROM DUAL;

--14
SELECT EXTRACT(YEAR FROM SYSDATE)
FROM DUAL;

--15
SELECT EXTRACT(YEAR FROM DUAL), EXTRACT(MONTH FROM DUAL)
FROM DUAL; --????

--16
SELECT *
FROM USER_TABLES
WHERE table_name LIKE '%FFA%';

--17 AJUTA LA TEMA !!!
SPOOL D:\spooler\
SELECT 'DROP TABLE ' || table_name
FROM USER_TABLES
WHERE table_name LIKE '%FFA%';
SPOOL OFF;

--20
SET FEEDBACK OFF; --dispar chestii de genul 1 row selected
SET FEEDBACK ON;

--23
SPOOL D:\spooler\
SELECT 'INSERT INTO ' || 'DEPARTMENTS ' || 'VALUES (' 
|| department_id || ',' ||'''' || department_name || '''' || ')'
FROM DEPARTMENTS;
SPOOL OFF;

