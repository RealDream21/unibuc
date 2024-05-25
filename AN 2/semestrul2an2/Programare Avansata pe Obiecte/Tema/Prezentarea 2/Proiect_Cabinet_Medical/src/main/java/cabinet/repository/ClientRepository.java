package cabinet.repository;

import cabinet.config.DatabaseConfiguration;
import cabinet.domain.Client;
import cabinet.domain.Medic;
import cabinet.domain.Persoana;
import cabinet.service.AuditService;

import javax.swing.text.Style;
import javax.xml.crypto.Data;
import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;
import java.util.OptionalInt;

public class ClientRepository {

    private final static AuditService auditService = AuditService.getInstance();
    public void insert(String nume, String email, String numarTelefon, boolean asigurareMedicala)
    {
        String comandaInsert = "INSERT INTO client(nume, email, numarTelefon, asigurareMedicala) VALUES (?, ?, ?, ?)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setString(1, nume);
            preparedStatement.setString(2, email);
            preparedStatement.setString(3, numarTelefon);
            preparedStatement.setBoolean(4, asigurareMedicala);
            preparedStatement.execute();
            String line = "Am inserat clientul " + nume + " " + email + " " + numarTelefon;
            auditService.writeLine("log.csv", line);
        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void insert(Client client)
    {
        String comandaInsert = "INSERT INTO client(nume, email, numarTelefon, asigurareMedicala) VALUES (?, ?, ?, ?)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setString(1, client.getNume());
            preparedStatement.setString(2, client.getEmail());
            preparedStatement.setString(3, client.getNumarTelefon());
            preparedStatement.setBoolean(4, client.getAsigurareMedicala());
            preparedStatement.execute();
            String line = "Am inserat clientul " + client.getNume() + " " + client.getEmail() + " " + client.getNumarTelefon();
            auditService.writeLine("log.csv", line);
        }catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public Optional<Integer> getId(String nume, String email, String numarTelefon){
        String comandaCautare = "SELECT id FROM client WHERE nume = ? AND email = ? AND numarTelefon = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaCautare);
            preparedStatement.setString(1, nume);
            preparedStatement.setString(2, email);
            preparedStatement.setString(3, numarTelefon);
            ResultSet rezultat = preparedStatement.executeQuery();
            if(rezultat.next()){
                Integer id = rezultat.getInt("id");
                return Optional.of(id);
            }
            return Optional.empty();
        }catch(SQLException e){
            e.printStackTrace();
        }
        return Optional.empty();
    }

    public Optional<Client> getByid(int id){
        String comandaCautare = "SELECT * FROM client WHERE id = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try {
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaCautare);
            preparedStatement.setInt(1, id);
            ResultSet rezultat = preparedStatement.executeQuery();
            return mapToClient(rezultat);
        }catch(SQLException e){
            e.printStackTrace();
        }
        return Optional.empty();
    }

    public Optional<ArrayList<Client>> getAll(){
        ArrayList<Client> returnList = new ArrayList<Client>();
        String comandaSelect = "SELECT * FROM client";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            Statement statement = conexiune.createStatement();
            ResultSet resultSet = statement.executeQuery(comandaSelect);
            while(true){
                Optional<Client> mapare = mapToClient(resultSet);
                if(mapare.isEmpty())
                    break;
                returnList.add(mapare.get());
            }
            return Optional.of(returnList);
        }catch(SQLException e){
            e.printStackTrace();
        }
        return Optional.empty();
    }

    private Optional<Client> mapToClient(ResultSet rezultat)throws SQLException{
        if(rezultat.next()){
            String nume = rezultat.getString("nume");
            String email = rezultat.getString("email");
            String numarTelefon = rezultat.getString("numarTelefon");
            boolean asigurareMedicala = rezultat.getBoolean("asigurareMedicala");
            return Optional.of(new Client(nume, email, numarTelefon, asigurareMedicala));
        }
        return Optional.empty();
    }

    public void updateAsigurare(String nume, String email, boolean statutNouAsigurare)
    {
        String comandaUpdate = "UPDATE client SET asigurareMedicala = ? WHERE nume = ? AND email = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaUpdate);
            preparedStatement.setBoolean(1, statutNouAsigurare);
            preparedStatement.setString(2, nume);
            preparedStatement.setString(3, email);
            preparedStatement.executeUpdate();
        }catch(SQLException e){
            e.printStackTrace();
        }
        String line = "Am updatat clientul " + nume + " " + email;
        auditService.writeLine("log.csv", line);
    }

    public void delete(String nume, String email, String numarTelefon)
    {
        String comandaDelete = "DELETE FROM client WHERE nume = ? AND email = ? AND numarTelefon = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaDelete);
            preparedStatement.setString(1, nume);
            preparedStatement.setString(2, email);
            preparedStatement.setString(3, numarTelefon);
            preparedStatement.executeUpdate();
            String line = "Am sters clientul " + nume + " " + email + " " + numarTelefon;
            auditService.writeLine("log.csv", line);
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
}
