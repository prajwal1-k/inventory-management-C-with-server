#pragma once
#include <string>
#include <vector>


// pragma is used to special purposes, in this case to ensure that the header file is included only once during compilation, 
// preventing multiple definition errors.
struct Product {
    int id;
    std::string name;
    int quantity;
    int price;

    std::vector<Product> products;
};
