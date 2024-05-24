package cabinet.config;

import javax.xml.crypto.Data;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

public class SetupDataUsingStatement {
    public void createClientTable() {
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
            statement.execute(comanda );
        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void createMedicTable() {
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
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void createProgramareConsultTable(){
        String comandaTabel = """
                CREATE TABLE programare_consult(
                    id int PRIMARY KEY AUTO_INCREMENT,
                    data DATE,
                    cost DOUBLE(10, 3),
                    MedicId int,
                    ClientId int,
                    FOREIGN KEY (MedicId) REFERENCES medic(id),
                    FOREIGN KEY (ClientId) REFERENCES client(id)
                );
                """;
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            Statement statement = conexiune.createStatement();
            statement.execute(comandaTabel);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

}
