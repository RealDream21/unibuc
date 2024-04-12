package cabinet.domain;

import java.io.IOException;
import java.security.InvalidParameterException;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;
import java.util.logging.ConsoleHandler;

public class SingletonMeniuUtilizare {

    private static SingletonMeniuUtilizare instance;

    private static SingletonServiciuProgramare singletonServiciuProgramare;
    private SingletonMeniuUtilizare(){}

    public static SingletonMeniuUtilizare getInstance()
    {
        if(singletonServiciuProgramare == null)
            singletonServiciuProgramare = SingletonServiciuProgramare.getInstanceOfServiciuProgramare();
        if(instance == null)
            instance = new SingletonMeniuUtilizare();
        return instance;
    }

    public final void enterMeniu()
    {
        Scanner input = new Scanner(System.in);
        final int MAX_OPTIUNE = 10;
        while(true)
        {
            System.out.println("Alege ce vrei sa faci:");
            System.out.println("0. Iesi");
            System.out.println("1. Adauga client");
            System.out.println("2. Adauga medic");
            System.out.println("3. Adauga programare");
            System.out.println("4. Afiseaza incasarile cabinetului");
            System.out.println("5. Afiseaza programarile cu un anumit medic");
            System.out.println("6. Afiseaza programarile unui anumit client");
            System.out.println("7. Afiseaza programarile unui anumit client cu un anumit medic");
            System.out.println("8. Afiseaza programarile sortate");
            System.out.println("9. Afiseaza clienti");
            System.out.println("10. Afiseaza medici");

            int alegere = 0;
            try{
                alegere = input.nextInt();
                if(alegere < 0)
                    throw new RuntimeException("Indicele ales este prea mic");
                if(alegere > MAX_OPTIUNE)
                    throw new RuntimeException("Indicele ales este prea mare");
            }
            catch (InputMismatchException e){
                System.out.println("Tipul de date citit nu este cel bun");
            }
            catch (RuntimeException e)
            {
                System.out.println("A aparut o eroare la indicele ales: " +e.toString());
            }

            if(alegere == 0)
                break;

            try{
                switch(alegere){
                    case 1:
                        optiune1();
                        break;
                    case 2:
                        optiune2();
                        break;
                    case 3:
                        optiune3();
                        break;
                    case 4:
                        optiune4();
                        break;
                    case 5:
                        optiune5();
                        break;
                    case 6:
                        optiune6();
                        break;
                    case 7:
                        optiune7();
                        break;
                    case 8:
                        optiune8();
                        break;
                    case 9:
                        optiune9();
                        break;
                    case 10:
                        optiune10();
                        break;
                }
            }catch (Exception e){
                System.out.println(e.toString());
            }
        }
    }

    private void optiune1(){
        try{
            singletonServiciuProgramare.addClient();
        }catch (InvalidParameterException e) {
            System.out.println(e.toString());
        }
    }

    private void optiune2(){
        try{
            singletonServiciuProgramare.addMedic();
        }catch(InputMismatchException e){
            System.out.println("A aparut o eroare la input: " +  e.toString());
        }catch(IndexOutOfBoundsException e){
            System.out.println("A aparut o eroare la un index: " + e.toString());
        }
    }

    private void optiune3(){
        singletonServiciuProgramare.addProgramare();
    }

    private void optiune4(){
        System.out.println("Cabinetul a incasat: " + singletonServiciuProgramare.totalIncasari());
    }

    private void optiune5(){
        List<Programare> programari = singletonServiciuProgramare.getProgramariCuUnAnumitMedic();
        for(Programare programare: programari){
            System.out.println(programare);
        }
    }

    private void optiune6(){
        List<Programare> programari = singletonServiciuProgramare.getProgramariPersoana();
        for(Programare programare: programari){
            System.out.println(programare);
        }
    }

    private void optiune7(){
        List<Programare> programari = singletonServiciuProgramare.reminderProgramari();
        for(Programare programare: programari){
            System.out.println(programare);
        }
    }

    private void optiune8(){
        List<Programare> programari = singletonServiciuProgramare.getProgramariSortate();
        for(Programare programare: programari){
            System.out.println(programare);
        }

    }

    private void optiune9(){
        List<Client> clienti = singletonServiciuProgramare.getClienti();
        for(Client client: clienti){
            System.out.println(client);
        }
    }

    private void optiune10(){
        List<Medic> medici = singletonServiciuProgramare.getMedici();
        for(Medic medic: medici){
            System.out.println(medic);
        }
    }
}
