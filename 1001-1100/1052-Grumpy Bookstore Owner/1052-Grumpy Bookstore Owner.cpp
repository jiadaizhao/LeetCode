class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int satisfied = 0, make_satisfied = 0, max_make_satisfied = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i]) {
                make_satisfied += customers[i];
            }
            else {
                satisfied += customers[i];
            }
            if (i >= X && grumpy[i - X]) {
                make_satisfied -= customers[i - X];
            }
            
            max_make_satisfied = max(max_make_satisfied, make_satisfied);
        }
        
        return satisfied + max_make_satisfied;
    }
};
