--23 De terminat
SPOOL D:\spooler\
SELECT 'INSERT INTO ' || 'DEPARTMENTS ' || 'VALUES (' 
|| department_id || ',' ||'''' || department_name || '''' || ')'
FROM DEPARTMENTS;
SPOOL OFF;

--17. Generati automat un script SQL care sa stearga toate tabelele din baza de date
SPOOL 'C:\Users\Fabi\Desktop\unibuc folder\unibuc\AN 2\semestrul1an2\SGBD\Tema1\'
SELECT 'DROP TABLE ' || table_name || ';'
FROM user_tables;
SPOOL OFF;

--23. Generati un script SQL care reintroduce toate datele in tabela FAMILIE
SPOOL 'C:\Users\Fabi\Desktop\unibuc folder\unibuc\AN 2\semestrul1an2\SGBD\Tema1'
SELECT 'INSERT INTO FAMILIE VALUES (' || id_familie || ',' || id_primarie || ',' || '''' || nume_familie || '''' || ');'
FROM FAMILIE;
SPOOL OFF;