package exceptions.gymApp;

import exceptions.gymApp.domain.Member;
import exceptions.gymApp.service.GymService;

public class Main {
    public static void main(String[] args) {
        GymService service = new GymService(100);

        Member member = new Member();

        Object nonMember = new Object();

        try{
            service.bookSeatedClass();
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

    }

}
