package Builder.domain;

public class Pizza {
    private String name;

    private Size size;

    private boolean tomatoTopping;

    private boolean oliveTopping;
    private boolean mozarellaTopping;

    private boolean pepperoniTopping;
    @Override
    public String toString()
    {
        return "Pizza: name = " + name + ", " +
                    "size = " + size + ", " +
                    "tomatoTopping: " + tomatoTopping + ", " +
                    "oliveTopping: " + oliveTopping + ", " +
                    "mozarellaTopping: " + mozarellaTopping + ", " +
                    "pepperoniTopping: " + pepperoniTopping;
    }


    public static class Builder{
        private Pizza pizza = new Pizza();

        public Pizza build(){
            return this.pizza;
        }

        public Builder(String name){
            pizza.name = name;
        }

        public Builder withSize(Size size){
            pizza.size = size;
            return this;
        }

        public Builder withTomatoTopping(boolean topping){
            this.pizza.tomatoTopping = topping;
            return this;
        }

        public Builder withOliveTopping(boolean topping){
            this.pizza.oliveTopping = topping;
            return this;
        }
        public Builder withMozarellaTopping(boolean topping){
            this.pizza.mozarellaTopping = topping;
            return this;
        }

        public Builder withPepperoniTopping(boolean topping){
            this.pizza.pepperoniTopping = topping;
            return this;
        }


    }

}
