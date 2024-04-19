package exceptions;

public class TryWithResources implements AutoCloseable {


    @Override
    public void close() throws Exception {
        System.out.println("Close my resources");
    }
}

class Test{
    public static void main(String[] args) throws Exception{
        TryWithResources resources = null;

        try{
            resources = new TryWithResources();
            //something with resource field
        }catch(Exception e) {
            resources = new TryWithResources();
        }finally {
            if(resources != null)
                resources.close();
        }

        try(TryWithResources resources1 = new TryWithResources()){
            //work with the field
        }finally{
            System.out.println("Final");
        }




    }


}
