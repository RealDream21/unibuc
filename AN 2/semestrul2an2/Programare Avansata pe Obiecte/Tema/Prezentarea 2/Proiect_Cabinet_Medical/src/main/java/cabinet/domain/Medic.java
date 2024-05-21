package cabinet.domain;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public abstract class Medic extends Persoana{

    Medic(String nume, String email, String numarTelefon)
    {
        super(nume, email, numarTelefon);
    }

    //Nu mai scriu override la toString deoarece o vreau abstracta mai departe, deci nu scriu nimic
    public abstract double getCotizatie();
}
