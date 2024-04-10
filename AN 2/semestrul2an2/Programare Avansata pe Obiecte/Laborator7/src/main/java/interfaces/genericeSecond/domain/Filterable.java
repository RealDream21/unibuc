package interfaces.genericeSecond.domain;

public interface Filterable<T> {

    Product[] filter(Product[] products, T value);
}
