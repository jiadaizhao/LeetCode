class ProductOfNumbers {
public:
    ProductOfNumbers() {
        product = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            product = {1};
        }
        else {
            product.push_back(product.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= product.size()) {
            return 0;
        }
        else {
            return product.back() / product[product.size() - k - 1];
        }
    }
    
private:
    vector<int> product;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
