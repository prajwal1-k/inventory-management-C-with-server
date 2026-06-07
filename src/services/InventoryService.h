#pragma once
#include "../models/Product.h"
#include <vector>

class InventoryService {
private:
    std::vector<Product> products;  // In-memory storage for products, product us the private access specifier which emans that can be accessed only 
    // within the class

public:
    void addProduct(Product product);  // Method to add a product to the inventory
    std::vector<Product> getProducts();  // Method to retrieve all products from

    bool updateProduct(int id, int quantity);  // Method to update the quantity of a product in the inventory
    bool deleteProduct(int id);  // Method to delete a product from the inventory
};