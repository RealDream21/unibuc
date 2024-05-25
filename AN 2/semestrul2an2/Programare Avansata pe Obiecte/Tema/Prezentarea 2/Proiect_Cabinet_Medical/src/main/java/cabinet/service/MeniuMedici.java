package cabinet.service;

import cabinet.domain.Medic;
import cabinet.domain.MedicGeneralist;
import cabinet.domain.MedicSpecialist;
import cabinet.domain.Specializare;

import java.util.*;

public class MeniuMedici {
    public static MeniuMedici instance;
    private static DatabaseManagerSingleton databaseManagerSingleton;

    private MeniuMedici(){}

    public static MeniuMedici getInstance()
    {
        if(instance == null){
            instance = new MeniuMedici();
            databaseManagerSingleton = DatabaseManagerSingleton.getInstance();
        }
        return instance;
    }


    public void enterMenu()
    {
        Scanner input = new Scanner(System.in);
        final int MAX_OPTIUNE = 3;
        while(true) {
            System.out.println("Alege ce vrei sa faci:");
            System.out.println("0. Iesi");
            System.out.println("1. Afiseaza toti medicii");
            System.out.println("2. Insereaza un medic");
            System.out.println("3. Sterge medicul");

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
                        afiseazaTotiMedicii();
                        break;
                    case 2:
                        insereazaUnMedic();
                        break;
                    case 3:
                        stergeUnMedic();
                        break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void afiseazaTotiMedicii()
    {
        ArrayList<Medic> medici = DatabaseManagerSingleton.getInstance().getAllMedics();
        for(var medic:medici)
        {
            System.out.println(medic);
        }
    }

    public void insereazaUnMedic()
    {
        Medic medic = createMedic();
        if(medic instanceof MedicSpecialist){
            DatabaseManagerSingleton.getInstance().insertMedicSpecialist((MedicSpecialist) medic);
        } else if (medic instanceof MedicGeneralist) {
            DatabaseManagerSingleton.getInstance().insertMedicGeneralist((MedicGeneralist) medic);
        }
    }

    public void stergeUnMedic()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele medicului");
        nume = readNume(input);
        System.out.println("Dati email-ul medicului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al medicului:");
        numarTelefon = readNumarTelefon(input);

        try{
            DatabaseManagerSingleton.getInstance().deleteMedic(new MedicGeneralist(nume, email, numarTelefon));
        }catch(Exception e)
        {
            e.printStackTrace();
        }
    }


    public Medic createMedic()
    {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele medicului");
        nume = readNume(input);
        System.out.println("Dati email-ul medicului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al medicului:");
        numarTelefon = readNumarTelefon(input);

        System.out.println("NUMARUL DE TELEFON ESTE: " + numarTelefon);

        System.out.println("Medicul este specialist sau generalist?\n1.Specialist\n2.Generalist");
        int tip = input.nextInt();
        if(tip == 1)
        {
            System.out.println("In ce se specializeaza?\n");
            Specializare[] specializari = Arrays.copyOf(Specializare.values(), Specializare.values().length);
            for(int i = 0; i < specializari.length; i++)
            {
                System.out.println(i + ". " + specializari[i]);
            }
            int indexSpec = input.nextInt();
            if(indexSpec >= 0 && indexSpec < specializari.length){
                Specializare spec = specializari[indexSpec];
                return new MedicSpecialist(nume, email, numarTelefon, spec);
            }
            else {
                throw new IndexOutOfBoundsException("Indexul accesat nu este in range");
            }
        } else if (tip == 2){
            return new MedicGeneralist(nume, email, numarTelefon);
        } else{
            throw new InputMismatchException("Nu exista acest tip de medic");
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
