// calculator.js

// Import readline module
const readline = require("readline");

// Create interface
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Take first number
rl.question("Enter first number: ", (num1) => {

    // Take second number
    rl.question("Enter second number: ", (num2) => {

        // Take operator
        rl.question("Enter operation (+, -, *, /): ", (operator) => {

            // Convert string to number
            num1 = Number(num1);
            num2 = Number(num2);

            let result;

            // Perform operation
            switch(operator) {

                case "+":
                    result = num1 + num2;
                    break;

                case "-":
                    result = num1 - num2;
                    break;

                case "*":
                    result = num1 * num2;
                    break;

                case "/":
                    result = num1 / num2;
                    break;

                default:
                    console.log("Invalid Operator");
                    rl.close();
                    return;
            }

            // Display result
            console.log("Result =", result);

            // Close interface
            rl.close();

        });

    });

});