package models;

import com.avaje.ebean.Model;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class Product extends Model {
	@Id
	public Long id;

	public String name;
	public Long categoryid;
	public float price;

	public static Finder<Long,Product> find = new Finder<Long,Product>(
		Long.class, Product.class
	);
}