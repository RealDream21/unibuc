package interfaces.multipleInheritence;

public class Hero extends ActionCharacter implements CanFight, CanFly, CanSwim{


    @Override
    public void canFly() {
        System.out.printf("Fly\n");

    }

    @Override
    public void canSwim() {
        System.out.printf("Swim\n");
    }
}
