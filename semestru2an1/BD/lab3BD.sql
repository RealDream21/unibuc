
--??: ex6, 

--ex1
SELECT e1.last_name, to_char(e1.hire_date, 'Month/yyyy')
FROM employees e1 JOIN (SELECT department_id
                        FROM employees
                        WHERE lower(last_name) = 'gates') e2
                    ON e1.department_id = e2.department_id
WHERE e1.department_id = e2.department_id AND lower(e1.last_name) LIKE ('%a%') and lower(last_name) != 'gates';

--ex2 maybe corect???
describe employees;
describe departments;
SELECT e1.employee_id, e1.last_name, e1.department_id, d.department_id, d.department_name
FROM employees e1 JOIN (SELECT DISTINCT department_id
                        FROM employees
                        WHERE LOWER(last_name) LIKE ('%t%')) e2 ON e1.department_id = e2.department_id JOIN departments d ON e1.department_id = d.department_id;
--ex3 14 rez
SELECT e.last_name, e.salary, l.city, c.country_name
FROM employees e JOIN (SELECT employee_id
                        FROM employees
                        where lower(last_name) = 'king') idking ON e.manager_id = idking.employee_id 
                JOIN departments d ON d.department_id = e.department_id
                JOIN locations l ON l.location_id = d.location_id
                JOIN countries c ON c.country_id = l.country_id;
                
--ex4
SELECT d.department_id, d.department_name, e.last_name, e.job_id, to_char(e.salary, '$99,999.00')
FROM employees e JOIN (SELECT department_id, department_name
                        FROM departments
                        WHERE department_name LIKE('%ti%')) d ON e.department_id = d.department_id;

--ex5
SELECT e.last_name, d.department_id, d.department_name, city, e.job_id
FROM departments d JOIN (SELECT location_id, city
                        FROM locations
                        WHERE lower(city) = 'oxford') l ON d.location_id = l.location_id JOIN employees e ON e.department_id = d.department_id;
                        
--ex6 ???
SELECT e1.employee_id, e1.last_name, e1.department_id, d.department_id, d.department_name
FROM employees e1 JOIN (SELECT DISTINCT department_id
                        FROM employees
                        WHERE LOWER(last_name) LIKE ('%t%')) e2 ON e1.department_id = e2.department_id JOIN departments d ON e1.department_id = d.department_id
where e1.salary > AVG(e1.salary);

--ex7 angajati fara departamente
SELECT e.last_name, d.department_name
FROM employees e LEFT OUTER JOIN departments d ON e.department_id = d.department_id;
FROM employees e JOIN departments d ON e.department_id = d.department_id(+);


--ex8 departamente fara angajati
SELECT e.last_name, d.department_name
FROM employees e RIGHT OUTER JOIN departments d ON e.department_id = d.department_id;
FROM employees e JOIN departments d ON e.department_id(+) = d.department_id;

--ex9 si departamente fara angajati si angajati fara departamente
SELECT e.last_name, d.department_name
FROM employees e FULL OUTER JOIN departments d ON e.department_id = d.department_id;

--ex10
describe employees;
SELECT department_id
FROM departments
WHERE department_name LIKE('%re%')
UNION
SELECT d.department_id
FROM employees e JOIN departments d ON e.department_id = d.department_id
WHERE e.job_id = 'SA_REP';

--ex12 !!!NULL!!!
SELECT department_id
FROM departments
WHERE department_id NOT IN(SELECT DISTINCT nvl(department_id, -1)
                            FROM employees);
SELECT department_id
FROM departments
MINUS
SELECT department_id
from employees;

--ex13
describe departments;
SELECT department_id
FROM departments
WHERE lower(department_name) LIKE ('%re%') AND department_id IN (SELECT department_id
                                                                FROM employees
                                                                WHERE lower(job_id) = 'hr_rep');
                                                        
--ex14 ??
describe employees;
SELECT employee_id, job_id, last_name, AVG(salary)
FROM employees
WHERE salary > 3000;



