package cabinet.domain;

public abstract class Persoana{
    protected String nume;
    protected String email;
    protected String numarTelefon;

    public Persoana(String nume, String email, String numarTelefon) {
        if(verificaNume(nume))
        {
            this.nume = nume;
        }
        else {
            this.nume = "NUME_INVALID";
        }

        if(verificaEmail(email))
        {
            this.email = email;
        }
        else{
            this.email = "EMAIL_INVALID";
        }

        if(verificaTelefon(numarTelefon)){
            this.numarTelefon = numarTelefon;
        }
        else {
            this.numarTelefon = "NUMAR_INVALID";
        }
    }

    private static boolean verificaNume(String nume)
    {
        String regexNume = "[A-Z][a-z]+";
        if(nume.matches(regexNume))
            return true;
        return false;
    }

    private static boolean verificaEmail(String email)
    {
        String regexEmail = "^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$";
        if(email.matches(regexEmail))
            return true;
        return false;
    }

    private static boolean verificaTelefon(String numarTelefon)
    {
        String regexTelefon = "0[0-9]{9}+";
        if(numarTelefon.matches(regexTelefon))
            return true;
        return false;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        if(verificaNume(nume))
            this.nume = nume;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        if(verificaEmail(email))
            this.email = email;
    }

    public String getNumarTelefon() {
        return numarTelefon;
    }

    public void setNumarTelefon(String numarTelefon) {
        if(verificaTelefon(numarTelefon))
            this.numarTelefon = numarTelefon;
    }

    public abstract String toString();
}
