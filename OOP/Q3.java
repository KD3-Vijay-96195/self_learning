package com;
class Animal {
    protected String name;

    public Animal(String name) {
        this.name = name;
    }

    public void sound() {
        System.out.println("Animal makes sound");
    }
}

class Lion extends Animal {
    public Lion(String name) {
        super(name);
    }

    @Override
    public void sound() {
        System.out.println(name + " roars");
    }
}

class Zoo {
    private Animal animal;

    public Zoo(Animal animal) {
        this.animal = animal;
    }

    public void showAnimal() {
        animal.sound();
    }
}

public class Program {
    public static void main(String[] args) {
        Animal a = new Lion("Simba");
        Zoo z = new Zoo(a);
        z.showAnimal();
    }
}