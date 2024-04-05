package cabinet.domain;

import java.util.Calendar;
import java.util.Date;

public abstract class Programare {
    protected Date data;
    protected Medic medic;
    protected Client client;

    //private double cost; costul este calculat si nu setat

    protected Programare(Date data, Medic medic, Client client, double cost) {
        this.data = data;
        this.medic = medic;
        this.client = client;
    }

    @Override
    public abstract String toString();

    protected abstract double getCostSpecial();
    public final double calculeazaCost() {
        return medic.getCotizatie() * getCostSpecial();
    }
}
