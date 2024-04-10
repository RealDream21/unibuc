package interfaces.genericeSecond.domain;

import java.util.Arrays;

public class PriceFilter implements Filterable<Double>{


    @Override
    public Product[] filter(Product[] products, Double value) {
        Product filtered[] = new Product[0];

        for(Product product: products)
        {
            if(product.getPrice() == value){
                filtered = Arrays.copyOf(filtered, filtered.length + 1);
                filtered[filtered.length - 1] = product;
            }

        }
        return filtered;
    }
}
