class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> St;
        for (int i = n - 1; i >= 0; --i) {
            while (!St.empty() && temperatures[St.top()] <= temperatures[i]) {
                St.pop();
            }
            if (!St.empty()) {
                result[i] = St.top() - i;
            }
            St.push(i);            
        }
        
        return result;
    }
};
