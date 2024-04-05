package cabinet.domain;

public class SingletonServiciuProgramare extends ServiciuProgramare{
    //aici va fi logica pentru un singleton care se ocupa de programari

    private static SingletonServiciuProgramare serviciuProgramare;

    private SingletonServiciuProgramare(){}

    public static SingletonServiciuProgramare getInstanceOfServiciuProgramare()
    {
        if(serviciuProgramare == null)
        {
            serviciuProgramare = new SingletonServiciuProgramare();
            return serviciuProgramare;
        }
        return serviciuProgramare;
    }
}
