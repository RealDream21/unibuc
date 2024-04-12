package cabinet;

import cabinet.domain.*;

import java.io.IOException;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.spi.CalendarDataProvider;


/*
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
        SingletonMeniuUtilizare meniu = SingletonMeniuUtilizare.getInstance();
        meniu.enterMeniu();
    }
}
