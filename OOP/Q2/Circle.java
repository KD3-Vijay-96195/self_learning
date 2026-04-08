package com.domain;

import com.sunbeam.AdapterClass;
import com.sunbeam.Shape;

public class Circle extends AdapterClass
{
	private double radius;
	
	public Circle()
	{
		
	}
	public Circle(double radius)
	{
		this.radius = radius; 
	}
	public void setRadius(double radius)
	{
		this.radius = radius;
	}
	
	@Override
	public double area()
	{
		double area =  this.radius*this.radius*PI;
		return area;
	}

}
