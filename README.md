# Inventory Management System (C++ HTTP Server)

## Overview

This project is a lightweight Inventory Management System built using C++ sockets without external web frameworks. It includes:

* Custom HTTP Server in C++
* Product Inventory Management
* HTML/CSS Frontend
* JavaScript API Integration
* REST-style Endpoints
* Real-time Product Display
* In-memory Product Storage

The application allows users to:

* View products
* Add new products
* Display inventory in a web interface
* Store products in server memory during runtime

---

## Project Structure

```text
inventory-management/
│
├── main.cpp
├── server.cpp
│
├── public/
│   ├── index.html
│   ├── style.css
│   └── app.js
│
└── README.md
```

---

## Technologies Used

### Backend

* C++
* TCP Socket Programming
* HTTP Protocol
* STL (Vector, String, Stream)

### Frontend

* HTML5
* CSS3
* JavaScript (Fetch API)

### Operating System

* Linux
* Ubuntu
* WSL
* macOS

---

## Features

### Product Management

* Add Product
* View Product List
* Store Inventory in Memory
* JSON-based Communication

### Server Features

* Custom Socket Server
* Route Handling
* Static File Serving
* JSON API Responses

### Frontend Features

* Product Form
* Dynamic Table Updates
* Fetch API Integration

---

## API Endpoints

### Home Page

```http
GET /
```

Returns:

```html
index.html
```

---

### CSS

```http
GET /style.css
```

Returns:

```css
style.css
```

---

### JavaScript

```http
GET /app.js
```

Returns:

```javascript
app.js
```

---

### Get Products

```http
GET /products
```

Response:

```json
[
  {
    "id": 1,
    "name": "Laptop",
    "quantity": 10,
    "price": 55000
  }
]
```

---

### Add Product

```http
POST /products
```

Request:

```json
{
  "id": 4,
  "name": "Monitor",
  "quantity": 12,
  "price": 15000
}
```

Response:

```json
{
  "message": "Product Added"
}
```

---

## Compilation

Compile using g++:

```bash
g++ main.cpp server.cpp -o inventory_server
```

---

## Running the Server

Start the application:

```bash
./inventory_server
```

Output:

```text
Server running at:
http://localhost:8080
```

---

## Access Application

Open your browser:

```text
http://localhost:8080
```

Do not open:

```text
file:///index.html
```

because Fetch API requests will fail when loaded directly from the filesystem.

---

## Example Workflow

### Step 1

Open:

```text
http://localhost:8080
```

### Step 2

Enter product details:

```text
ID: 4
Name: Monitor
Quantity: 12
Price: 15000
```

### Step 3

Click:

```text
Add Product
```

### Step 4

Server Output:

```text
=== PRODUCT ADDED ===

4 | Monitor | 12 | 15000
```

### Step 5

Product appears in the inventory table.

---

## Current Limitations

* Data stored only in memory
* No authentication
* No database integration
* Single-threaded server
* No input validation
* No persistent storage

When the server restarts, all products are cleared.

---

## Future Enhancements

### Database Integration

* SQLite
* MySQL
* PostgreSQL

### Inventory Features

* Update Product
* Delete Product
* Search Product
* Category Management
* Supplier Management
* Purchase Orders

### Security

* Authentication
* Authorization
* Session Management

### Reporting

* Inventory Reports
* Low Stock Alerts
* Sales Analytics
* Export to CSV/PDF

### AI Features

* Inventory Forecasting
* Demand Prediction
* Smart Reorder Suggestions
* AI Inventory Assistant

---

## Learning Outcomes

This project demonstrates:

* Socket Programming
* HTTP Server Development
* REST API Design
* Frontend-Backend Communication
* JSON Handling
* Inventory Management Concepts
* Full Stack Development using C++

---

## Author

Developed as a custom Inventory Management System using C++ Socket Programming and Web Technologies.
