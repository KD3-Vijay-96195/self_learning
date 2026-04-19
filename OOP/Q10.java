package com;
public class Program{
    public static <T extends Number> T findMin(T[] arr) {
        T min = arr[0];

        for (T num : arr) {
            if (num.doubleValue() < min.doubleValue()) {
                min = num;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        Integer[] arr = {45, 12, 78, 3, 99};

        Integer min = findMin(arr);

        System.out.println("Minimum = " + min);
    }
}