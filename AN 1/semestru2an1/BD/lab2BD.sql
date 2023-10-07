--ex5, 9 ???

--ex1
SELECT last_name ||' '|| CONCAT(first_name, 'castiga ') ||''|| salary || CONCAT(' lunar', ' dar doreste') || ' ' || salary*3 AS "Salariu ideal"
FROM employees; 

--ex2
SELECT INITCAP(first_name) ||' '|| UPPER(last_name) ||' '||length(last_name)
FROM employees
WHERE last_name LIKE('J%') or last_name LIKE('M%') or last_name LIKE('__a%')
ORDER BY length(last_name) desc; SELECT INITCAP(first_name) ||' '|| UPPER(last_name) ||' '||length(last_name)

SELECT INITCAP(first_name) ||' '|| UPPER(last_name) ||' '||length(last_name)
FROM employees
WHERE SUBSTR(last_name, 1, 1) = 'J' OR SUBSTR(last_name, 1, 1) = 'M' OR SUBSTR(last_name, 3, 1) = 'a'
ORDER BY length(last_name) DESC; 

--ex3
describe employees;
SELECT employee_id, last_name, department_id
FROM employees
WHERE lower(TRIM(BOTH ' ' FROM first_name)) = 'steven'; 

--ex4
SELECT employee_id, last_name, first_name, LENGTH(last_name), INSTR(LOWER(last_name), 'a')
FROM employees
WHERE LOWER(last_name) LIKE '%e'; --Functii pt date calendaristice
SELECT next_day('03/MAR/2023', 'Monday')
from dual; select last_day('11-feb-2024')
from dual; select TRUNC(SYSDATE)
from dual; select TO_CHAR(TRUNC(SYSDATE), 'dd/mm/yy HH24:MI')
from dual; 
--ex6????
SELECT employee_id, last_name, salary, ROUND((salary + (15/100)*salary), 2), ROUND(MOD((salary + (15/100)*salary)/100,1000),0)
from employees
WHERE MOD(salary, 1000) != 0; select nvl('a', 1)
from dual; select nvl(NULL, 1)
from dual; select nvl(1, 'ab') --considera ca rezultatul care trb afisat este un number. nu stie sa faca conversia lui 'ab' in numar
from dual; select nvl(1, '2') --stie sa faca conversia lui '2' in numar
from dual; SELECT nvl2(manager_id, 1, 0) --1 daca are manager, 0 daca nu are
from employees; 
SELECT nvl(to_char(manager_id), 'nu are manager') manager, manager_id --manevra este sa fie char si char nu number si char ca altfel nu merge
from employees; --sa se afiseze data peste 30 de zile
select to_char(sysdate+30, 'Month, Day, DD_MM_YYYY HH24:MI:SS')
from dual;

--ex7
SELECT last_name AS "Nume angajat", RPAD(to_char(hire_date,'dd/mm/yyyy'), 20, '~') AS "Data angajarii"
FROM employees
WHERE commission_pct IS NOT NULL;

--ex8
SELECT to_char(sysdate + 30, 'DAY/MONTH/YEAR, HH24:MI:SS')
FROM dual;

--ex9 ????
SELECT to_char(trunc(sysdate),'dd-mm-yy') - '31-dec-23'
from dual;

--ex10
SELECT TO_CHAR(sysdate + 1/2, 'dd-mm-yy')
FROM dual;
SELECT TO_CHAR(sysdate + 5/(24*60), 'dd-mm-yy')
FROM dual;

--ex11
SELECT last_name ||' '|| first_name ||' '||hire_date ||' '|| next_day(add_months(hire_date, 6), 'Monday') as Negociere
FROM employees;

--ex12
SELECT last_name ||' '|| round(months_between(sysdate, hire_date),0) AS "Luni lucrate"
FROM employees
ORDER BY months_between(sysdate, hire_date) DESC;

--ex13
SET DATEFIRST 1; --nu merge
SELECT last_name || ' ' || hire_date ||' ' || to_char(hire_date, 'Day') Zi
FROM employees
ORDER BY MOD(to_char(hire_date, 'D') + 5, 7) asc;

--ex14
describe employees;
SELECT last_name ||' '|| nvl(TO_CHAR(commission_pct), 'Fara comision') Comision
FROM employees;

--ex15
SELECT last_name ||' '|| salary ||' '|| commission_pct
FROM employees
WHERE salary + nvl(commission_pct,0)*salary > 10000;

--ex16
SELECT last_name, job_id, salary, salary + DECODE(job_id, 'IT_PROG', 20/100, 'SA_REP', 25/100, 'SA_MAN', 35/100, 0)*salary AS "Salariu renegociat"
FROM employees;
