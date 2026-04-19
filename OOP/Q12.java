package com;
import java.util.Comparator;
import java.util.Arrays;

public class Program {
    public static <T> void selectionSort(T[] arr, Comparator<T> c) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (c.compare(arr[i], arr[j]) > 0) {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Integer[] arr = {64, 25, 12, 22, 11};

        selectionSort(arr, (a, b) -> a - b);

        System.out.println(Arrays.toString(arr));
    }
}