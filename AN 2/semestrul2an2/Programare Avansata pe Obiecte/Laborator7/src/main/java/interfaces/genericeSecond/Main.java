package interfaces.genericeSecond;

import interfaces.genericeSecond.domain.NameFilter;
import interfaces.genericeSecond.domain.PriceFilter;
import interfaces.genericeSecond.domain.Product;
import interfaces.genericeSecond.service.ProductService;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        ProductService productService = new ProductService();

        productService.displayShopContent();

        Product[] filteredByName = productService.filterByName(new NameFilter(), "name 1");
        System.out.printf(Arrays.toString(filteredByName));

        Product[] filteredByPrice = productService.filterByPrice(new PriceFilter(), 50);
        System.out.println(Arrays.toString(filteredByPrice));
    }

}
