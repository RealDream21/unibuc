--9
SELECT r.member_id,m.last_name, m.first_name, t.title, count(r.title_id) "Numar imprumuturi"
FROM rental r JOIN title t ON r.title_id = t.title_id
    JOIN member m ON m.member_id = r.member_id
GROUP BY r.member_id, t.title_id, t.title, m.last_name, m.first_name;

--10
SELECT r.member_id, m.last_name, m.first_name, copy_id "ID COPIE", count(copy_id) "NUMAR IMPRUMUTURI", title_id "TITLU FILM"
FROM rental r JOIN member m ON r.member_id = m.member_id
GROUP BY r.member_id, m.last_name, m.first_name, copy_id, title_id;

--11
WITH cele_mai AS(
    SELECT r.title_id, count(r.copy_id), t.title
    FROM rental r JOIN title t ON r.title_id = t.title_id
    GROUP BY r.title_id, t.title
    ORDER BY count(r.copy_id) desc
    )
SELECT c.title_id, tc.status, c.title
FROM cele_mai c JOIN title_copy tc ON c.title_id = tc.title_id
WHERE ROWNUM = 1;






