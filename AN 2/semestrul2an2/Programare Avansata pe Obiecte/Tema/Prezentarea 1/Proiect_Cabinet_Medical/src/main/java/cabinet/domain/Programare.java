package cabinet.domain;

import java.util.Calendar;
import java.util.Date;

public abstract class Programare {
    protected Date data;
    protected Medic medic;
    protected Client client;

    private double cost;

    protected Programare(Date data, Medic medic, Client client, double cost) {
        this.data = data;
        this.medic = medic;
        this.client = client;
        this.cost = cost;
    }

    @Override
    public abstract String toString();

    public double calculeazaCost() {
        if(medic instanceof MedicGeneralist)
        {

        }
        else if(medic instanceof MedicSpecialist) {

        }
        return cost;
    }

}
