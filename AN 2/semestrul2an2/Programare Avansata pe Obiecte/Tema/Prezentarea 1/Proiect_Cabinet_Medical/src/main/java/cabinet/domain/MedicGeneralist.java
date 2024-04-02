package cabinet.domain;

public class MedicGeneralist extends Medic{

    final static double COTIZATIE_MEDIC_GENERALIST = 1.3;


    @Override
    public String toString()
    {
        return "Medicul " + nume + ", email " + email + "este generalist";
    }
    @Override
    public double getCotizatie()
    {
        return COTIZATIE_MEDIC_GENERALIST;
    }
}
