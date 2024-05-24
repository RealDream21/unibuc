package cabinet;

import cabinet.config.DatabaseConfiguration;
import cabinet.config.SetupDataUsingStatement;
import cabinet.domain.*;
import cabinet.repository.ClientRepository;
import cabinet.repository.MedicRepository;
import cabinet.repository.ProgramareConsultRepository;

import java.io.IOException;
import java.sql.Connection;
import java.sql.Date;
import java.time.Instant;
import java.util.Calendar;
import java.util.List;
import java.util.spi.CalendarDataProvider;


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
        SetupDataUsingStatement setupDataUsingStatement = new SetupDataUsingStatement();
//        setupDataUsingStatement.createMedicTable();
//        setupDataUsingStatement.createClientTable();
//        setupDataUsingStatement.createProgramareConsultTable();

        MedicRepository medicRepository = new MedicRepository();
        ClientRepository clientRepository = new ClientRepository();
        ProgramareConsultRepository programareConsultRepository = new ProgramareConsultRepository();

        //medicRepository.insert("Ionel", "ionel@yahoo.com", "0725670003", Specializare.ORTODONT);
        //clientRepository.insert("Costel", "costel@yahoo.com", "0722369550", false);
        //medicRepository.insert("Paul", "paul@yahoo.com", "0724510600");

        programareConsultRepository.updateData(clientRepository.getByid(1).get(), medicRepository.getByid(1).get(),new Date(Instant.now().toEpochMilli()), new Date(Instant.ofEpochMilli(1000).toEpochMilli()));

        programareConsultRepository.delete(clientRepository.getByid(1).get(), medicRepository.getByid(1).get(), new Date(Instant.ofEpochMilli(1000).toEpochMilli()));

        System.out.println(programareConsultRepository.getProgramariPersoana(clientRepository.getByid(1).get()).get());

    }
}
