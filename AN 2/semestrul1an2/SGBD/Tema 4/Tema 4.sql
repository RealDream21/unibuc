--ex 2
--a
with zile_din_luna AS(
    SELECT to_char(trunc(sysdate, 'MONTH') + (LEVEL - 1), 'DD-MM-YYYY') zi
    FROM DUAL
    CONNECT BY LEVEL <= EXTRACT (DAY FROM LAST_DAY(sysdate))
    )
SELECT zi, count(copy_id) carti_imprumutate
FROM rental r RIGHT JOIN zile_din_luna z ON to_char(r.book_date, 'DD-MM-YYYY') = z.zi
GROUP BY zi
ORDER BY zi asc;

--b
CREATE TABLE octombrie_FFA(
    id NUMBER(4) PRIMARY KEY,
    data DATE NOT NULL
);

DECLARE
    v_startID NUMBER(4) := 1;
    v_data DATE;
    maxim NUMBER(2) := to_number(to_char(LAST_DAY(SYSDATE), 'dd'));
BEGIN
    LOOP
        v_data := SYSDATE + v_startID;
        INSERT INTO octombrie_FFA
        VALUES (v_startID, v_data);
        v_startID := v_startID + 1;
        EXIT WHEN v_startID > maxim;
    END LOOP;
END;
/

--ex 4 + 5
DECLARE
    v_nrFilme number(10);
    v_nume member.last_name%type := '&nume';
    v_prenume member.first_name%type := '&prenume';
    v_memID member.member_id%type;
    v_titluriTotale number(10);
    v_procentaj FLOAT(10);
BEGIN
    SELECT member_id 
    INTO v_memID
    FROM member
    WHERE lower(last_name) = lower(v_nume) AND lower(first_name) = lower(v_prenume);
    
    SELECT count(copy_id)
    INTO v_nrFilme
    FROM rental
    GROUP BY member_id
    HAVING member_id = v_memID;
    DBMS_OUTPUT.PUT_LINE(v_nrFilme);

    SELECT count(copy_id)
    INTO v_titluriTotale
    FROM rental;
    
    v_procentaj := v_nrFilme/v_titluriTotale;
    DBMS_OUTPUT.PUT_LINE(v_procentaj);
    
    IF v_procentaj >= 0.75 THEN
        DBMS_OUTPUT.PUT_LINE('A imprumutat mai mult de 75% din titlurile existente');
        UPDATE member_ffa
        SET discount = 0.1
        WHERE member_id = v_memID;
        DBMS_OUTPUT.PUT_LINE('A fost aplicat un discount de 10%');
    ELSIF v_procentaj >= 0.50 THEN
        DBMS_OUTPUT.PUT_LINE('A imprumutat mai mult de 50% din titlurile existente');
        UPDATE member_ffa
        SET discount = 0.05
        WHERE member_id = v_memID;
        DBMS_OUTPUT.PUT_LINE('A fost aplicat un discount de 5%');
    ELSIF v_procentaj >= 0.25 THEN
        DBMS_OUTPUT.PUT_LINE('A imprumutat mai mult de 25% din titlurile existente');
        UPDATE member_ffa
        SET discount = 0.03
        WHERE member_id = v_memID;
        DBMS_OUTPUT.PUT_LINE('A fost aplicat un discount de 3%');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Altfel');
    END IF;
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_output.put_line('Nu exista membrul');
    WHEN TOO_MANY_ROWS THEN
        DBMS_output.put_line('Eroare');
    WHEN OTHERS THEN
        DBMS_output.put_line('Alta');
END;
/



