$ ->
	$.get "/products", (products) ->
		$.each products, (index, product) ->
			$('#products').append $("<li>").text "ID:" + product.id + " NAME:" + product.name + " PRICE:" + product.price