package cabinet.service;

import cabinet.domain.Client;
import cabinet.domain.MedicGeneralist;

import java.util.InputMismatchException;
import java.util.Scanner;

public class MeniuProgramari {
    private static MeniuProgramari instance;
    private static DatabaseManagerSingleton databaseManagerSingleton;

    private MeniuProgramari(){}

    public static MeniuProgramari getInstance(){
        if(instance == null){
            instance = new MeniuProgramari();
            databaseManagerSingleton = DatabaseManagerSingleton.getInstance();
        }
        return instance;
    }

    public void enterMenu()
    {
        Scanner input = new Scanner(System.in);
        final int MAX_OPTIUNE = 2;
        while(true) {
            System.out.println("Alege ce vrei sa faci:");
            System.out.println("0. Iesi");
            System.out.println("1. Programeaza un consult");
            System.out.println("2. Programreaza o urgenta");

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
                        programeazaConsult();
                        break;
                    case 2:
                        programeazaUrgenta();
                        break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void programeazaConsult()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele medicului");
        nume = readNume(input);
        System.out.println("Dati email-ul medicului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al medicului:");
        numarTelefon = readNumarTelefon(input);

        String nume1, email1, numarTelefon1;
        System.out.println("Dati numele clientului");
        nume1 = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email1 = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon1 = readNumarTelefon(input);

        DatabaseManagerSingleton.getInstance().insertProgramareConsult(new Client(nume1, email1, numarTelefon1), new MedicGeneralist(nume, email, numarTelefon));
    }

    private void programeazaUrgenta()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele medicului");
        nume = readNume(input);
        System.out.println("Dati email-ul medicului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al medicului:");
        numarTelefon = readNumarTelefon(input);

        String nume1, email1, numarTelefon1;
        System.out.println("Dati numele clientului");
        nume1 = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email1 = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon1 = readNumarTelefon(input);

        System.out.println("Dati gradul de urgenta:");
        int gradUrgenta = input.nextInt();

        DatabaseManagerSingleton.getInstance().insertProgramareUrgenta(new Client(nume1, email1, numarTelefon1), new MedicGeneralist(nume, email, numarTelefon), gradUrgenta);

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
