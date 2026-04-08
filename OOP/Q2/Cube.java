package com.domain;

import com.sunbeam.AdapterClass;

public class Cube extends AdapterClass
{
	private int side;
	
	public Cube()
	{
		
	}
	public Cube(int side)
	{
		this.side = side;
	}
	public int getSide() {
		return side;
	}
	public void setSide(int side) {
		this.side = side;
	}
	@Override
	public String toString() {
		return "Cube [side=" + side + "]";
	}
	
	@Override
	public double volume()
	{
		double volume = side*side*side;
		return volume;
	}
	

}
