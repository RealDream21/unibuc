--4
WITH nr_categorii AS(
    SELECT count(*) nr, t.category categorie
    FROM title t JOIN title_copy tc ON t.title_id = tc.title_id JOIN rental r ON r.title_id = tc.title_id AND r.copy_id = tc.copy_id
    GROUP BY t.category)
SELECT max(nr) nr_filme_imprumutate
FROM nr_categorii nc;

--5
WITH carti_libere AS(
    SELECT t.title_id, tc.copy_id
    FROM title_copy tc JOIN title t ON t.title_id = tc.title_id
    AND (tc.copy_id, tc.title_id) NOT IN (SELECT copy_id, title_id FROM rental WHERE act_ret_date IS NULL)
    )
SELECT title_id, count(*) copii_libere
FROM carti_libere
GROUP BY title_id;

--6
WITH status_corect AS(
    SELECT title_id, copy_id
    FROM title_copy
    WHERE (title_id, copy_id) NOT IN (SELECT copy_id, title_id FROM rental WHERE act_ret_date IS NULL)
    )
SELECT 
    CASE
        WHEN (t.title_id, tc.copy_id) IN (SELECT * FROM STATUS_CORECT) THEN  'Available'
        WHEN (t.title_id, tc.copy_id)  NOT IN (SELECT * FROM STATUS_CORECT) THEN 'Unavailable'
    END, t.title
FROM title_copy tc JOIN title t ON tc.title_id = t.title_id; 


--12 b
SELECT to_date(book_date) zi, count(copy_id) carti_imprumutate
FROM rental
WHERE EXTRACT(month from book_date) = EXTRACT(month FROM to_date(sysdate))
GROUP by to_date(book_date);

--12 c
with zile_din_luna AS(
    SELECT to_char(trunc(sysdate, 'MONTH') + (LEVEL - 1), 'DD-MM-YYYY') zi
    FROM DUAL
    CONNECT BY LEVEL <= EXTRACT (DAY FROM LAST_DAY(sysdate))
    )
SELECT zi, count(copy_id) carti_imprumutate
FROM rental r RIGHT JOIN zile_din_luna z ON to_char(r.book_date, 'DD-MM-YYYY') = z.zi
GROUP BY zi
ORDER BY zi asc;
    
    