package exceptions.Override;

import java.io.IOException;
import java.sql.SQLException;

public class ParentClass {

    public void myFirstMethod() throws IOException {
        throw new IOException();
    }

    public void mySecondMethod() throws SQLException {
    }

}
