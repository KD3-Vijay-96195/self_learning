package com.domain;

import com.sunbeam.AdapterClass;

public class Sphere extends AdapterClass
{
	private double radius;
	
	public Sphere()
	{
		
	}
	public Sphere(double radius)
	{
		this.radius = radius;
	}
	public double getRadius() {
		return radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	@Override
	public String toString() {
		return "Sphere [radius=" + radius + "]";
	}
	
	@Override
	public double volume()
	{
		double volume = PI*radius*radius*radius;
		return volume;
	}

}
