package cabinet;

import cabinet.domain.*;

import java.util.Calendar;
import java.util.Date;
import java.util.spi.CalendarDataProvider;

public class Main {
    public static void main(String[] args) {
        Client client1 = new Client("Ionel", "0725670003", "Popesti", true);
        Medic medic1 = new Medic("Marian", new Specializare[]{Specializare.CARDIOLOG, Specializare.NEUROCHIRURG});
        Calendar calendar = Calendar.getInstance();
        calendar.set(2024, 4, 2);
        Date data = calendar.getTime();
        Programare programare = new ProgramareConsult(data, medic1, client1, 2050);
        System.out.println(programare.toString());
    }
}
