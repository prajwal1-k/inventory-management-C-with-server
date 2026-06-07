#pragma once
#include "../services/InventoryService.h"

class ProductController {
private:
    InventoryService& service; // Reference to the inventory Service
public:
    ProductController(InventoryService& service);

    std::string getProducts();
    std::string addProduct(int id, std::string name, int qty, int price);

};