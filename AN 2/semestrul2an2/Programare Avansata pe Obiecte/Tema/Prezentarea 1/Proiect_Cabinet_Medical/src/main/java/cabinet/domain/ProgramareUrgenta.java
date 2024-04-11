package cabinet.domain;

import java.util.Calendar;
import java.util.Date;

public class ProgramareUrgenta extends Programare{

    private final double COST_PER_GRAD_URGENTA = 100;
    private static final int URGENTA_MAXIMA = 10;
    int gradUrgenta;

    public ProgramareUrgenta(Date data, Medic medic, Client client, int gradUrgenta)
    {
        super(data, medic, client);
        this.gradUrgenta = gradUrgenta;
    }

    public int getGradUrgenta() {
        return gradUrgenta;
    }

    @Override
    public String toString()
    {
        return client.toString() + " are programare de urgenta la data: " + data.toString()+ " cu medicul " + medic.toString() + " gradul de urgenta este: " + gradUrgenta + " costul acestei interventii va fi " + this.calculeazaCost();
    }

    public static int getURGENTA_MAXIMA()
    {
        return URGENTA_MAXIMA;
    }

//    @Override
//    public double calculeazaCost()
//    {
//        return super.calculeazaCost() + gradUrgenta * super.calculeazaCost();
//    }

    @Override
    protected double getCostSpecial()
    {
        return gradUrgenta * COST_PER_GRAD_URGENTA;
    }
}
