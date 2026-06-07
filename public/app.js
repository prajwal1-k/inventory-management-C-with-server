async function addProduct() {

    const idElement = document.getElementById("id");
    const nameElement = document.getElementById("name");
    const quantityElement = document.getElementById("quantity");
    const priceElement = document.getElementById("price");

    console.log(idElement);
    console.log(nameElement);
    console.log(quantityElement);
    console.log(priceElement);

    if (
        !idElement ||
        !nameElement ||
        !quantityElement ||
        !priceElement
    ) {
        alert("One or more input fields were not found.");
        return;
    }

    const id = idElement.value;
    const name = nameElement.value;
    const quantity = quantityElement.value;
    const price = priceElement.value;

    const response = await fetch('/products', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            id: Number(id),
            name: name,
            quantity: Number(quantity),
            price: Number(price)
        })
    });

    const result = await response.json();

    console.log(result);

    idElement.value = "";
    nameElement.value = "";
    quantityElement.value = "";
    priceElement.value = "";

    loadProducts();
}

document
    .getElementById("productForm")
    .addEventListener("submit", function(e) {
        e.preventDefault();
        addProduct();
    });