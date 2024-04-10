package interfaces.genericeSecond.domain;

import java.util.Arrays;

public class NameFilter implements Filterable<String>{


    @Override
    public Product[] filter(Product[] products, String value) {
        Product[] filtered = new Product[0];

        for(Product product : products)
        {
            if(product.getName().toLowerCase().contains(value.toLowerCase())){
                filtered = Arrays.copyOf(filtered, filtered.length + 1);
                filtered[filtered.length - 1] = product;
            }
        }
        return filtered;
    }
}
