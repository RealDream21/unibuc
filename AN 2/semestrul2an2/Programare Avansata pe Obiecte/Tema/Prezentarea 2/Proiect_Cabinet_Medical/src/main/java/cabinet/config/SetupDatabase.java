package cabinet.config;

import cabinet.service.AuditService;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.Instant;
import java.util.Date;

public class SetupDatabase {

    private final AuditService auditService = AuditService.getInstance();
    public void createClientTable() throws SQLException {
        String comanda =
                """
                CREATE TABLE IF NOT EXISTS client(
                    id int PRIMARY KEY AUTO_INCREMENT,
                    nume VARCHAR(25),
                    email VARCHAR(255),
                    numarTelefon VARCHAR(255),
                    asigurareMedicala BOOL,
                    unique (nume, email, numarTelefon)
                );   
                """;
        Connection connection = DatabaseConfiguration.getDatabaseConnection();
        try{
            Statement statement = connection.createStatement();
            statement.execute(comanda);

            String linie = "Creare tabel client";
            auditService.writeLine("log.csv", linie);
        }catch(SQLException e){
            e.printStackTrace();
            throw e;
        }
    }

    public void createMedicTable() throws SQLException {
        String comandaTabel = """
                CREATE TABLE IF NOT EXISTS medic(
                    id int PRIMARY KEY AUTO_INCREMENT,
                    nume VARCHAR(25),
                    email VARCHAR(255),
                    numarTelefon VARCHAR(255),
                    specializare VARCHAR(25),
                    unique (nume, email, numarTelefon)
                );
                """;
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try {
            Statement statement = conexiune.createStatement();
            statement.execute(comandaTabel);
            String linie = "Creare tabel medic";
            auditService.writeLine("log.csv", linie);
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        }
    }

    public void createProgramareConsultTable() throws SQLException {
        String comandaTabel = """
                CREATE TABLE programare_consult(
                    id int PRIMARY KEY AUTO_INCREMENT,
                    data DATE,
                    cost DOUBLE(10, 3),
                    MedicId int,
                    ClientId int,
                    FOREIGN KEY (MedicId) REFERENCES medic(id),
                    FOREIGN KEY (ClientId) REFERENCES client(id),
                    UNIQUE (data, MedicId, ClientId)
                );
                """;
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            Statement statement = conexiune.createStatement();
            statement.execute(comandaTabel);
            String linie = "Creare tabel programari consultatii";
            auditService.writeLine("log.csv", linie);
        }catch (SQLException e){
            e.printStackTrace();
            throw e;
        }
    }

    public void createProgramareUrgentaTable() throws SQLException {
        String comandaTabel = """
                CREATE TABLE programare_urgenta(
                    id int PRIMARY KEY AUTO_INCREMENT,
                    data DATE,
                    gradUrgenta int,
                    cost DOUBLE(10, 3),
                    MedicId int,
                    ClientId int,
                    FOREIGN KEY (MedicId) REFERENCES medic(id),
                    FOREIGN KEY (ClientId) REFERENCES client(id),
                    CHECK (gradUrgenta >= 0 AND gradUrgenta <= 10),
                    UNIQUE(data, gradUrgenta, MedicId,ClientId)
                );
                """;
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            Statement statement = conexiune.createStatement();
            statement.execute(comandaTabel);
            String linie = "Creare tabel programari de urgenta";
            auditService.writeLine("log.csv", linie);
        }catch (SQLException e) {
            e.printStackTrace();
            throw e;
        }
    }

}
