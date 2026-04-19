package com;
enum Day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;

    public boolean isWeekend() {
        return this == SATURDAY || this == SUNDAY;
    }

    public void weekday() {
        if (isWeekend())
            System.out.println(this + " is Weekend");
        else
            System.out.println(this + " is Weekday");
    }
}

public class Program{
    public static void main(String[] args) {
        for (Day d : Day.values()) {
            d.weekday();
        }
    }
}