package com.product.entities;

import java.time.LocalDate;

import org.hibernate.annotations.CreationTimestamp;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.EnumType;
import jakarta.persistence.Enumerated;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

/* product id : Long (auto increment)
name : string (unique) : varchar(50)
product description : string : varchar(300)
manufacture date : LocalDate
price : Double
available quantity : Integer
category : enum (STATIONARY,SHOES,GRAINS,OIL...)*/

@NoArgsConstructor
@Getter
@Setter
@ToString
//JPA Annotations
@Entity
@Table(name="Products")
public class Product {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name="product_id")
	private Long productId;
	@Column(name="product_name", length = 50, unique = true)
	private String productName;
	@Column(name="product_description", length = 300)
	private String description;
	@Column(name="mfg_date")
	private LocalDate mfgDate;
	@Column
	private Double price;
	@Column(name="available_qty")
	private Integer qty;
	@Enumerated(EnumType.STRING)
	private Category category;
	
	public Product(String productName, String description, LocalDate mfgDate, Double price, Integer qty,
			Category category) {
		super();
		this.productName = productName;
		this.description = description;
		this.mfgDate = mfgDate;
		this.price = price;
		this.qty = qty;
		this.category = category;
	}
}

































