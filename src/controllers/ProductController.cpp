#include "ProductController.h"
#include <sstream>

ProductController::ProductController(
    InventoryService& service)
    : service(service)
{
}

std::string
ProductController::getProducts()
{
    auto products =
        service.getProducts();

    std::stringstream json;

    json << "[";

    for(size_t i=0;i<products.size();i++)
    {
        json << "{";
        json << "\"id\":" << products[i].id << ",";
        json << "\"name\":\""
             << products[i].name
             << "\",";
        json << "\"quantity\":"
             << products[i].quantity
             << ",";
        json << "\"price\":"
             << products[i].price;
        json << "}";

        if(i < products.size()-1)
            json << ",";
    }

    json << "]";

    return json.str();
}

std::string
ProductController::addProduct(
    int id,
    std::string name,
    int qty,
    int price)
{
    service.addProduct({
        id,
        name,
        qty,
        price
    });

    return R"({"message":"Product Added"})";
}