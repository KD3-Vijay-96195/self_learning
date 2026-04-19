package com;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String str = sc.nextLine().toLowerCase();

        int vowels = 0, consonants = 0, special = 0, digits = 0, spaces = 0;

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if (ch >= 'a' && ch <= 'z') {
                if ("aeiou".indexOf(ch) != -1)
                    vowels++;
                else
                    consonants++;
            } else if (ch >= '0' && ch <= '9') {
                digits++;
            } else if (ch == ' ') {
                spaces++;
            } else {
                special++;
            }
        }

        System.out.println("Vowels = " + vowels);
        System.out.println("Consonants = " + consonants);
        System.out.println("Digits = " + digits);
        System.out.println("Spaces = " + spaces);
        System.out.println("Special Characters = " + special);
    }
}