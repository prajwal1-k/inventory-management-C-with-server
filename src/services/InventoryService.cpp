#include "./InventoryService.h"

void InventoryService::addProduct(Product product) {
    products.push_back(product);  // Add the product to the in-memory storage
}

std::vector<Product>InventoryService::getProducts(){
    return products;  
}

bool InventoryService::updateProduct(int id, int quantity){
    // Here we have to run the for loop as there will be multiple products in the inventory
    for (auto& product: products){
        if(product.id == id){
            product.quantity = quantity;  // Update the quantity of the product
            return true;
        }
    }
    return false;  // Return false if the product with the given id is not found
}

bool InventoryService::deleteProduct(int id){
    for(auto it = products.begin(); it != products.end(); it++){
        if(it->id == id){
            products.erase(it);  // this will erase the product from the inventory
            return true;
        }

    }
    return false; // Not Found
}