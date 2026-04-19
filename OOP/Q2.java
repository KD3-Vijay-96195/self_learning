package com.sunbeam;


class shape{


	public shape() {}
		public double calarea() {
			return 0;
		}
		public double calvol() {
			return 0;
		}
}

class shape2d extends shape{
	public shape2d() {
		
	}
	
	
}
class shape3d extends shape{
	public shape3d() {
		
	}
	

}
class circle extends shape2d{
	private double r;
	
	public circle(double r) {
		this.r=r;
	}
	@Override
	public double calarea() {
		return 3.14*this.r*this.r;
	}
	
	
}
class rectangle extends shape2d{
	private double l;
	private double b;
	public rectangle(double l,double b) {
      this.l=l;
      this.b=b;
	}
	@Override
	public double calarea() {
		return this.l*this.b;
	}
	
	
}
class cube extends shape3d{
	private double a;
	public cube(double a) {
		this.a=a;
	}
	@Override
	public double calarea() {
		return 6*a*a;
	}
	public double calvol() {
		return a*a*a;
	}
	
}
class sphere extends shape3d{
	private double r;
	public sphere (double r) {
		this.r=r;
	}
	@Override
	public double calarea() {
		return 4*3.14*r*r;
	}
	public double calvol() {
		return (4.0/3)*3.14*r*r*r;
	}
	
}


public class Program {
	
	public static void main(String[] args) {
		System.out.println("area of circle->");
		circle c=new circle(4);
		System.out.println(c.calarea());
		
		System.out.println("area of rectangle->");
		rectangle r=new rectangle(4,5);
		System.out.println(r.calarea());
		
		System.out.println("area of sphere->");
		sphere s=new sphere(4);
		System.out.println(s.calarea());
		
		System.out.println("vol of sphere->");
		sphere s1=new sphere(4);
		System.out.println(s1.calvol());
		
		System.out.println("area of cube->");
		cube c1=new cube(4);
		System.out.println(c1.calarea());
		
		System.out.println("vol of sphere->");
		cube c2=new cube(4);
		System.out.println(c2.calvol());
		
		
		
	}

}
