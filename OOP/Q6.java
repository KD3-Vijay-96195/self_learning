package com;
class EcommerceException extends Exception {
    public EcommerceException(String message) {
        super(message);
    }
}

class PaymentException extends EcommerceException {
    public PaymentException(String message) {
        super(message);
    }
}

class InventoryException extends EcommerceException {
    public InventoryException(String message) {
        super(message);
    }
}

class ShippingException extends EcommerceException {
    public ShippingException(String message) {
        super(message);
    }
}

class OrderService {
    public void processOrder(boolean payment, boolean stock, boolean shipping)
            throws PaymentException, InventoryException, ShippingException {

        if (!payment)
            throw new PaymentException("Payment failed");

        if (!stock)
            throw new InventoryException("Item out of stock");

        if (!shipping)
            throw new ShippingException("Shipping unavailable");

        System.out.println("Order processed successfully");
    }
}

public class Program {
    public static void main(String[] args) {
        OrderService order = new OrderService();

        try {
            order.processOrder(true, false, true);
        } catch (EcommerceException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}