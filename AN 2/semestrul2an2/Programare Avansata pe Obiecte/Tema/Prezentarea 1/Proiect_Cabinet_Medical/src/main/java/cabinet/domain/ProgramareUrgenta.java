package cabinet.domain;

import java.util.Date;

public class ProgramareUrgenta extends Programare{

    int gradUrgenta;

    public ProgramareUrgenta(Date data, Medic medic, Client client, double cost, int gradUrgenta)
    {
        super(data, medic, client, cost);
        this.gradUrgenta = gradUrgenta;
    }

    public int getGradUrgenta() {
        return gradUrgenta;
    }

    @Override
    public String toString()
    {
        return "Pacientul: " + client.toString() + " are programare de urgenta la data: " + data.toString()+ " cu medicul " + medic.toString() + " gradul de urgenta este: " + gradUrgenta;
    }

    @Override
    public double calculeazaCost()
    {
        return super.calculeazaCost() + gradUrgenta * super.calculeazaCost();
    }
}
