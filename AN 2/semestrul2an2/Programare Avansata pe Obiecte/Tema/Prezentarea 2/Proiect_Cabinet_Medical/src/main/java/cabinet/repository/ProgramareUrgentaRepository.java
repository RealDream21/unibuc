package cabinet.repository;

import cabinet.config.DatabaseConfiguration;
import cabinet.domain.Client;
import cabinet.domain.Medic;
import cabinet.domain.ProgramareUrgenta;
import cabinet.service.AuditService;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class ProgramareUrgentaRepository {

    private static final AuditService auditService = AuditService.getInstance();
    public void insert(Client client, Medic medic, int gradUrgenta)
    {
        String comandaInsert = "INSERT INTO programare_urgenta(data, gradUrgenta, cost, MedicId, ClientId) VALUES(?, ?, ?, ?, ?)";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        try{
            long dataActuala = System.currentTimeMillis();
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaInsert);
            preparedStatement.setDate(1, new Date(dataActuala));

            ProgramareUrgenta programareUrgenta = new ProgramareUrgenta(new Date(dataActuala), medic, client, gradUrgenta);
            double cost = programareUrgenta.calculeazaCost();

            MedicRepository medicRepository = new MedicRepository();
            ClientRepository clientRepository = new ClientRepository();

            preparedStatement.setInt(2, gradUrgenta);
            preparedStatement.setDouble(3, cost);
            preparedStatement.setInt(4, medicRepository.getId(medic.getNume(), medic.getEmail(), medic.getNumarTelefon()).get());
            preparedStatement.setInt(5,clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon()).get());
            preparedStatement.executeUpdate();
            String line = "Am inserat programarea de urgenta dintre medicul " + medic.getNume() + " si clientul " + client.getNume();
            auditService.writeLine("log.csv", line);
        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public Optional<ArrayList<ProgramareUrgenta>> getProgramariPersoana(Client client)
    {
        String comandaSelect = "SELECT * FROM programare_urgenta WHERE ClientId = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try{
            ArrayList<ProgramareUrgenta> listaProgramari = new ArrayList<ProgramareUrgenta>();
            ClientRepository clientRepository = new ClientRepository();
            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaSelect);
            Optional<Integer> getId = clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon());
            if(getId.isEmpty())
                return Optional.empty();
            preparedStatement.setInt(1, getId.get());
            ResultSet rezultat = preparedStatement.executeQuery();
            while(true){
                Optional<ProgramareUrgenta> mapare = mapToProgramareUrgenta(rezultat);
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

    public Optional<ProgramareUrgenta> mapToProgramareUrgenta(ResultSet resultSet)throws SQLException
    {
        if(resultSet.next())
        {
            ClientRepository clientRepository = new ClientRepository();
            MedicRepository medicRepository = new MedicRepository();
            Date data = resultSet.getDate("data");
            Double cost = resultSet.getDouble("cost");
            int gradUrgenta = resultSet.getInt("gradUrgenta");
            int MedicId = resultSet.getInt("MedicId");
            int ClientId = resultSet.getInt("ClientId");
            return Optional.of(new ProgramareUrgenta(data, medicRepository.getByid(MedicId).get(), clientRepository.getByid(ClientId).get(), gradUrgenta));
        }else{
            return Optional.empty();
        }
    }

    public void updateUrgenta(Client client, Medic medic, Date data, int gradNou)
    {
        String comandaUpdate = "UPDATE programare_urgenta SET gradUrgenta = ? WHERE data = ? AND ClientId = ? AND MedicId = ?";
        Connection connection = DatabaseConfiguration.getDatabaseConnection();

        try{
            ClientRepository clientRepository = new ClientRepository();
            MedicRepository medicRepository = new MedicRepository();
            PreparedStatement preparedStatement = connection.prepareStatement(comandaUpdate);
            preparedStatement.setInt(1, gradNou);
            preparedStatement.setDate(2, data);

            Optional<Integer> ClientId = clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon());
            Optional<Integer> MedicId = medicRepository.getId(medic.getNume(), medic.getEmail(), medic.getNumarTelefon());
//
//            if(ClientId.isEmpty() || MedicId.isEmpty()) il lasam sa dea eroare si dam catch in alta parte
//                return;

            preparedStatement.setInt(3, ClientId.get());
            preparedStatement.setInt(4, MedicId.get());
            preparedStatement.executeUpdate();
            String line = "Am modificat gradul de urgenta al programarii dintre medicul " + medic.getNume() + " si clientul " + client.getNume() + " in gradul " + new Integer(gradNou).toString();
            auditService.writeLine("log.csv", line);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public void delete(Client client, Medic medic, Date data, int gradUrgenta)
    {
        String comandaDelete = "DELETE FROM programare_urgenta WHERE ClientId = ? AND MedicId = ? AND data = ? AND gradUrgenta = ?";
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();

        try{
            ClientRepository clientRepository = new ClientRepository();
            MedicRepository medicRepository = new MedicRepository();

            PreparedStatement preparedStatement = conexiune.prepareStatement(comandaDelete);
            Optional<Integer> ClientId = clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon());
            Optional<Integer> MedicId = medicRepository.getId(medic.getNume(), medic.getEmail(), medic.getNumarTelefon());

            preparedStatement.setInt(1, ClientId.get());
            preparedStatement.setInt(2, MedicId.get());
            preparedStatement.setDate(3, data);
            preparedStatement.setInt(4, gradUrgenta);
            preparedStatement.executeUpdate();
            String line = "Am sters programarea de urgenta dintre medicul  " + medic.getNume() + " si clientul " + client.getNume();
            auditService.writeLine("log.csv", line);
        }catch (SQLException e)
        {
            e.printStackTrace();
        }
    }
}
