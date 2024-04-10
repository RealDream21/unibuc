package exceptions.Override;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) {
        ParentClass parent = new ChildClass();

        try{
            parent.myFirstMethod();
//            parent.mySecondMethod();

        }
        catch (IOException e){
            e.printStackTrace();
        }

    }

}
