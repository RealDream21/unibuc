--Exemplu
SELECT DISTINCT e.employee_id, count(p.project_id)
FROM employees e JOIN works_on w ON e.employee_id = w.employee_id JOIN project p ON w.project_id = p.project_id
WHERE p.budget = 10000
GROUP BY e.employee_id
HAVING count(p.project_id) = (SELECT count(*)
                                FROM project
                                WHERE project.budget = 10000);

--Ex 1. 
SELECT employee_id, count(project_id)
FROM works_on
WHERE to_char(start_date, 'MM') <= 6 AND to_char(start_date, 'YYYY') <= 2006
GROUP BY employee_id
HAVING count(project_id) = (SELECT count(*)
                            FROM project
                            WHERE to_char(start_date, 'MM') <= 6 AND to_char(start_date, 'YYYY') <= 2006);
                            
--Ex 2
WITH angajati AS(
        SELECT count(count(employee_id)) nr_ang
        FROM job_history
        GROUP BY employee_id
        HAVING count(job_id) >= 2),
    den_angajati AS(
        SELECT employee_id
        FROM job_history
        GROUP BY employee_id
        HAVING count(job_id) >= 2)
SELECT count(w.employee_id) nr_ang, project_id id_proiect
FROM works_on w JOIN den_angajati da ON w.employee_id = da.employee_id
GROUP BY project_id
HAVING count(w.employee_id) = (SELECT * from angajati);

--Ex 3
WITH candidati AS(
        SELECT employee_id
        FROM job_history
        GROUP BY employee_id
        HAVING count(job_id) >= 2)
SELECT e.last_name, e.employee_id
FROM candidati c JOIN employees e on c.employee_id = e.employee_id
WHERE EXISTS(   SELECT 'x'
                FROM employees e
                WHERE e.employee_id = c.employee_id AND job_id IS NOT NULL);
                
--Ex 4
SELECT count(e.employee_id), d.department_id, l.country_id
FROM employees e JOIN departments d ON e.department_id = d.department_id JOIN locations l ON l.location_id = d.location_id
GROUP BY d.department_id, l.country_id;

--Ex 5
WITH overdue_projects AS(
            SELECT project_id
            FROM project
            WHERE delivery_date > deadline)
SELECT w.employee_id, e.last_name
FROM works_on w JOIN employees e ON w.employee_id = e.employee_id
WHERE w.project_id IN (SELECT * FROM overdue_projects)
GROUP BY w.employee_id, e.last_name
HAVING count(w.project_id) >= 2;

--Ex 6
SELECT e.employee_id, e.last_name, nvl(w.project_id, 0)
FROM employees e LEFT OUTER JOIN works_on w  ON e.employee_id = w.employee_id;

--Ex 7
WITH manager_proiect AS(
        SELECT distinct project_manager
        FROM project)
SELECT e.last_name, e.employee_id
FROM employees e
WHERE e.department_id IN (SELECT e1.department_id FROM employees e1 WHERE e1.employee_id IN (SELECT * FROM manager_proiect));

--Ex 8
WITH manager_proiect AS(
        SELECT distinct project_manager
        FROM project)
SELECT e.last_name, e.employee_id
FROM employees e
WHERE e.department_id NOT IN (SELECT e1.department_id FROM employees e1 WHERE e1.employee_id IN (SELECT * FROM manager_proiect));

--Ex 9


