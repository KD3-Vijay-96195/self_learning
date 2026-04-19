package com;
class Address {
    String city;

    public Address(String city) {
        this.city = city;
    }

    @Override
    public String toString() {
        return city;
    }
}

class Student {
    private int rollNo;
    private String name;
    private Address address;

    public Student() {
        this.rollNo = 0;
        this.name = "Unknown";
        this.address = new Address("Not Assigned");
    }

    public Student(int rollNo, String name, Address address) {
        this.rollNo = rollNo;
        this.name = name;
        this.address = address;
    }

    public Student(Student s) {
        this.rollNo = s.rollNo;
        this.name = s.name;
        this.address = s.address;
    }

    public Student deepCopy() {
        return new Student(this.rollNo, this.name, new Address(this.address.city));
    }

    public void setCity(String city) {
        this.address.city = city;
    }

    @Override
    public String toString() {
        return "Student [rollNo=" + rollNo + ", name=" + name + ", city=" + address + "]";
    }
}

public class Program {
    public static void main(String[] args) {
        Student s1 = new Student(1, "Prajwal", new Address("Sangli"));
        Student s2 = new Student(s1);
        Student s3 = s1.deepCopy();

        System.out.println("Before change:");
        System.out.println("Original : " + s1);
        System.out.println("Shallow : " + s2);
        System.out.println("Deep    : " + s3);

        s1.setCity("Pune");

        System.out.println("\nAfter changing original city:");
        System.out.println("Original : " + s1);
        System.out.println("Shallow : " + s2);
        System.out.println("Deep    : " + s3);
    }
}