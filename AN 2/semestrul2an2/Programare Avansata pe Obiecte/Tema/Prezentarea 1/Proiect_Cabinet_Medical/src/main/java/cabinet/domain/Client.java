package cabinet.domain;

public class Client {
    String nume;
    String numarTelefon;
    String adresa;
    boolean asigurareMedicala;
    Programare[] istoricProgramari;//astea sa fie afisate in ordine crescatoare dupa data lor sau cv
    String[] observatii;//diverse alergii si altele

    public Client() {
        this.asigurareMedicala = false;
    }

    public Client(String nume)
    {
        this();
        this.nume = nume;
    }

    public Client(String nume, String numarTelefon)
    {
        this(nume);
        String regexTelefon = "0[0-9]{9}+";
        if(numarTelefon.matches(regexTelefon)){
            this.numarTelefon = numarTelefon;
        }
        else {
            this.numarTelefon = "NUMAR_INVALID";
        }
    }

    public Client(String nume, String numarTelefon, String adresa)
    {
        this(nume, numarTelefon);
        this.adresa = adresa;
    }

    public Client(String nume, String numarTelefon, String adresa, boolean asigurareMedicala)
    {
        this(nume, numarTelefon, adresa);
        this.asigurareMedicala = asigurareMedicala;
    }

    public String getNume() {
        return nume;
    }

    public String getNumarTelefon() {
        return numarTelefon;
    }

    public String getAdresa() {
        return adresa;
    }

    public boolean isAsigurareMedicala() {
        return asigurareMedicala;
    }

    public Programare[] getIstoricProgramari() {
        return istoricProgramari;
    }

    public String[] getObservatii() {
        return observatii;
    }

    @Override
    public String toString(){
        return "Metoda toString() inca nu a fost suprascrisa dar trebuie suprascrisa";
    }
}
