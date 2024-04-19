package exceptions.gymApp.exception;

import exceptions.gymApp.domain.Gym;

public class GymAccessDeniedException extends Exception{

    public GymAccessDeniedException(){
        super("You are not a member of this club");
    }

}
