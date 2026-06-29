package com.product.tester;

import java.time.LocalDate;

import java.util.Scanner;

import org.hibernate.SessionFactory;

import com.product.dao.ProductDao;
import com.product.dao.ProductDaoImpl;
import com.product.entities.Category;
import com.product.entities.Product;
import com.product.utils.HibernateUtils;

public class AddNewProduct {
	
	public static void main(String[] args) {
		try(SessionFactory sf = HibernateUtils.getSessionFactory();
				Scanner sc = new Scanner(System.in)){
			ProductDao productDao = new ProductDaoImpl();
			
			System.out.println(
					"Enter product details - name, description, mfg-date, price, qty, category"
					);
			Product product = new Product(sc.next(), sc.next(), LocalDate.parse(sc.next()), sc.nextDouble(), sc.nextInt(), Category.valueOf(sc.next()));
			System.out.println("Addition status - "+productDao.addNewProduct(product));
		}
					
				
	}
}
