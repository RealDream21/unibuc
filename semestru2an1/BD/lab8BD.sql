--Ex 1
--a + b
WITH medie_dept AS(
        SELECT avg(salary) medie, department_id dept_id
        FROM employees
        GROUP BY department_id)
SELECT last_name, salary, e.department_id, d.department_name, aux.nr_ang, aux.med_salar
FROM employees e JOIN departments d ON e.department_id = d.department_id JOIN (SELECT count(*) nr_ang, department_id, ROUND(avg(salary),2) med_salar FROM employees GROUP BY department_id) aux ON aux.department_id = d.department_id 
WHERE e.salary > (SELECT md.medie
                    FROM medie_dept md
                    WHERE md.dept_id = e.department_id);
                    
--Ex 2
SELECT first_name, last_name, salary
FROM employees
WHERE salary > ALL(SELECT avg(salary)
                    FROM employees
                    GROUP BY department_id);
                    
SELECT first_name, last_name, salary
FROM employees
WHERE salary > (SELECT max(avg(salary))
                    FROM employees
                    GROUP BY department_id);

--Ex 3
WITH min_sal AS(
        SELECT min(salary) mins, department_id
        FROM employees
        GROUP BY department_id)
SELECT last_name, salary
FROM employees e JOIN min_sal ms ON e.department_id = ms.department_id
WHERE e.salary = ms.mins;

--Ex 4
WITH dept_vech AS(
        SELECT min(hire_date) dang, department_id
        FROM employees
        GROUP by department_id)
SELECT d.department_name, first_name, last_name, hire_date
FROM employees e JOIN dept_vech ON e.department_id = dept_vech.department_id JOIN departments d ON d.department_id = e.department_id
WHERE e.hire_date = dept_vech.dang;

--Ex 5
WITH sal_max_dept30 AS(
        SELECT max(salary) value
        FROM employees
        GROUP BY department_id
        having department_id = 30)
SELECT last_name, salary
FROM employees e, sal_max_dept30
WHERE EXISTS(SELECT '*'
                FROM employees e1
                WHERE e1.department_id = e. department_id and salary = sal_max_dept30.value);
                
--Ex 6
SELECT *
FROM (  SELECT last_name, salary
        FROM employees
        ORDER by 2 desc) aux
WHERE rownum <= 3;

--Ex 7
with nr_subalterni AS(
        SELECT manager_id lider, count(employee_id) subalterni
        FROM employees
        GROUP BY manager_id)
SELECT e.employee_id, e.first_name
FROM employees e JOIN nr_subalterni nrs ON e.employee_id = nrs.lider
WHERE nrs.subalterni >= 2;

--Ex 8
SELECT DISTINCT l.location_id
FROM employees e JOIN departments d on e.department_id = d.department_id JOIN locations l ON l.location_id = d.location_id;

SELECT l.location_id
FROM locations l
WHERE EXISTS(SELECT 'x'
                FROM departments d
                WHERE d.location_id = l.location_id);

SELECT l.location_id
FROM locations l
WHERE l.location_id IN (SELECT d.location_id
                        FROM departments d
                        WHERE d.location_id = l.location_id);
                        
--Ex 9
SELECT distinct department_id
FROM departments
WHERE department_id is not null
MINUS
SELECT distinct department_id
FROM employees
WHERE department_id is not null;

SELECT d.department_id
FROM departments d
WHERE NOT EXISTS(SELECT '*'
                    FROM employees e
                    WHERE e.department_id = d.department_id);
                    
--Ex 10
WITH dept_good AS(
        SELECT sum(e.salary), e.department_id
        FROM employees e
        GROUP BY e.department_id
        HAVING sum(e.salary) > (  SELECT sum(e1.salary)/count(e1.employee_id)
                                FROM employees e1
                                GROUP BY e1.department_id
                                HAVING e1.department_id = e.department_id))
SELECT *
FROM dept_good;
        
        
WITH val_dep AS (
 select department_name, sum(salary) as total
 from departments d, employees e
 where e.department_id =d.department_id
 group by department_name),
val_medie AS (select sum(total)/count(*) as medie 
 from val_dep )
SELECT *
FROM val_dep
WHERE total > (SELECT medie
 FROM val_medie)
ORDER BY department_name;


--Ex 11
WITH emp_sk AS(
        SELECT employee_id, first_name, last_name, hire_date
        FROM employees
        WHERE manager_id = (SELECT employee_id
                            FROM employees
                            WHERE manager_id is null)
        ORDER BY 4 asc)
SELECT *
FROM emp_sk es
WHERE ROWNUM = 1;

--Ex 12
WITH top_salarii AS(
        SELECT job_id, last_name, salary
        FROM employees
        ORDER BY 3 desc)
SELECT *
FROM top_salarii
WHERE rownum <= 10;

--Ex 13
WITH medii_salariu AS(
            SELECT job_id, avg(salary)
            FROM employees
            GROUP BY job_id
            ORDER BY 2 asc)
SELECT *
FROM medii_salariu
WHERE rownum <= 3;

--Ex 14
SELECT job_id, avg(salary)
FROM employees
GROUP BY job_id
HAVING lower(job_id) like 's%';

WITH top_salarii AS (
  SELECT job_id, MAX(salary) AS max_salary
  FROM employees
  GROUP BY job_id
  ORDER BY max_salary DESC
)
SELECT e.job_id, AVG(e.salary) AS average_salary
FROM employees e
JOIN top_salarii ts ON e.job_id = ts.job_id
WHERE e.job_id = (SELECT job_id FROM top_salarii WHERE ROWNUM = 1)
GROUP BY e.job_id;

WITH min_salarii AS(
        SELECT job_id jid, min(salary) ms
        FROM employees
        GROUP BY job_id)
SELECT min(e.salary), e.job_id
FROM employees e JOIN min_salarii ms ON e.job_id = ms.jid
WHERE e.job_id = (SELECT jid FROM min_salarii WHERE ROWNUM = 1)
GROUP BY e.job_id;





                    