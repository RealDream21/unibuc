package cabinet.domain;

public class MedicSpecialist extends Medic{
    private static final double COTIZATIE_MEDIC_SPECIALIST = 1.3;
    Specializare specializare;

    public MedicSpecialist(String nume, Specializare specializare)
    {
        super(nume);
        this.specializare = specializare;
    }

    public MedicSpecialist(String nume, Specializare specializare, String email)
    {
        super(nume, email);
        this.specializare = specializare;
    }

    @Override
    public String toString(){
        return "Medicul " + nume + " ,email " + email + " este specialist in " + specializare.toString();
    }
    @Override
    public double getCotizatie(){
        return COTIZATIE_MEDIC_SPECIALIST;
    }
}
