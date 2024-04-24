package org.example.config;

import java.net.ConnectException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConfiguration {


    private static final String DATABASE_URL = "jdbc:mysql://localhost:3307/lab9";

    private static final String USER = "User";

    private static final String PASSWORD = "MyRandomPassword";

    private static Connection connection;

    private DatabaseConfiguration(){

    }

    public static Connection getDatabaseConnection(){
        try{
            if(connection == null || connection.isClosed()){
                connection = DriverManager.getConnection(DATABASE_URL, USER, PASSWORD);
            }
        }catch(SQLException e){
            e.printStackTrace();
        }
        return connection;
    }
}
