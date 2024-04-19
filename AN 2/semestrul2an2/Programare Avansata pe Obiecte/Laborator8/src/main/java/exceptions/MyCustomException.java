package exceptions;

public class MyCustomException extends Exception{

    private String code;

    public MyCustomException(){
        super();
    }

    public MyCustomException(String message){
        super(message);
    }

    public MyCustomException(String code, String message, Throwable cause){
        super(message, cause);
        this.code = code;
    }


}
