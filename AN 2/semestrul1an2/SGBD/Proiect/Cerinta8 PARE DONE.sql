--aflati strada casei unei familii cu un anumit nume(eroare daca nu exista id-ul), 
CREATE OR REPLACE FUNCTION f_cerinta8
    (v_nume familie.nume_familie%type)
    RETURN strada.nume_strada%TYPE
    IS
        v_nume_strada strada.nume_strada%type;
        v_cnt_familie NUMBER(2);
        v_id_strada strada.id_strada%type;
        v_numar_casa familie_casa.numar%type;
        v_data familie_casa.data_mutare%type;
        v_data2 familie_casa.data_mutare%type;
        ex_casa_ocupata EXCEPTION; -- prima exceptie, in caz ca sta cineva in casa lor deja
        ex_familie_negasita EXCEPTION;
        PRAGMA EXCEPTION_INIT(ex_casa_ocupata, -20001);
        PRAGMA EXCEPTION_INIT(ex_familie_negasita, -20002);
    BEGIN

    --prima data verific daca exita familia sau mai multe chiar cu acelasi nume
    SELECT count(nume_familie) INTO v_cnt_familie
    FROM familie
    WHERE lower(nume_familie) = lower(v_nume);
    
    IF v_cnt_familie = 0 THEN
        RAISE_APPLICATION_ERROR(-20002, 'Nu a fost gasita o familie cu acest nume');
    END IF;


    WITH aux AS(
        SELECT ss.id_strada, fc.numar, fc.data_mutare
        FROM familie_casa fc JOIN strada ss ON fc.id_strada = ss.id_strada JOIN familie f on f.id_familie = fc.id_familie
        WHERE lower(f.nume_familie) = lower(v_nume)
        ORDER BY data_mutare desc
    )
    SELECT * INTO v_id_strada, v_numar_casa, v_data
    FROM aux
    WHERE ROWNUM = 1;

    --verific daca in ultima lor casa nu cumva sta deja altcineva(lucru cauzat de eroare la validarea datelor)
    --gasesc ultima data la care s-a mutat cineva in acea casa
    WITH aux as(
        SELECT data_mutare
        FROM familie_casa
        WHERE id_strada = v_id_strada AND numar = v_numar_casa
        ORDER BY data_mutare desc)
    SELECT * INTO v_data2
    FROM aux
    WHERE ROWNUM = 1;
    
    IF v_data < v_data2 THEN
        RAISE_APPLICATION_ERROR(-20001, 'O familie deja sta la aceasta casa');
    END IF;
    
    SELECT nume_strada INTO v_nume_strada
    FROM strada
    WHERE id_strada = v_id_strada;
    
    return v_nume_strada;
    
    EXCEPTION
        WHEN EX_FAMILIE_NEGASITA THEN
            DBMS_OUTPUT.PUT_LINE('Nu a fost gasita o familie cu acest nume');
            return -1;
        WHEN EX_CASA_OCUPATA THEN
            DBMS_OUTPUT.PUT_LINE('A aparut o eroare la data casei');
            return -1;
END f_cerinta8;
/

BEGIN
    DBMS_output.put_line(f_cerinta8('Popescu')); --exemplu care produce eroare
    DBMS_output.put_line(f_cerinta8('Constantinescu')); -- exemplu care merge bine
    DBMS_output.put_line(f_cerinta8('haha')); --exemplu in care nu exista familia
END;
/
