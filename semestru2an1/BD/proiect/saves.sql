CREATE TABLE STRADA(
    id_strada NUMBER(3) PRIMARY KEY,
    nume_strada VARCHAR(100) NOT NULL
    );
    
CREATE TABLE INSTITUTIE_INVATAMANT(
    id_forma NUMBER(3) PRIMARY KEY,
    nume VARCHAR(50) NOT NULL,
    tip_forma_invatamant CHAR(15) NOT NULL,
    id_strada REFERENCES strada,
    numar NUMBER(2) NOT NULL,
    CONSTRAINT unic_numar_strada UNIQUE (id_strada, numar)
    );
    
CREATE TABLE CASA(
    id_strada REFERENCES strada,
    numar NUMBER(3)NOT NULL,
    camere NUMBER(2) DEFAULT 1 NOT NULL,
    dimensiune NUMBER(4) NOT NULL,
    PRIMARY KEY (id_strada, numar)
    );
    
CREATE TABLE PRIMARIE (
    id_primarie NUMBER(3) PRIMARY KEY,
    id_strada REFERENCES strada,
    numar NUMBER(3) NOT NULL,
    nume VARCHAR(100) NOT NULL,
    CONSTRAINT unic_strada_numar UNIQUE (id_strada, numar)
    );

CREATE TABLE FAMILIE(
    id_familie NUMBER(4) PRIMARY KEY,
    id_primarie REFERENCES PRIMARIE
    );
    
CREATE TABLE LOCUITOR(
    id_locuitor NUMBER(5) PRIMARY KEY,
    id_familie REFERENCES FAMILIE,
    nume VARCHAR(25) NOT NULL,
    prenume VARCHAR(50) NOT NULL,
    sex NUMBER(1) CHECK (sex > 0 and sex < 3)
    );

CREATE TABLE FIRMA_ORGANIZARE(
    id_firma NUMBER(3) PRIMARY KEY,
    nume VARCHAR(100) NOT NULL
    );
    
CREATE TABLE EVENIMENT_CULTURAL(
    id_eveniment NUMBER(3) PRIMARY KEY, 
    id_firma REFERENCES FIRMA_ORGANIZARE,
    nume_eveniment VARCHAR(25) NOT NULL,
    capacitate NUMBER(7) NOT NULL
    );

CREATE TABLE CUMPARATOR(
    id_cumparator NUMBER(3) PRIMARY KEY,
    nume VARCHAR(100) NOT NULL
    );

CREATE TABLE CICLU_INVATAMANT(
    id_forma_invatamant REFERENCES INSTITUTIE_INVATAMANT,
    id_locuitor REFERENCES locuitor,
    an_invatamant DATE NOT NULL,
    PRIMARY KEY (id_forma_invatamant, id_locuitor, an_invatamant)
    );
    
CREATE TABLE CONTRACT_CUMPARARE(
    id_primarie REFERENCES PRIMARIE,
    id_cumparator REFERENCES CUMPARATOR,
    id_familie REFERENCES FAMILIE,
    taxa NUMBER(3) DEFAULT 1,
    suma NUMBER(8) NOT NULL,
    PRIMARY KEY (id_primarie, id_cumparator, id_familie)
    );

CREATE TABLE FAMILIE_CASA(
    id_familie NUMBER(4),
    id_strada NUMBER(3),
    numar NUMBER(3),
    data_mutare DATE NOT NULL,
    PRIMARY KEY (id_familie, id_strada, numar, data_mutare),
    FOREIGN KEY (id_strada, numar) REFERENCES CASA (id_strada, numar),
    FOREIGN KEY (id_familie) REFERENCES FAMILIE (id_familie)
);

CREATE TABLE PRIMARIE_FIRMA_ORGANIZARE(
    id_primarie REFERENCES PRIMARIE,
    id_firma REFERENCES FIRMA_ORGANIZARE,
    data_contract DATE NOT NULL,
    PRIMARY KEY (id_primarie, id_firma, data_contract)
    );

DROP TABLE CONTRACT_CUMPARARE;
DROP TABLE CUMPARATOR;
DROP TABLE PRIMARIE_FIRMA_ORGANIZARE;
DROP TABLE EVENIMENT_CULTURAL;
DROP TABLE FIRMA_ORGANIZARE;
DROP TABLE CICLU_INVATAMANT;
DROP TABLE INSTITUTIE_INVATAMANT;
DROP TABLE LOCUITOR;
DROP TABLE FAMILIE_CASA;
DROP TABLE FAMILIE;
DROP TABLE CASA;
DROP TABLE PRIMARIE;
DROP TABLE STRADA;

INSERT INTO STRADA
VALUES(10, 'Teilor');
INSERT INTO STRADA
VALUES(11, 'Libertatii');
INSERT INTO STRADA
VALUES(12, 'Viilor');
INSERT INTO STRADA
VALUES(13, 'Crinului');
INSERT INTO STRADA
VALUES(14, 'Tineretului');
INSERT INTO STRADA
VALUES(15, 'Eroilor');

INSERT INTO CASA
VALUES(14, 3, 5, 420);
INSERT INTO CASA(id_strada, numar, dimensiune)
VALUES(14, 2, 210);
INSERT INTO CASA
VALUES(10, 1, 1, 100);
INSERT INTO CASA
VALUES(10, 2, 3, 250);
INSERT INTO CASA
VALUES(12, 20, 2, 160);


