package com.sunbeam;

import java.util.Scanner;

import com.domain.Circle;
import com.domain.Cube;
import com.domain.Rectangle;
import com.domain.Sphere;

public class Program 
{
	public static Scanner sc = new Scanner(System.in);
	
	public static void circleArea()
	{
		Circle c = new Circle();
		System.out.println("enter radius of the circle : ");
		double radius = sc.nextDouble();
		c.setRadius(radius);
		System.out.println("Area of circle : "+c.area());
	}
	public static void rectangleArea()
	{
		System.out.println("Enter length : ");
		int length = sc.nextInt();
		System.out.println("enter breadth : ");
		int breadth = sc.nextInt();
		Rectangle rec = new Rectangle();
		rec.setLength(length);
		rec.setBreadth(breadth);
		System.out.println("area of rectangle : "+rec.area());
	}
	
	public static void sphereVolume()
	{
		Sphere sp = new Sphere();
		System.out.println("enter radius of sphere : ");
		sp.setRadius(sc.nextDouble());
		System.out.println("sphere volume : "+sp.volume());
	}
	
	public static void cubeVolume()
	{
		Cube c = new Cube();
		System.out.println("enter side of cube : ");
		c.setSide(sc.nextInt());
		System.out.println("volume of cube : "+c.volume());
	}
	
	public static int menuList3()
	{
		System.out.println("0. Exit");
		System.out.println("1. Sphere");
		System.out.println("2. cube");
		System.out.println("enter your choice : ");
		return sc.nextInt();
	}
	
	public static int menuList2() {
		System.out.println("0. Exit");
		System.out.println("1. Circle");
		System.out.println("2. Rectangle");
		System.out.println("enter your choice : ");
		return sc.nextInt();
	}
	
	public static int menuList()
	{
		System.out.println("0. Exit");
		System.out.println("1. 2D shape");
		System.out.println("2. 3D shape");
		System.out.println("enter your choice : ");
		return sc.nextInt();
	}
	
	public static void main(String[] args) 
	{
		int choice;
		
		while((choice = menuList()) != 0)
		{
			switch(choice) {
			case 1:
			{
				int choice2;
				while((choice2 = menuList2()) != 0) {
					switch(choice2) {
					case 1: //calculate area
						Program.circleArea();
						break;
					case 2:
						Program.rectangleArea();
						break;
					}
					
				}
				break;
			}
			case 2:
			{
				int choice3;
				while((choice3 = menuList3()) != 0) 
				{
					switch(choice3)
					{
					case 1:
						Program.sphereVolume();
						break;
					case 2:
						Program.cubeVolume();
						break;
						
					}
					
				}
				
			}
				
			}
			
		}
		
	}

}
