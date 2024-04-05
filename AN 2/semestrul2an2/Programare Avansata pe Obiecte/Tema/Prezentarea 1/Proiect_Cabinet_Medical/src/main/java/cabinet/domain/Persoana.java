package cabinet.domain;

public abstract class Persoana {
    protected String nume;
    protected String email;
    protected String numarTelefon;

    public Persoana(String nume, String email, String numarTelefon) {
        this.nume = nume;
        this.email = email;
        String regexTelefon = "0[0-9]{9}+";
        if(numarTelefon.matches(regexTelefon)){
            this.numarTelefon = numarTelefon;
        }
        else {
            this.numarTelefon = "NUMAR_INVALID";
        }
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getNumarTelefon() {
        return numarTelefon;
    }

    public void setNumarTelefon(String numarTelefon) {
        this.numarTelefon = numarTelefon;
    }

    public abstract String toString();
}
