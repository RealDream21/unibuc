package cabinet.domain;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Client extends Persoana{
    private static double REDUCERE_ASIGURARE_MEDICALA = 0.8;
    private boolean asigurareMedicala;
    private List<Programare> istoricProgramari;//astea sa fie afisate in ordine crescatoare dupa data lor sau cv
    private String[] observatii;//diverse alergii si altele


    public Client(String nume, String email, String numarTelefon)
    {
        super(nume, email, numarTelefon);
        istoricProgramari = new ArrayList<Programare>();
    }

    public Client(String nume, String email, String numarTelefon, boolean asigurareMedicala)
    {
        this(nume,email,numarTelefon);
        this.asigurareMedicala = asigurareMedicala;
    }

    public void addProgramare(Programare programare)
    {
        istoricProgramari.add(programare);
    }

    public void addObservatie(String observatie)
    {
        observatii[observatii.length] = observatie;
    }

    public boolean getAsigurareMedicala() {
        return asigurareMedicala;
    }

    public void setAsigurareMedicala(boolean asigurareMedicala) {
        this.asigurareMedicala = asigurareMedicala;
    }

    public List<Programare> getIstoricProgramari() {
        return istoricProgramari;
    }
    public double getReducereAsigurareMedicala()
    {
        return REDUCERE_ASIGURARE_MEDICALA;
    }

    public String[] getObservatii() {
        return Arrays.copyOf(observatii, observatii.length);
    }

    @Override
    public String toString() {
        return "Clientul se numeste: " + nume;
    }
}
