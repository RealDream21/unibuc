package cabinet;

import cabinet.domain.*;

import java.io.IOException;
import java.util.Calendar;
import java.util.Date;
import java.util.spi.CalendarDataProvider;

public class Main {
    public static void main(String[] args) throws IOException {
        SingletonServiciuProgramare singletonServiciuProgramare = SingletonServiciuProgramare.getInstanceOfServiciuProgramare();
//        singletonServiciuProgramare.addClient();
//        System.out.println(singletonServiciuProgramare.getClienti());
//        singletonServiciuProgramare.addClient();
        singletonServiciuProgramare.addMedic();
        System.out.println(singletonServiciuProgramare.getMedici());
        System.out.println(singletonServiciuProgramare.getClienti());

    }
}
