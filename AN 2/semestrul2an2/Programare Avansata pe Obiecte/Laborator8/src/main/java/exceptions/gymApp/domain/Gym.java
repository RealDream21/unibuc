package exceptions.gymApp.domain;

import exceptions.gymApp.exception.GymAccessDeniedException;

public class Gym {
    private int totalSeats;

    private int bookedSeats;

    public static final LocalTime startTime = LocalTime.of(9, 0);
    public static final LocalTime endTime = LocalTime.of(9, 0);

    public int getTotalSeats(){
        return totalSeats;
    }

    public void setTotalSeats(int totalSeats){

        if(totalSeats <= 0){
            throw new IllegalArgumentException();
        }
        this.totalSeats = totalSeats;
    }

    public int getBookedSeats(){
        return bookedSeats;
    }

    public void set

    public void setBookedSeats(int bookedSeats) {
        this.bookedSeats = bookedSeats;
    }

    public void bookSeatedClass(Object object){
        if(object instanceof Member){
            if(LocalTime.now().isAfter(Gym.startTime) && LocalTime.now().isBefore(Gym.endTime)){
                if(gym.get)

            }
            else{
                throw new GymClosedException();
            }


        }else{
            throw new GymAccessDeniedException();
        }

    }

}
