package controllers;

import com.avaje.ebean.Model;
import com.avaje.ebean.Ebean;
import com.avaje.ebean.SqlUpdate;

import models.Product;
import play.*;
import play.data.Form;
import play.mvc.*;

import views.html.*;

import java.util.List;
import play.libs.Json;
import static play.libs.Json.toJson;
import play.twirl.api.Content;

public class HomeController extends Controller {

	public Result index() {
		return ok(index.render("Your new application is ready."));
	}

	public Result addProduct() {
		Product product = Form.form(Product.class).bindFromRequest().get();
		product.save();
		return redirect(routes.HomeController.index());
	}

	public Result getProducts() {
		List<Product> products = new Model.Finder(String.class, Product.class).all();
		return ok(toJson(products));
	}

	public Result deleteProduct(String name) {
        Product product = Form.form(Product.class).bindFromRequest().get();
		SqlUpdate down = Ebean.createSqlUpdate("DELETE FROM product WHERE name = :param1 OR id = :param2");
		down.setParameter("param1", product.name);
		down.setParameter("param2", product.id);
		down.execute();
		return ok();
	}

	public Result updateProduct(String id) {
        Product product = Form.form(Product.class).bindFromRequest().get();
		String sql = "UPDATE product SET name = :name, price = :price  WHERE id = :edit";
		SqlUpdate update = Ebean.createSqlUpdate(sql);
		update.setParameter("name", product.name);
		update.setParameter("price", product.price);
		update.setParameter("edit", product.id);
		update.execute();
		return ok();
	}
}