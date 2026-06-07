#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "../models/Product.h"
#include<vector>

std::vector<Product> products;

class Server
{
public:
    void start(int port);

private:
    std::string readFile(const std::string& path);
};

std::string Server::readFile(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        return "";
    }

    std::stringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
}

void Server::start(int port)
{
    int serverSocket =
        socket(AF_INET, SOCK_STREAM, 0);

    if(serverSocket < 0)
    {
        std::cerr << "Socket creation failed\n";
        return;
    }

    int opt = 1;

    setsockopt(
        serverSocket,
        SOL_SOCKET,
        SO_REUSEADDR,
        &opt,
        sizeof(opt)
    );

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if(bind(
        serverSocket,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)) < 0)
    {
        std::cerr << "Bind failed\n";
        return;
    }

    if(listen(serverSocket, 10) < 0)
    {
        std::cerr << "Listen failed\n";
        return;
    }

    std::cout
        << "Server running at:\n"
        << "http://localhost:"
        << port
        << "\n";

    while(true)
    {
        int clientSocket =
            accept(
                serverSocket,
                nullptr,
                nullptr
            );

        if(clientSocket < 0)
        {
            continue;
        }

        char buffer[8192] = {0};

        read(
            clientSocket,
            buffer,
            sizeof(buffer)
        );

        std::string request(buffer);

        std::cout
            << "\nREQUEST:\n"
            << request
            << "\n";

        std::string body;
        std::string contentType;

        // Home Page
        if(request.find("GET / HTTP/1.1")
           != std::string::npos)
        {
            body =
                readFile(
                    "public/index.html"
                );

            contentType =
                "text/html";
        }

        // CSS
        else if(
            request.find("GET /style.css")
            != std::string::npos)
        {
            body =
                readFile(
                    "public/style.css"
                );

            contentType =
                "text/css";
        }

        // JavaScript
        else if(
            request.find("GET /app.js")
            != std::string::npos)
        {
            body =
                readFile(
                    "public/app.js"
                );

            contentType =
                "application/javascript";
        }

        // Products API
        else if(
    request.find("POST /products")
    != std::string::npos)
{
    size_t bodyPos =
        request.find("\r\n\r\n");

    std::string requestBody =
        request.substr(bodyPos + 4);

    std::cout
        << "\nBODY:\n"
        << requestBody
        << "\n";

    Product p;

    // Very simple parsing
    size_t pos;

    pos = requestBody.find("\"id\":");
    p.id = std::stoi(
        requestBody.substr(pos + 5)
    );

    pos = requestBody.find("\"name\":\"");
    size_t start = pos + 8;
    size_t end = requestBody.find("\"", start);
    p.name =
        requestBody.substr(
            start,
            end - start
        );

    pos = requestBody.find("\"quantity\":");
    p.quantity = std::stoi(
        requestBody.substr(pos + 11)
    );

    pos = requestBody.find("\"price\":");
    p.price = std::stod(
        requestBody.substr(pos + 8)
    );

    products.push_back(p);

    std::cout
        << "\n=== PRODUCT ADDED ===\n";

    std::cout
        << p.id << " | "
        << p.name << " | "
        << p.quantity << " | "
        << p.price << "\n";

    body =
        R"({"message":"Product Added"})";

    contentType =
        "application/json";
}

        else
        {
            body =
                "<h1>404 Not Found</h1>";

            contentType =
                "text/html";
        }

        std::string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: " +
            contentType +
            "\r\n"
            "Content-Length: " +
            std::to_string(body.size()) +
            "\r\n"
            "Connection: close\r\n\r\n" +
            body;

        send(
            clientSocket,
            response.c_str(),
            response.size(),
            0
        );

        close(clientSocket);
    }
}