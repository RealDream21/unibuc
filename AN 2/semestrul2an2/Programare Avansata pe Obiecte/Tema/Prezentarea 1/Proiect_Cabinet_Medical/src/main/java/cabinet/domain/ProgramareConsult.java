package cabinet.domain;

import java.util.Calendar;
import java.util.Date;

public class ProgramareConsult extends Programare{
    int numarDeOrdine;
    private static final double COTIZATIE_CONSULT;

    public static int nr_crt = 0;
    {
        nr_crt++;
    }
    public ProgramareConsult(Date data, Medic medic, Client client, double cost)
    {
        super(data, medic, client, cost);
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
        return "Pacientul + " + client.toString() + " are programata o consultatie cu medicul " + medic.toString() + " la data de " + data.toString();
    }

    @Override
    public double calculeazaCost()
    {
        return super.calculeazaCost() * COTIZATIE_CONSULT;
    }
}
