package cabinet.domain;

public class MedicGeneralist extends Medic{

    private final static double COTIZATIE_MEDIC_GENERALIST = 1.24;

    MedicGeneralist(String nume, String email, String numarTelefon)
    {
        super(nume,email, numarTelefon);
    }

    @Override
    public String toString()
    {
        return "Medicul " + super.getNume() + ", email " + super.getEmail() + "este generalist";
    }
    @Override
    public double getCotizatie()
    {
        return COTIZATIE_MEDIC_GENERALIST;
    }
}
