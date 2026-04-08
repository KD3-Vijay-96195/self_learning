package com.domain;

import com.sunbeam.AdapterClass;

public class Rectangle extends AdapterClass 
{
	private int length;
	private int breadth;
	
	public Rectangle()
	{
		
	}
	public Rectangle(int length, int breadth) {
		super();
		this.length = length;
		this.breadth = breadth;
	}
	public int getLength() {
		return length;
	}
	public void setLength(int length) {
		this.length = length;
	}
	public int getBreadth() {
		return breadth;
	}
	public void setBreadth(int breadth) {
		this.breadth = breadth;
	}
	@Override
	public String toString() {
		return "Rectangle [length=" + length + ", breadth=" + breadth + "]";
	}
	
	@Override
	public double area()
	{
		double area = length * breadth;
		return area;
	}

}
