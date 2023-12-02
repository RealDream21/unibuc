--Sa se mareasca contractele de cumparare cu suma >= 10.000 cu inca 10 . Afisati contractele modificate(dupa)
--din acest nou tablou sa se pastreze intr un vector doar familiile care au avut contracte cu cumparatorul cu id 1. Daca nu exista => se afiseaza un mesaj de eroare


SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE p_cerinta6        
IS
    TYPE tablou_indexat IS TABLE OF contract_cumparare%rowtype INDEX BY PLS_INTEGER;
    t_contracte tablou_indexat;
    
    TYPE vector IS VARRAY(20) OF contract_cumparare%rowtype;
    t_vector vector:=vector();
    
    TYPE tablou_imbricat IS TABLE OF contract_cumparare%rowtype;
    t_contracte_sterse tablou_imbricat := tablou_imbricat();
    
BEGIN
    SELECT id_primarie, id_cumparator, id_familie, data_cumparare, taxa, suma BULK COLLECT INTO t_contracte
    FROM contract_cumparare;
        
    FOR i in t_contracte.FIRST..t_contracte.LAST LOOP
        IF(t_contracte(i).suma >= 10000) THEN
            t_vector.extend;
            t_vector(t_vector.count) := t_contracte(i);
        END IF;
    END LOOP;
    
    FOR i in t_vector.first..t_vector.last LOOP
        t_contracte_sterse.extend;
        UPDATE contract_cumparare
        SET suma = suma + 0.01*suma
        WHERE id_cumparator = t_vector(i).id_cumparator
            AND id_familie = t_vector(i).id_familie
            AND data_cumparare = t_vector(i).data_cumparare
        RETURNING id_primarie, id_cumparator, id_familie, data_cumparare, taxa, suma
        INTO t_contracte_sterse(i);
    END LOOP;
    
    FOR i in t_contracte_sterse.first..t_contracte_sterse.last LOOP
        DBMS_OUTPUT.PUT_LINE(t_contracte_sterse(i).id_familie || ' ' || t_contracte_sterse(i).suma);
    END LOOP;
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Nu au fost gasite contracte');
END p_cerinta6;
/


BEGIN
    p_cerinta6;
    rollback;
END;
/
