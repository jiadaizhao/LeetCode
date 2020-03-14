class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for (int i = 0; i < products.size(); ++i) {
            priceTable[products[i]] = prices[i];
        }
        curr = 0;
        target = n;
        this->discount = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double total = 0;
        for (int i = 0; i < product.size(); ++i) {
            total += priceTable[product[i]] * amount[i];
        }
        if (++curr == target) {
            curr = 0;
            total *= 1 - (double)discount / 100;
        }
        return total;
    }
    
private:
    unordered_map<int, int> priceTable;
    int curr, target, discount;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
