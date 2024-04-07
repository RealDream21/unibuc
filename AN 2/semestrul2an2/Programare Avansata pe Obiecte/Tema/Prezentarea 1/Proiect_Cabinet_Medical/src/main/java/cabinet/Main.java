package cabinet;

import cabinet.domain.*;

import java.io.IOException;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.spi.CalendarDataProvider;

public class Main {
    public static void main(String[] args) throws IOException {
        SingletonServiciuProgramare singletonServiciuProgramare = SingletonServiciuProgramare.getInstanceOfServiciuProgramare();
//        singletonServiciuProgramare.addClient();
//        System.out.println(singletonServiciuProgramare.getClienti());
//        singletonServiciuProgramare.addClient();
        singletonServiciuProgramare.addClient();
        singletonServiciuProgramare.addMedic();
        singletonServiciuProgramare.addProgramare();
        singletonServiciuProgramare.addProgramare();
        List<Programare> programari = singletonServiciuProgramare.getProgramariSortate();
        //eroare, imi spune ca List<Programare> este imutabila :(((
        for(var programare: programari)
        {
            System.out.println(programare);
        }
    }
}
