package interfaces.comparable;

public class CatHouse {
    public static void main(String[] args) {
        Cat cats[] = {
                new Cat("Luna", 7),
                new Cat("Tom", 5),
                new Cat("Lucy", 2),
                new Cat("Kitty", 12)
        };

        System.out.println("Unsorted: " + Arrays.toString(cats));
        Arrays.sort(cats);
        System.out.println("Sorted: " + Arrays.toString(cats));

    }


}
