package controllers;

import com.avaje.ebean.Model;

import models.Product;
import play.*;
import play.data.Form;
import play.mvc.*;

import views.html.*;

import java.util.List;
import static play.libs.Json.toJson;

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
}