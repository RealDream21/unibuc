package cabinet.repository;

import cabinet.config.DatabaseConfiguration;
import cabinet.domain.*;
import cabinet.service.AuditService;

import javax.swing.plaf.nimbus.State;
import javax.xml.crypto.Data;
import java.lang.management.OperatingSystemMXBean;
import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class MedicRepository {

    private static final AuditService auditService = AuditService.getInstance();
    private static String specializareToString(Specializare specializare)
    {
        return specializare.toString();
    }

    public void insert(String nume, String email, String numarTelefon, Specializare specializare)
    {
        String comandaInsert = "INSERT INTO medic (nume, email, numarTelefon, specializare) VALUES(?, ?, ?, ?)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setString(1, nume);
            preparedStatement.setString(2, email);
            preparedStatement.setString(3, numarTelefon);
            preparedStatement.setString(4, specializareToString(specializare));
            preparedStatement.execute();
            String line = "Am inserat medicul specialist " + nume + " " + email + " " + numarTelefon + " " + specializare.toString();
            auditService.writeLine("log.csv", line);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public void insert(String nume, String email, String numarTelefon)
    {
        String comandaInsert = "INSERT INTO medic (nume, email, numarTelefon, specializare) VALUES(?, ?, ?, NULL)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setString(1, nume);
            preparedStatement.setString(2, email);
            preparedStatement.setString(3, numarTelefon);
            preparedStatement.execute();
            String line = "Am inserat medicul generalist " + nume + " " + email + " " + numarTelefon;
            auditService.writeLine("log.csv", line);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public void insert(MedicGeneralist medicGeneralist){
        String comandaInsert = "INSERT INTO medic (nume, email, numarTelefon, specializare) VALUES(?, ?, ?, NULL)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setString(1, medicGeneralist.getNume());
            preparedStatement.setString(2, medicGeneralist.getEmail());
            preparedStatement.setString(3, medicGeneralist.getNumarTelefon());
            preparedStatement.execute();
            String line = "Am inserat medicul generalist " + medicGeneralist.getNume() + " " + medicGeneralist.getEmail() + " " + medicGeneralist.getNumarTelefon();
            auditService.writeLine("log.csv", line);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public void insert(MedicSpecialist medicSpecialist){
        String comandaInsert = "INSERT INTO medic (nume, email, numarTelefon, specializare) VALUES(?, ?, ?, ?)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setString(1, medicSpecialist.getNume());
            preparedStatement.setString(2, medicSpecialist.getEmail());
            preparedStatement.setString(3, medicSpecialist.getNumarTelefon());
            preparedStatement.setString(4, medicSpecialist.getSpecializare().toString());
            preparedStatement.execute();
            String line = "Am inserat medicul specialist " + medicSpecialist.getNume() + " " + medicSpecialist.getEmail() + " " + medicSpecialist.getNumarTelefon() + " " + medicSpecialist.getSpecializare().toString();
            auditService.writeLine("log.csv", line);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public Optional<Integer> getId(String nume, String email, String numarTelefon){
        String comandaCautare = "SELECT id FROM medic WHERE nume = ? AND email = ? AND numarTelefon = ?";
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

    public Optional<ArrayList<Medic>> getAll(){
        ArrayList<Medic> returnList = new ArrayList<Medic>();
        String comandaSelect = "SELECT * FROM medic";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            Statement statement = conexiune.createStatement();
            ResultSet resultSet = statement.executeQuery(comandaSelect);
            while(true){
                Optional<Medic> mapare = mapToMedic(resultSet);
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

    public Optional<Medic> getByid(int id){
        String comandaCautare = "SELECT * FROM medic WHERE id = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try {
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaCautare);
            preparedStatement.setInt(1, id);
            ResultSet rezultat = preparedStatement.executeQuery();
            return mapToMedic(rezultat);
        }catch(SQLException e){
            e.printStackTrace();
        }
        return Optional.empty();
    }

    private Optional<Medic> mapToMedic(ResultSet rezultat)throws SQLException{
        if(rezultat.next()) {
            String nume = rezultat.getString("nume");
            String email = rezultat.getString("email");
            String numarTelefon = rezultat.getString("numarTelefon");
            String valSpecialziare = rezultat.getString("specializare");
            if (valSpecialziare != null) {
                Specializare specializare = Specializare.valueOf(rezultat.getString("specializare"));
                return Optional.of(new MedicSpecialist(nume, email, numarTelefon, specializare));
            } else {
                return Optional.of(new MedicGeneralist(nume, email, numarTelefon));
            }
        }else{
            return Optional.empty();
        }
    }

    public void updateSpecializre(String nume, String email, String numarTelefon, Specializare specializare){
        String comandaUpdate = "UPDATE medic SET specializare = ? WHERE nume = ? AND numarTelefon = ? AND email = ? AND specializare IS NOT NULL";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaUpdate);
            preparedStatement.setString(1, specializare.toString());
            preparedStatement.setString(2, nume);
            preparedStatement.setString(3, numarTelefon);
            preparedStatement.setString(4, email);
            preparedStatement.executeUpdate();
            String line = "Am updatat specializarea medicului " + nume + " " + email + " " + numarTelefon + " in " + specializare.toString();
            auditService.writeLine("log.csv", line);
        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void delete(String nume, String email, String numarTelefon){
        String comandaDelete = "DELETE FROM medic WHERE nume = ? AND email = ? AND numarTelefon = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaDelete);
            preparedStatement.setString(1, nume);
            preparedStatement.setString(2, email);
            preparedStatement.setString(3, numarTelefon);
            preparedStatement.executeUpdate();
            String line = "Am sters medicul " + nume + " " + email + " " + numarTelefon;
            auditService.writeLine("log.csv", line);
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
}
