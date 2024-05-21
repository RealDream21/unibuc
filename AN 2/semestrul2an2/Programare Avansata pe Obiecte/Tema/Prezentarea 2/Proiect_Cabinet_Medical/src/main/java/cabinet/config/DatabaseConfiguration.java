package cabinet.config;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConfiguration {
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3307/proiect_cabinet_medical";
    private static final String USER = "Fabian";
    private static final String PASSWORD = "MyRandomPassword";

    private static Connection connection;

    private DatabaseConfiguration(){}

    public static Connection getDatabaseConnection(){
        try{
            Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
        }catch(Exception e){
            throw new RuntimeException(e);
        }

        try{
            if(connection == null || connection.isClosed()){
                connection = DriverManager.getConnection(DATABASE_URL, USER, PASSWORD);
            }
        }catch(SQLException e){
            throw new RuntimeException(e);
        }
        return connection;
    }

    public void closeDatabaseConnection(){
        try{
            if(connection != null && !connection.isClosed()){
                connection.close();
            }
        }catch(SQLException e)
        {
            throw new RuntimeException(e);
        }
    }
}
