#include <iostream>
#include <string>
#include <vector>

class Cart {
private:
    const std::string cartId;
    std::vector<double> prices;
    int maxItems;

public:
    Cart(const std::string& id, int max_items) : cartId(id), maxItems(max_items) {}

    void addItem(double price) {
        if (prices.size() < maxItems) {
            prices.push_back(price);
        }
    }

    double getTotal() const {
        double total = 0.0;
        for (double price : prices) {
            total += price;
        }
        return total;
    }

    int getItemCount() const {
        return prices.size();
    }
};

// Usage Example
void testShoppingCart() {
    Cart cart("CART-5", 20);
    cart.addItem(250);
    cart.addItem(99);
    cart.addItem(151);
    
    std::cout << "Total: " << cart.getTotal() << "\n"; // 500
    std::cout << "Items: " << cart.getItemCount() << "\n"; // 3
}