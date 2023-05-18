--Ex 1
SELECT d.department_id, sum(e.salary), count(*), job_id
FROM employees e, departments d
WHERE e.department_id = d.department_id
GROUP BY d.department_id, e.job_id
order by 1;

--Ex 2
SELECT d.department_id, d.department_name, e.job_id, j.job_title, sum(e.salary)
FROM employees e JOIN departments d ON e.department_id = d.department_id JOIN jobs j on j.job_id = e.job_id
GROUP BY d.department_id, d.department_name, e.job_id, j.job_title;

--Ex 3
SELECT d.department_name, d.department_id, e.last_name
FROM DEPARTMENTS d JOIN employees e ON d.department_id = e.department_id
WHERE (d.department_id, e.salary) in (
with aux as(
SELECT AVG(e1.salary) medie, d1.department_id, min(e1.salary) minim
FROM departments d1 JOIN employees e1 ON e1.department_id = d1.department_id
GROUP BY d1.department_id
order by 1 desc)
SELECT department_id, minim
FROM aux
WHERE rownum = 1);

--Ex 4 cod, nume_dept, nr_ang
SELECT d.department_id id, d.department_name nume, count(e.department_id) nr_pers
FROM departments d JOIN employees e ON d.department_id = e.department_id
GROUP BY d.department_id, d.department_name
HAVING COUNT(*) < 4;

--gas cate pers lucreaza in fiecare departament, 0 pt cele in care nu lucreaza
SELECT aux.DEPARTMENT_ID, aux.DEPARTMENT_NAME, aux.nr_ang
FROM (SELECT d.DEPARTMENT_ID, D.DEPARTMENT_NAME, (SELECT count(employee_id)
                                                    FROM employees e
                                                    WHERE e.department_id = d.department_id) as nr_ang
        FROM departments d) aux
WHERE nr_ang < 4;


--Ex 5
with manevra as(
SELECT aux.formated wtf
FROM employees e, (SELECT DISTINCT to_char(hire_date, 'DD') formated
                    FROM employees) aux
WHERE to_char(e.hire_date, 'DD') = aux.formated
GROUP by aux.formated
HAVING count(e.employee_id) = (SELECT max(count(e.employee_id))
                                FROM employees e, (SELECT DISTINCT to_char(hire_date, 'DD') formated
                                                    FROM employees) aux
                                WHERE to_char(e.hire_date,'DD') = aux.formated
                                GROUP BY aux.formated))
SELECT *
FROM employees e, manevra
WHERE to_char(e.hire_date, 'DD') = manevra.wtf;

--Ex 6
SELECT count(*) nr_dept
FROM ( SELECT department_id
        FROM employees
        GROUP by department_id
        HAVING count(employee_id) >= 15);
        
--Ex 7
WITH departamente as(
SELECT department_id
FROM employees
group by department_id
HAVING department_id != 30 and count(employee_id) <= 10)
SELECT e.department_id dep_id , sum(e.salary) suma_sal
FROM employees e JOIN departamente ON e.department_id = departamente.department_id
GROUP BY e.department_id
ORDER BY 2 desc;

--Ex 8
WITH inf_departamente AS (
        SELECT e.department_id dept_id, count(e.employee_id) nr_ang, ROUND(avg(e.salary), 2) salariu, d.department_name dept_name
        FROM employees e JOIN departments d ON e.department_id = d.department_id
        GROUP BY e.department_id, d.department_name)
SELECT ifd.dept_id, ifd.dept_name, nr_ang, e.last_name, e.salary, e.job_id
FROM inf_departamentE ifd JOIN employees e ON ifd.dept_id = e.department_id
UNION
SELECT d.department_id, d.department_name, NULL, NULL, NULL, NULL
FROM departments d
WHERE d.department_id in (SELECT department_id
                            FROM departments
                            MINUS
                            SELECT DISTINCT d.department_id
                            FROM departments d join employees e on d.department_id = e.department_id);

--Ex 9
WITH departamente_bune AS(
                SELECT department_id, department_name, location_id
                FROM departments
                WHERE department_id > 80)
SELECT e.job_id, sum(e.salary), e.department_id, db.department_name, l.city
FROM employees e JOIN departamente_bune db ON e.department_id = db.department_id JOIN locations l ON db.location_id = l.location_id
GROUP BY e.job_id, e.department_id, db.department_name, db.location_id, l.city;

--Ex 10
WITH ang_nr_joburi as(
    SELECT employee_id, count(job_id) nr
    FROM job_history
    GROUP BY employee_id)
SELECT e.last_name, e.employee_id
FROM employees e JOIN ang_nr_joburi anj ON e.employee_id = anj.employee_id
where anj.nr >= 2;

--Ex 11
SELECT AVG(nvl(commission_pct, 0))
FROM employees;

SELECT SUM(commission_pct)/COUNT(*)
FROM employees;

--Ex 12
SELECT job_id, NVL(SUM(DECODE(department_id, 30, salary)), 0) Dep30,
                NVL(SUM(DECODE(department_id, 50, salary)), 0) Dep50,
                NVL(SUM(DECODE(department_id, 80, salary)), 0) Dep80, sum(salary) Total
FROM (SELECT * FROM employees where department_id = 30 OR department_id = 50 OR department_id = 80)
GROUP BY job_id;

--Ex 13
WITH manevra AS(
    SELECT to_char(hire_date, 'YYYY') an, count(*) nr
    FROM employees
    GROUP BY hire_date)
SELECT  NVL(SUM(DECODE(manevra.an, 1997, manevra.nr)), 0) AS "1997",
        NVL(SUM(DECODE(manevra.an, 1998, manevra.nr)), 0) AS "1998",
        NVL(SUM(DECODE(manevra.an, 1999, manevra.nr)), 0) AS "1999",
        NVL(SUM(DECODE(manevra.an, 2000, manevra.nr)), 0) AS "2000", sum(manevra.nr)
FROM manevra;

--Ex 14
WITH suma_dept AS(
        SELECT sum(salary) suma, department_id
        FROM employees
        GROUP BY department_id)
SELECT sd.suma, d.department_id, d.department_name
FROM suma_dept sd, departments d
WHERE d.department_id = sd.department_id;

--Ex 15 + 16
with inf_job AS(
        SELECT job_id id, avg(salary) medie, avg(salary) - (max(salary) - min(salary)) dif, count(employee_id) nr_ang
        FROM employees
        GROUP BY job_id)
SELECT j.job_title, ij.medie, ij.dif, ij.nr_ang
FROM inf_job ij JOIN jobs j ON ij.id = j.job_id;

--Ex 17
WITH min_sal_dept AS(
        SELECT min(e.salary) minsal, e.department_id, d.department_name
        FROM employees e JOIN departments d on e.department_id = d.department_id
        GROUP BY e.department_id, d.department_name)
SELECT d.department_name, last_name, e.salary
FROM employees e JOIN departments d on e.department_id = d.department_id
WHERE e.salary = (SELECT msd.minsal
                    FROM min_sal_dept msd
                    WHERE msd.department_id = e.department_id);