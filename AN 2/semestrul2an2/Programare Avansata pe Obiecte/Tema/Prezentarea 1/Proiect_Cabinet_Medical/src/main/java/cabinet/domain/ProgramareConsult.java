package cabinet.domain;

import java.util.Date;

public class ProgramareConsult extends Programare{
    int numarDeOrdine;
    private static final double COTIZATIE_CONSULT = 1.23;
    private static final double COST_STANDARD = 100;

    public static int nr_crt = 0;
    {
        nr_crt++;
    }
    public ProgramareConsult(Date data, Medic medic, Client client)
    {
        super(data, medic, client);
        this.numarDeOrdine = nr_crt;
    }

    public int getNumarDeOrdine() {
        return numarDeOrdine;
    }

    public static int getNr_crt() {
        return nr_crt;
    }

    @Override
    public String toString() {
        return client.toString() + " are programata o consultatie cu medicul " + medic.toString() + " la data de " + data.toString() + " costul consultatiei va fi " + this.calculeazaCost();
    }

//    @Override
//    public double calculeazaCost()
//    {
//        return super.calculeazaCost() * COTIZATIE_CONSULT;
//    }

    @Override
    protected double getCostSpecial()
    {
        return COTIZATIE_CONSULT * COST_STANDARD;
    }
}
