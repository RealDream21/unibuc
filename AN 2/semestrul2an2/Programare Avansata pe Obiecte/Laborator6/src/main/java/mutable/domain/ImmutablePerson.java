package mutable.domain;

public class ImmutablePerson {
    private final int id;

    private final String name;

    private final MutableDateOfBirth dateOfBirth;

    public ImmutablePerson(int id, java.lang.String name, MutableDateOfBirth dateOfBirth) {
        this.id = id;
        this.name = name;
        this.dateOfBirth = dateOfBirth;
    }


    @Override
    public String toString(){
        return "Immutable person id = " + id +
                ", name = " + name +
                ", birthday = " + dateOfBirth;
    }


    public int getId() {
        return id;
    }

    public java.lang.String getName() {
        return name;
    }

    public MutableDateOfBirth getDateOfBirth() {
        return dateOfBirth;
    }
}
