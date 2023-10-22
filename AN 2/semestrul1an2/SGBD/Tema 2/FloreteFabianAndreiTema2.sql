--ex 7 a)
SELECT count(*) as statusuri_eronate
FROM title_copy tc JOIN (SELECT title_id, copy_id, 
                            CASE
                                WHEN act_ret_date is NULL then 0
                                ELSE 1
                            END actual_status
                            FROM rental) rent
                    ON tc.copy_id = rent.copy_id AND tc.title_id = rent.title_id
WHERE DECODE(lower(status), 'rented', 0, 1) != actual_status;

--ex 7 b)
UPDATE title_copy_ffa tcf
SET status = DECODE((SELECT actual_status FROM (SELECT tc.title_id, tc.copy_id, status, actual_status
FROM title_copy tc JOIN (SELECT title_id, copy_id, 
                            CASE
                                WHEN act_ret_date is NULL then 0
                                ELSE 1
                            END actual_status
                            FROM rental) rent
                    ON tc.copy_id = rent.copy_id AND tc.title_id = rent.title_id
WHERE DECODE(lower(status), 'rented', 0, 1) != actual_status) sg WHERE sg.title_id = tcf.title_id AND sg.copy_id = tcf.copy_id), 0, 'Unavailable', 'Available');

--ex 8
WITH imprumutate_la_timp AS(
    SELECT count(*)
    FROM reservation res JOIN rental r ON res.title_id = r.title_id 
    WHERE res.res_date = r.book_date
    )
SELECT
    CASE
        WHEN (SELECT * FROM imprumutate_la_timp) = (SELECT count(*) FROM reservation) THEN 'Da'
        ELSE 'Nu'
    END Valoare
FROM imprumutate_la_timp;