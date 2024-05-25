package cabinet.service;

import cabinet.config.DatabaseConfiguration;
import cabinet.config.SetupDatabase;
import cabinet.domain.*;
import cabinet.repository.ClientRepository;
import cabinet.repository.MedicRepository;
import cabinet.repository.ProgramareConsultRepository;
import cabinet.repository.ProgramareUrgentaRepository;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Optional;

public class DatabaseManagerSingleton {
    private static DatabaseManagerSingleton instance;
    private static SetupDatabase setupDatabase;

    private DatabaseManagerSingleton(){}

    public static DatabaseManagerSingleton getInstance()
    {
        if (instance == null)
        {
            instance = new DatabaseManagerSingleton();
            setupDatabase = new SetupDatabase();
        }
        return instance;
    }

    public void initializeDatabase()
    {
        try {
            setupDatabase.createClientTable();
        }catch(SQLException e) {
            System.out.println("A aparut o eroare la crearea bazei de date pentru clienti: " + e.toString());
        }
        try{
            setupDatabase.createMedicTable();
        }catch(SQLException e) {
            System.out.println("A aparut o eroare la crearae bazei de date pentru medici " + e.toString());
        }
        try{
            setupDatabase.createProgramareConsultTable();
        }catch (SQLException e){
            System.out.println("A aparut o eroare la crearea bazei de date pentru programarile de tip consult " + e.toString());
        }
        try{
            setupDatabase.createProgramareUrgentaTable();
        }catch (SQLException e){
            System.out.println("A aparut o eroare la crearea bazei de date pentru programarile de tip urgenta " + e.toString());
        }
    }

    public ArrayList<Client> getAllClients()
    {
        ClientRepository clientRepository = new ClientRepository();
        clientRepository.getAll();
        Optional<ArrayList<Client>> clienti = clientRepository.getAll();
        if(clienti.isEmpty())
        {
            System.out.println("Nu au fost gasiti clienti");
        }
        return clienti.get();
    }

    public void insertClient(Client client)
    {
        ClientRepository clientRepository = new ClientRepository();
        clientRepository.insert(client);
    }

    public ArrayList<ProgramareConsult> getProgramariConsult(Client client)
    {
        ProgramareConsultRepository programareConsultRepository = new ProgramareConsultRepository();
        Optional<ArrayList<ProgramareConsult>> programari = programareConsultRepository.getProgramariPersoana(client);
        if(programari.isEmpty())
        {
            System.out.println("Nu au fost gasite programari de consult");
        }
        return programari.get();
    }

    public ArrayList<ProgramareUrgenta> getProgramariUrgenta(Client client)
    {
        ProgramareUrgentaRepository programareUrgentaRepository = new ProgramareUrgentaRepository();
        Optional<ArrayList<ProgramareUrgenta>> programari = programareUrgentaRepository.getProgramariPersoana(client);
        if(programari.isEmpty())
        {
            System.out.println("Nu au fost gasite programari de consult");
        }
        return programari.get();
    }

    public void deleteClient(Client client){
        ClientRepository clientRepository = new ClientRepository();
        clientRepository.delete(client.getNume(), client.getEmail(), client.getNumarTelefon());
    }

    public void negateAsigurareMedicala(Client client) {
        ClientRepository clientRepository = new ClientRepository();
        int ClientId = clientRepository.getId(client.getNume(), client.getEmail(), client.getNumarTelefon()).get();
        Client client1 = clientRepository.getByid(ClientId).get();
        clientRepository.updateAsigurare(client.getNume(), client.getEmail(), !client1.getAsigurareMedicala());
    }

    public ArrayList<Medic> getAllMedics()
    {
        MedicRepository medicRepository = new MedicRepository();
        medicRepository.getAll();
        Optional<ArrayList<Medic>> medici = medicRepository.getAll();
        if(medici.isEmpty())
        {
            System.out.println("Nu au fost gasiti medici");
        }
        return medici.get();
    }

    public void insertMedicSpecialist(MedicSpecialist medicSpecialist)
    {
        MedicRepository medicRepository = new MedicRepository();
        medicRepository.insert(medicSpecialist);
    }

    public void insertMedicGeneralist(MedicGeneralist medicGeneralist)
    {
        MedicRepository medicRepository = new MedicRepository();
        medicRepository.insert(medicGeneralist);
    }

    public void deleteMedic(MedicGeneralist medic)
    {
        MedicRepository medicRepository = new MedicRepository();
        medicRepository.delete(medic.getNume(), medic.getEmail(), medic.getNumarTelefon());
    }

    public void insertProgramareConsult(Client client, Medic medic)
    {
        ProgramareConsultRepository programareConsultRepository = new ProgramareConsultRepository();
        programareConsultRepository.insert(client, medic);
    }

    public void insertProgramareUrgenta(Client client, Medic medic, int gradUrgenta)
    {
        ProgramareUrgentaRepository programareUrgentaRepository = new ProgramareUrgentaRepository();
        programareUrgentaRepository.insert(client, medic, gradUrgenta);
    }

}
