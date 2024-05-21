package cabinet.repository;

import cabinet.config.DatabaseConfiguration;
import cabinet.domain.MedicGeneralist;
import cabinet.domain.MedicSpecialist;
import cabinet.domain.Specializare;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class MedicRepository {

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
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public void insert(MedicGeneralist medicGeneralist){}

    public void insert(MedicSpecialist medicSpecialist){}







}
