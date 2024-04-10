package interfaces.genericeSecond.service;

import interfaces.genericeSecond.domain.Filterable;
import interfaces.genericeSecond.domain.Product;

import java.util.Arrays;

public class ProductService {
    private Product[] products = new Product[10];

    public ProductService()
    {
        initializeProdcuts();
    }

    public void displayShopContent(){
        System.out.println(Arrays.toString(products));
    }

    public Product[] filterByName(Filterable filterable, String name){
        return filterable.filter(this.products, name);
    }

    public Product[] filterByPrice(Filterable filterable, double price)
    {
        return filterable.filter(this.products, price);
    }

    private void initializeProdcuts(){
        for(int i = 0; i < products.length; i++){
            products[i] = new Product("name" + i, i + 12, i * 2.5);
        }

        products[0].setPrice(50);
        products[3].setPrice(50);

    }

}
