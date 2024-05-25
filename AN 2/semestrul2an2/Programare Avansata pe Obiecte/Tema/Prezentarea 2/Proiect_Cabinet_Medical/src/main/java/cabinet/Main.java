package cabinet;

import cabinet.config.DatabaseConfiguration;
import cabinet.config.SetupDatabase;
import cabinet.repository.ClientRepository;
import cabinet.repository.MedicRepository;
import cabinet.repository.ProgramareConsultRepository;
import cabinet.repository.ProgramareUrgentaRepository;
import cabinet.service.DatabaseInteractiveMenu;
import cabinet.service.MeniuClienti;
import cabinet.service.MeniuMedici;

import java.io.IOException;
import java.sql.Connection;


/*
for future debugging: la maven daca da eroare ca nu am driver => il adaug in pom.xml versiunea lui si dupa ma duc la maven in dreapta si reload

PAROLA LA ORICE LEGAT DE BAZA DE DATE ESTE: MyRandomPassword

servicii:
1. ServiciuProgramare.addClient()
2. ServiciuProgramare.addMedic()
3. ServiciuProgramare.getProgramariSortate()
4. Programare.calculeazaCost()
5. ServiciuProgramare.totalIncasari() + ServiciuProgramare.totalIncasariIntreDouaDate(Data, Data)
6. Client.addProgramare()
7. ServiciuProgramare.getProgramariCuUnAnumitMedic() + parametrizat
8. ServiciuProgramare.addProgramare()
9. ServiciuProgramare.getProgramariPersoana() + parametrizat
10. ServiciuProgramare.reminderProgramare(Persoana, Medic)
 */

public class Main {
    public static void main(String[] args) throws IOException {
//        SingletonMeniuUtilizare meniu = SingletonMeniuUtilizare.getInstance();
//        meniu.enterMeniu();
        Connection conexiune = DatabaseConfiguration.getDatabaseConnection();
        DatabaseInteractiveMenu databaseInteractiveMenu = DatabaseInteractiveMenu.getInstance();
        databaseInteractiveMenu.enterMenu();
    }
}
