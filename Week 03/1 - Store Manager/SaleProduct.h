#pragma once

class SaleProduct {
private:
	int productId;
	int quantity;
public:
	SaleProduct(int productId, int quantity) {
		this->productId = productId;
		this->quantity = quantity;
	}

	~SaleProduct() { }

	int getProductId() {
		return this->productId;
	}

	int getQuantity() {
		return this->quantity;
	}
};