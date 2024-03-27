package asocieri;

import asocieri.Domain.Departament;
import asocieri.Domain.Profesor;
import asocieri.Domain.Universitate;

public class Main {
    public static void main(String[] args) {
        Profesor[] profesoriInfo = {
                new Profesor(1, "Ionescu"),
                new Profesor(2, "Popescu"),
                new Profesor(3, "Georgescu")
        };
        Profesor[] profesoriMate ={
                new Profesor(1, "Ion"),
                new Profesor(2, "Popa"),
                new Profesor(3, "Geroge")
        };

        Departament departamentInfo = new Departament("info", profesoriInfo);
        Departament departamentMate = new Departament("mate", profesoriMate);

        Universitate unibuc = new Universitate("unibuc", new Departament[]{departamentInfo, departamentMate});

        System.out.println(unibuc.toString());
    }

}
