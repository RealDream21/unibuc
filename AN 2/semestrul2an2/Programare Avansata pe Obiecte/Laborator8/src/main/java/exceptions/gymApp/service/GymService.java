package exceptions.gymApp.service;

import exceptions.gymApp.domain.Gym;

public class GymService {
    private Gym gym;

    public GymService(int capacity){
        this.gym = new Gym();
    }

    public GymService(int capacity){
        this.gym = new Gym();
        gym.setTotalSeats(capacity);
    }




}
