package cabinet.domain;

import java.util.Arrays;

public class Client extends Persoana{
    private boolean asigurareMedicala;
    private Programare[] istoricProgramari;//astea sa fie afisate in ordine crescatoare dupa data lor sau cv
    private String[] observatii;//diverse alergii si altele


    public Client(String nume, String email, String numarTelefon)
    {
        super(nume, email, numarTelefon);
    }

    public Client(String nume, String email, String numarTelefon, boolean asigurareMedicala)
    {
        this(nume,email,numarTelefon);
        this.asigurareMedicala = asigurareMedicala;
    }

    public boolean isAsigurareMedicala() {
        return asigurareMedicala;
    }

    public void setAsigurareMedicala(boolean asigurareMedicala) {
        this.asigurareMedicala = asigurareMedicala;
    }

    public Programare[] getIstoricProgramari() {
        return Arrays.copyOf(istoricProgramari, istoricProgramari.length);
    }

    public String[] getObservatii() {
        return Arrays.copyOf(observatii, observatii.length);
    }

    @Override
    public String toString() {
        return "Clientul se numeste: " + nume;
    }
}
