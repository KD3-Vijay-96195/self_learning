// server.js

const http = require("http");

// Dummy Product Data
let products = [
    { id: 1, name: "Laptop", price: 50000 },
    { id: 2, name: "Mobile", price: 20000 },
    { id: 3, name: "Keyboard", price: 1500 }
];

// Create Server
const server = http.createServer((req, res) => {

    // Set Response Type
    res.setHeader("Content-Type", "application/json");

    // GET ALL PRODUCTS
    if (req.method === "GET" && req.url === "/products") {

        res.statusCode = 200;
        res.end(JSON.stringify(products));
    }

    // POST PRODUCT
    else if (req.method === "POST" && req.url === "/products") {

        let body = "";

        req.on("data", chunk => {
            body += chunk.toString();
        });

        req.on("end", () => {

            const newProduct = JSON.parse(body);

            products.push(newProduct);

            res.statusCode = 201;

            res.end(JSON.stringify({
                message: "Product Added",
                products
            }));
        });
    }

    // PUT PRODUCT
    else if (req.method === "PUT" && req.url.startsWith("/products/")) {

        const id = parseInt(req.url.split("/")[2]);

        let body = "";

        req.on("data", chunk => {
            body += chunk.toString();
        });

        req.on("end", () => {

            const updatedData = JSON.parse(body);

            const index = products.findIndex(p => p.id === id);

            if (index !== -1) {

                products[index] = {
                    ...products[index],
                    ...updatedData
                };

                res.statusCode = 200;

                res.end(JSON.stringify({
                    message: "Product Updated",
                    product: products[index]
                }));

            } else {

                res.statusCode = 404;

                res.end(JSON.stringify({
                    message: "Product Not Found"
                }));
            }
        });
    }

    // DELETE PRODUCT
    else if (req.method === "DELETE" && req.url.startsWith("/products/")) {

        const id = parseInt(req.url.split("/")[2]);

        const index = products.findIndex(p => p.id === id);

        if (index !== -1) {

            const deletedProduct = products.splice(index, 1);

            res.statusCode = 200;

            res.end(JSON.stringify({
                message: "Product Deleted",
                deletedProduct
            }));

        } else {

            res.statusCode = 404;

            res.end(JSON.stringify({
                message: "Product Not Found"
            }));
        }
    }

    // INVALID ROUTE
    else {

        res.statusCode = 404;

        res.end(JSON.stringify({
            message: "Route Not Found"
        }));
    }

});

// Start Server
server.listen(3000, () => {
    console.log("Server running on port 3000");
});