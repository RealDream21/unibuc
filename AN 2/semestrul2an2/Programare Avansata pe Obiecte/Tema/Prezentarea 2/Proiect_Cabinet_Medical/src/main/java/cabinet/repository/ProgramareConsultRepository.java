package cabinet.repository;

import cabinet.config.DatabaseConfiguration;
import cabinet.domain.Client;
import cabinet.domain.Medic;
import cabinet.domain.ProgramareConsult;
import cabinet.service.AuditService;

import java.sql.*;
import java.time.Instant;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Optional;
import java.util.spi.CalendarDataProvider;

public class ProgramareConsultRepository {


    private static AuditService auditService = AuditService.getInstance();
    public void insert(Client client, Medic medic)
    {
        String comandaInsert = "INSERT INTO programare_consult(data, cost, MedicId, ClientId) VALUES(?, ?, ?, ?)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            long dataActuala = System.currentTimeMillis();
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setDate(1, new Date(dataActuala));

            ProgramareConsult programareConsult = new ProgramareConsult(new Date(dataActuala), medic, client);
            double cost = programareConsult.calculeazaCost();

            MedicRepository medicRepository = new MedicRepository();
            ClientRepository clientRepository = new ClientRepository();
            preparedStatement.setDouble(2, cost);
            preparedStatement.setInt(3, medicRepository.getId(medic.getNume(), medic.getEmail(), medic.getNumarTelefon()).get());
            preparedStatement.setInt(4,clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon()).get());

            preparedStatement.executeUpdate();
            String line = "Am inserta programarea dintre medicul: " + medic.getNume() + " si clientul: " + client.getNume() + " la data de " + new Date(dataActuala);
            auditService.writeLine("log.csv", line);
        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public Optional<ArrayList<ProgramareConsult>> getProgramariPersoana(Client client)
    {
        String comandaSelect = "SELECT * FROM programare_consult WHERE ClientId = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try{
            ArrayList<ProgramareConsult> listaProgramari = new ArrayList<ProgramareConsult>();
            ClientRepository clientRepository = new ClientRepository();
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaSelect);
            Optional<Integer> getId = clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon());
            if(getId.isEmpty())
                return Optional.empty();
            preparedStatement.setInt(1, getId.get());
            ResultSet rezultat = preparedStatement.executeQuery();
            while(true){
                Optional<ProgramareConsult> mapare = mapToProgramareConsult(rezultat);
                if(mapare.isEmpty())
                    break;
                listaProgramari.add(mapare.get());
            }
            return Optional.of(listaProgramari);
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    public Optional<ProgramareConsult> mapToProgramareConsult(ResultSet resultSet)throws SQLException
    {
        if(resultSet.next())
        {
            ClientRepository clientRepository = new ClientRepository();
            MedicRepository medicRepository = new MedicRepository();
            Date data = resultSet.getDate("data");
            Double cost = resultSet.getDouble("cost");
            int MedicId = resultSet.getInt("MedicId");
            int ClientId = resultSet.getInt("ClientId");
            return Optional.of(new ProgramareConsult(data, medicRepository.getByid(MedicId).get(), clientRepository.getByid(ClientId).get()));
        }else{
            return Optional.empty();
        }
    }

    public void updateData(Client client, Medic medic, Date dataVeche, Date dataNoua)
    {
        String comandaUpdate = "UPDATE programare_consult SET data = ? WHERE data = ? AND ClientId = ? AND MedicId = ?";
        Connection connection = DatabaseConfiguration.getDatabaseConnection();

        try{
            ClientRepository clientRepository = new ClientRepository();
            MedicRepository medicRepository = new MedicRepository();
            PreparedStatement preparedStatement = connection.prepareStatement(comandaUpdate);
            preparedStatement.setDate(1, dataNoua);
            preparedStatement.setDate(2, dataVeche);

            Optional<Integer> ClientId = clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon());
            Optional<Integer> MedicId = medicRepository.getId(medic.getNume(), medic.getEmail(), medic.getNumarTelefon());

            if(ClientId.isEmpty() || MedicId.isEmpty())
                return;

            preparedStatement.setInt(3, ClientId.get());
            preparedStatement.setInt(4, MedicId.get());
            preparedStatement.executeUpdate();
            String line = "Am schimbat data programerii de pe data  " + dataVeche + " la data " + dataNoua + " dintre medicul: " + medic.getNume() + " si clientul " + client.getNume();
            auditService.writeLine("log.csv", line);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public void delete(Client client, Medic medic, Date data)
    {
        String comandaDelete = "DELETE FROM programare_consult WHERE ClientId = ? AND MedicId = ? AND data = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try{
            ClientRepository clientRepository = new ClientRepository();
            MedicRepository medicRepository = new MedicRepository();

            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaDelete);
            Optional<Integer> ClientId = clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon());
            Optional<Integer> MedicId = medicRepository.getId(medic.getNume(), medic.getEmail(), medic.getNumarTelefon());

            if(ClientId.isEmpty() || MedicId.isEmpty())
                return;

            preparedStatement.setInt(1, ClientId.get());
            preparedStatement.setInt(2, MedicId.get());
            preparedStatement.setDate(3, data);
            preparedStatement.executeUpdate();
            String line = "Am sters programarea dintre medicul " + medic.getNume() + " si clientul " + client.getNume() + " de la data de " + data.toString();
            auditService.writeLine("log.csv", line);
        }catch (SQLException e)
        {
            e.printStackTrace();
        }
    }
}
