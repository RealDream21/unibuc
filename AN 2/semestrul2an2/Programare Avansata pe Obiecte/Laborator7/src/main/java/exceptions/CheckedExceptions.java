package exceptions;

import java.io.IOException;
import java.sql.SQLException;

//IOException, SQLException
public class CheckedExceptions {
    public static void main(String[] args) {
        try{
            doSomething();
            //doSOmethingElse();
        }catch(IOException e){
            //e.printStackTrace();
            //System.out.println(e.toString());
            System.out.println(e.getMessage());
        }

    }

    public static void doSomething() throws IOException{
        throw new IOException("problem");
    }

    public static void doSOmethingElse() throws RuntimeException, IOException{
        throw new RuntimeException("problem");
    }

}
