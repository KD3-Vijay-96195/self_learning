package com;
import java.util.stream.IntStream;

public class Program{
    public static void main(String[] args) {
        int num = 5;

        int fact = IntStream.rangeClosed(1, num)
                            .reduce(1, (a, b) -> a * b);

        System.out.println("Factorial = " + fact);
    }
}
