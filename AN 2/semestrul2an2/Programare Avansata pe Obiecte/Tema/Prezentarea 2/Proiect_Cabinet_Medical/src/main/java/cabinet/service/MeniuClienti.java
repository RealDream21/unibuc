package cabinet.service;

import cabinet.domain.Client;
import cabinet.domain.ProgramareConsult;
import cabinet.domain.ProgramareUrgenta;

import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class MeniuClienti {
    private static MeniuClienti instance;
    private static DatabaseManagerSingleton databaseManagerSingleton;

    private MeniuClienti(){}

    public static MeniuClienti getInstance(){
        if(instance == null){
            instance = new MeniuClienti();
            databaseManagerSingleton = DatabaseManagerSingleton.getInstance();
        }
        return instance;
    }

    public void enterMenu()
    {
        Scanner input = new Scanner(System.in);
        final int MAX_OPTIUNE = 6;
        while(true) {
            System.out.println("Alege ce vrei sa faci:");
            System.out.println("0. Iesi");
            System.out.println("1. Afiseaza toti clientii");
            System.out.println("2. Insereaza un client");
            System.out.println("3. Afiseaza programarile de consult ale unui client");
            System.out.println("4. Afiseaza programarile de urgenta ale unui client");
            System.out.println("5. Sterge clientul");
            System.out.println("6. Update asigurarea medicala prin negare");

            int alegere = 0;
            try {
                alegere = input.nextInt();
                if (alegere < 0)
                    throw new RuntimeException("Indicele ales este prea mic");
                if (alegere > MAX_OPTIUNE)
                    throw new RuntimeException("Indicele ales este prea mare");
            } catch (InputMismatchException e) {
                System.out.println("Tipul de date citit nu este cel bun");
            } catch (RuntimeException e) {
                System.out.println("A aparut o eroare la indicele ales: " + e.toString());
                continue;
            }
            if (alegere == 0)
                break;

            try {
                switch (alegere) {
                    case 1:
                        afiseazaTotiClientii();
                        break;
                    case 2:
                        insereazaUnClient();
                        break;
                    case 3:
                        afiseazaProgramarileDeConsult();
                        break;
                    case 4:
                        afiseazaProgramariDeUrgenta();
                        break;
                    case 5:
                        stergeClient();
                        break;
                    case 6:
                        negareAsigurareMedicala();
                        break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void afiseazaTotiClientii()
    {
        ArrayList<Client> clienti = databaseManagerSingleton.getAllClients();
        for(var client: clienti)
        {
            System.out.println(client);
        }
    }

    private final void insereazaUnClient() throws InvalidParameterException {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele clientului");
        nume = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon = readNumarTelefon(input);

        try{
            databaseManagerSingleton.insertClient(new Client(nume, email, numarTelefon));
        }catch(InvalidParameterException e){
            System.out.println(e.toString());
            throw new InvalidParameterException("Eroare la crearea clientului");
        }
    }

    private void afiseazaProgramarileDeConsult()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele clientului");
        nume = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon = readNumarTelefon(input);
        try{
            ArrayList<ProgramareConsult> programari = databaseManagerSingleton.getProgramariConsult(new Client(nume, email, numarTelefon));
            for(var programare:programari)
            {
                System.out.println(programare);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    private void afiseazaProgramariDeUrgenta()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele clientului");
        nume = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon = readNumarTelefon(input);
        try{
            ArrayList<ProgramareUrgenta> programari = databaseManagerSingleton.getProgramariUrgenta(new Client(nume, email, numarTelefon));
            for(var programare:programari)
            {
                System.out.println(programare);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    private void stergeClient()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele clientului");
        nume = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon = readNumarTelefon(input);

        try{
            databaseManagerSingleton.deleteClient(new Client(nume, email, numarTelefon));
        }catch(InvalidParameterException e){
            System.out.println(e.toString());
            throw new InvalidParameterException("Eroare la crearea clientului");
        }
    }

    public void negareAsigurareMedicala()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele clientului");
        nume = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon = readNumarTelefon(input);
        try{
            databaseManagerSingleton.negateAsigurareMedicala(new Client(nume, email, numarTelefon));
        }catch (Exception e)
        {
            e.printStackTrace();
        }
    }




    private static String readNume(Scanner input){
        String nume;
        nume = input.nextLine();
        nume = nume.strip();
        return nume;
    }

    private static String readEmail(Scanner input){
        String email;
        email = input.nextLine();
        email = email.strip();
        return email;
    }

    private static String readNumarTelefon(Scanner input){
        String numarTelefon;
        numarTelefon = input.nextLine();
        numarTelefon = numarTelefon.strip();
        return numarTelefon;
    }

}
