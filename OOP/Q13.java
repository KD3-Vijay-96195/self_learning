package com;
import java.util.Arrays;
import java.util.Comparator;

class Student {
    private int roll;
    private String name;
    private String city;
    private double marks;

    public Student(int roll, String name, String city, double marks) {
        this.roll = roll;
        this.name = name;
        this.city = city;
        this.marks = marks;
    }

    public String getName() {
        return name;
    }

    public String getCity() {
        return city;
    }

    public double getMarks() {
        return marks;
    }

    @Override
    public String toString() {
        return roll + " " + name + " " + city + " " + marks;
    }
}

public class Program {
    public static void main(String[] args) {
        Student[] arr = {
                new Student(1, "Prajwal", "Sangli", 85.5),
                new Student(2, "Amit", "Pune", 90.0),
                new Student(3, "Rahul", "Pune", 90.0),
                new Student(4, "Sneha", "Mumbai", 88.0),
                new Student(5, "Ankit", "Pune", 75.0)
        };

        Arrays.sort(arr,
                Comparator.comparing(Student::getCity, Comparator.reverseOrder())
                        .thenComparing(Student::getMarks, Comparator.reverseOrder())
                        .thenComparing(Student::getName)
        );

        for (Student s : arr) {
            System.out.println(s);
        }
    }
}