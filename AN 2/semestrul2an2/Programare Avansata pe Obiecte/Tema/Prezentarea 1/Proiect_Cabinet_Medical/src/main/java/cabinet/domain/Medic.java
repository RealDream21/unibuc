package cabinet.domain;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Medic {
    String nume;
    List<Specializare> specializari = new ArrayList<Specializare>();
    String email;

    public Medic(){}
    public Medic(String nume){
        this.nume = nume;
    }
    public Medic(String nume, Specializare[] specializari){
        this(nume);
        for(Specializare spec: specializari)
        {
            if(spec != null)
            {
                this.specializari.add(spec);
            }
        }
    }

    public Medic(String nume, Specializare[] specializari, String email)
    {
        this(nume, specializari);
        this.email = email;
    }

    public boolean addSpecializare(Specializare specializare) {
        this.specializari.add(specializare);
        return true;
    }

    public int getNrSpecializari()
    {
        return specializari.size();
    }

    @Override
    public String toString()
    {
        return "Medic: " + nume + " " + "email: " + email + " cu specializarile " + specializari.toString();
    }
}
