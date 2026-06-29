package com.product.dao;

import org.hibernate.Session;
import org.hibernate.Transaction;

import com.product.entities.Product;
import com.product.utils.HibernateUtils;





public class ProductDaoImpl implements ProductDao {

	@Override
	public String addNewProduct(Product newProduct) {
		String message="Product addition failed";
		
		//get session from session factory
		Session session = HibernateUtils.getSessionFactory().getCurrentSession();
		//begin transaction
		Transaction tx=session.beginTransaction();
		try {
			session.persist(newProduct);
			tx.commit();
			message="Product Added successfully with ID "+newProduct.getProductId();
		}catch(RuntimeException e) {
			if(tx != null) {
				tx.rollback();
			}
			throw e;
		}
		return message;
	}

}
