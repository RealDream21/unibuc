package exceptions.gymApp.exception;

public class GymClosedException extends Exception{
    public GymClosedException(){
        super("Gym is closed");
    }
}
