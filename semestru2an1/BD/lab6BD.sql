--Ex 1
SELECT last_name, hire_Date
FROM employees
WHERE hire_date > (SELECT hire_date
                    FROM employees
                    WHERE lower(last_name) ='gates');
                    
--Ex 2
SELECT last_name, salary, department_id
FROM employees
WHERE department_id = (SELECT department_id
                        FROM employees
                        WHERE lower(last_name) = 'gates');
                        
--Ex 3
SELECT last_name, salary
FROM employees
WHERE manager_id in (SELECT employee_id
                    FROM employees
                    WHERE nvl(manager_id, 0) = 0);

--Ex 4
SELECT last_name, department_id, salary
FROM employees
WHERE (department_id, salary) in (SELECT department_id, salary
                                    FROM employees
                                    WHERE commission_pct is not null);

--Ex 6
SELECT *
FROM employees
WHERE salary > ALL(SELECT salary
                    FROM employees
                    WHERE lower(job_id) LIKE '%clerk%');
                    
--Ex 7
SELECT e.last_name, d.department_name, e.salary
FROM employees e join departments d ON e.department_id = d.department_id
WHERE e.commission_pct IS NULL AND e.manager_id IN(SELECT e1.employee_id
                                            FROM employees e1
                                            WHERE e1.commission_pct IS NOT NULL);

--Ex 9
SELECT e.last_name, e.department_id, e.job_id
FROM employees e JOIN departments d ON e.department_id = d.department_id
WHERE d.location_id = (SELECT l.location_id
                        FROM locations l
                        WHERE initcap(l.city) = 'Toronto');

--Ex 11
SELECT MAX(salary) maxim, MIN(salary) minim, SUM(salary) suma, ROUND(AVG(salary), 2) media
FROM employees;

--Ex 12
SELECT MIN(salary) minim, MAX(salary) maxim, ROUND(AVG(salary), 2) medie, job_id
FROM employees
GROUP BY job_id;

--Ex13
SELECT COUNT(*) nr_angajati, job_id job
FROM employees
GROUP BY job_id;

--Ex14
SELECT COUNT(*) AS "Nr. manageri"
FROM employees
GROUP BY manager_id
HAVING NVL(manager_id, 0) = 0;

--Ex15
SELECT MAX(salary) - MIN(salary) diferenta
FROM employees;

--Ex16
SELECT d.department_name AS "Nume Departament", l.location_id AS "ID Locație", COUNT(e.employee_id) AS "Număr Angajați", AVG(e.salary) AS "Salariu Mediu"
FROM departments d
JOIN employees e ON d.department_id = e.department_id
JOIN locations l ON d.location_id = l.location_id
GROUP BY d.department_name, l.location_id;

--Ex 17
SELECT e.employee_id, e.last_name
FROM employees e
WHERE e.salary > (SELECT avg(ee.salary)
                    FROM employees ee);
                    
--Ex 19
SELECT dd.department_id id_departament, max(ee.salary) max_salary
FROM departments dd join employees ee on dd.department_id = ee.department_id
WHERE dd.department_id IN(SELECT d.department_id
                        FROM employees e JOIN departments d ON e.department_id = d.department_id
                        GROUP by d.department_id
                        HAVING max(e.salary) > 3000)
GROUP by dd.department_id;


