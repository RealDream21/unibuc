package asocieri.Domain;

public class Profesor {
    int id;
    String nume;

    public Profesor(int id, String nume)
    {
        this.nume = nume;
        this.id = id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNume() {
        return nume;
    }
    public void setNume(String nume)
    {
        this.nume = nume;
    }

    @Override
    public String toString(){
        return "Profesor: id= " + id + " nume" + nume;
    }


}
