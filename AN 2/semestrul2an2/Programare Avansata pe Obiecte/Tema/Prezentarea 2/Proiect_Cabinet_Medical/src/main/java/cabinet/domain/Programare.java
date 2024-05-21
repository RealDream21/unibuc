package cabinet.domain;

import java.util.Calendar;
import java.util.Date;

public abstract class Programare implements Comparable<Programare>{
    protected Date data;
    protected Medic medic; //aici am agregare
    protected Client client; //aici am agregare

    //private double cost; costul este calculat si nu setat

    protected Programare(Date data, Medic medic, Client client) {
        this.data = data;
        this.medic = medic;
        this.client = client;
        client.addProgramare(this);
    }

    @Override
    public abstract String toString();

    protected abstract double getCostSpecial();
    public final double calculeazaCost() {
        double reducere = 1;
        if(client.getAsigurareMedicala())
            reducere = client.getReducereAsigurareMedicala();
        return medic.getCotizatie() * getCostSpecial() * reducere;
    }

    @Override
    public int compareTo(Programare other)
    {
        return data.compareTo(other.getData());
    }

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public Medic getMedic() {
        return medic;
    }

    public void setMedic(Medic medic) {
        this.medic = medic;
    }

    public Client getClient() {
        return client;
    }

    public void setClient(Client client) {
        this.client = client;
    }
}
