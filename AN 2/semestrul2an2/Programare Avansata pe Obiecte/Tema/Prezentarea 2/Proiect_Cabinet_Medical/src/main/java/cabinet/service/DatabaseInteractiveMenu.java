package cabinet.service;

import java.awt.event.WindowStateListener;
import java.util.InputMismatchException;
import java.util.Scanner;

public class DatabaseInteractiveMenu {
    private static DatabaseInteractiveMenu instance;

    private DatabaseInteractiveMenu(){}

    public static DatabaseInteractiveMenu getInstance(){
        if(instance == null){
            instance = new DatabaseInteractiveMenu();
        }
        return instance;
    }

    public final void enterMenu(){
        Scanner input = new Scanner(System.in);
        final int MAX_OPTIUNE = 4;
        while(true) {
            System.out.println("Alege ce vrei sa faci:");
            System.out.println("0. Iesi");
            System.out.println("1. Intra in meniu clienti");
            System.out.println("2. Intra in meniu medici");
            System.out.println("3. Intra in meniu programari");
            System.out.println("4. Creaza baza de date");

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
            }
            if (alegere == 0)
                break;

            try {
                switch (alegere) {
                    case 1:
                        enterMeniuClienti();
                        break;
                    case 2:
                        enterMeniuMedici();
                        break;
                    case 3:
                        enterMeniuProgramari();
                        break;
                    case 4:
                        creazaBazaDeDate();
                        break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }

    private void enterMeniuClienti()
    {
        MeniuClienti.getInstance().enterMenu();
    }

    private void enterMeniuMedici()
    {
        MeniuMedici.getInstance().enterMenu();
    }

    private void enterMeniuProgramari()
    {
        MeniuProgramari.getInstance().enterMenu();
    }

    private void creazaBazaDeDate(){DatabaseManagerSingleton.getInstance().initializeDatabase();}

}
