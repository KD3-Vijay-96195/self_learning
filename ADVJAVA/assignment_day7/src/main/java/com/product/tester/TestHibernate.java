package com.product.tester;

import org.hibernate.SessionFactory;

import com.product.utils.HibernateUtils;

public class TestHibernate {
	public static void main(String[] args) {
		try(SessionFactory sf = HibernateUtils.getSessionFactory()){
			System.out.println("Hibernate up and running......");
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
