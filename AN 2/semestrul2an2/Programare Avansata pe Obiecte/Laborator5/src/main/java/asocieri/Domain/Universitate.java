package asocieri.Domain;

import java.util.Arrays;

public class Universitate {
    private String nume;
    private Departament[] departaments;//compozitie

    public Universitate(String nume, Departament[] departaments) {
        this.nume = nume;
//        this.departamente = departamente;
        this.departaments = Arrays.copyOf(departaments, departaments.length);
    }

    @Override
    public String toString()
    {
        return "Universitatea: nume = " + nume + " , departamente = " + Arrays.toString(departaments);
    }
}
