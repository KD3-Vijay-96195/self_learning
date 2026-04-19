package com.sunbeam;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.Scanner;

public class ShoppingCart {
	public static void main(String[] args) {
		
	Scanner sc=new Scanner(System.in);

	Map<Integer,String>prod=new HashMap<>();
	prod.put(1,"Mobile");
	prod.put(2,"Frdige");
	prod.put(3,"Laptop");
	prod.put(4,"Buds");
	
	List<String>ohis=new ArrayList<>();

	int choice=-1;
	while(choice!=0)
	{
		System.out.println("0.exit");
		System.out.println("1.Display Prod:");
		System.out.println("2.Add Prod:");
		System.out.println("3.Display order his:");
        
		choice=sc.nextInt();	
        
        
        
        switch(choice)
        {
        case 1:
        	for(Map.Entry<Integer, String>entry:prod.entrySet()) {
        		System.out.println(entry.getKey()+"="+entry.getValue());
        	}
        	break;
        case 2:
        	System.out.println("Enter Prod id:");
        	int id=sc.nextInt();
        	if(prod.containsKey(id)) {
        		ohis.add(prod.get(id));
        		System.out.println("Prod Added");
        	}
        	else {
        		System.out.println("Invalid prod id");
        	}
        case 3:
        	for(String item:ohis) {
        	System.out.println(item);
        	}
        
          
        }
	}
	
	}
}
