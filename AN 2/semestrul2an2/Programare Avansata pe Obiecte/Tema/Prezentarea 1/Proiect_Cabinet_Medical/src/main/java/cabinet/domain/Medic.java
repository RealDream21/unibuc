package cabinet.domain;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public abstract class Medic {
    String nume;
    String email;

    public Medic(){}
    public Medic(String nume){
        this.nume = nume;
    }

    public Medic(String nume, String email)
    {
        this(nume);
        this.email = email;
    }


    @Override
    public abstract String toString();
    public abstract double getCotizatie();
}
