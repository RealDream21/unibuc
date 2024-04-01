package cabinet;

import cabinet.domain.Client;
import cabinet.domain.Medic;
import cabinet.domain.Specializare;

public class Main {
    public static void main(String[] args) {
        Client t = new Client("Ionel", "31381983");
        Specializare[] specializari = new Specializare[5];
        specializari[0] = Specializare.GINECOLOG;
        specializari[1] = Specializare.NEUROCHIRURG;

        Medic y = new Medic("Baubau",specializari);
        y.addSpecializare(Specializare.CARDIOLOG);
        System.out.println(y.toString());
    }
}
