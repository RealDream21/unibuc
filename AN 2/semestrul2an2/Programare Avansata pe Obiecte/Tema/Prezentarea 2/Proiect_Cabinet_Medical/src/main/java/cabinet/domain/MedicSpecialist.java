package cabinet.domain;

public class MedicSpecialist extends Medic{
    private static final double COTIZATIE_MEDIC_SPECIALIST = 2.12;
    Specializare specializare;

    MedicSpecialist(String nume, String adresa, String numarTelefon, Specializare specializare)
    {
        super(nume, adresa, numarTelefon);
        this.specializare = specializare;
    }

    @Override
    public String toString(){
        return "Medicul " + super.getNume() + ", email " + super.getEmail() + " este specialist " + specializare.toString();
    }
    @Override
    public double getCotizatie(){
        return COTIZATIE_MEDIC_SPECIALIST;
    }
}
