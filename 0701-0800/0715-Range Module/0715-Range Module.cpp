class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto l = table.lower_bound(left), r = table.upper_bound(right);
        if (l != table.begin()) {
            --l;
            if (l->second < left) {
                ++l;
            }
        }
        
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            table.erase(l, ++r);
        }
        table[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = table.upper_bound(left);
        if (it == table.begin() || (--it)->second < right) {
            return false;
        }
        return true;        
    }
    
    void removeRange(int left, int right) {
        auto l = table.lower_bound(left), r = table.upper_bound(right);
        if (l != table.begin()) {
            --l;
            if (l->second <= left) {
                ++l;
            }
        }
        
        if (l != r) {
            int ll = min(left, l->first);
            int rr = max(right, (--r)->second);
            table.erase(l, ++r);
            if (ll < left) {
                table[ll] = left;
            }
            if (rr > right) {
                table[right] = rr;
            }            
        }
    }
    
private:
    map<int, int> table;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
