class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> num;
        int temp = N + 1;
        while (temp) {
            num.push_back(temp % 10);
            temp /= 10;
        }
        reverse(num.begin(), num.end());
        
        int total = 0;
        for (int i = 1; i < num.size(); ++i) {
            total += 9 * perm(9, i - 1);
        }
        
        unordered_set<int> visited;
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i ? 0 : 1; j < num[i]; ++j) {
                if (!visited.count(j)) {
                    total += perm(9 - i, num.size() - i - 1);
                }
            }
            
            if (!visited.insert(num[i]).second) {
                break;
            }
        }
        
        return N - total;
    }
    
private:
    int perm(int m, int n) {
        int result = 1, curr = m;
        while (curr >= m - n + 1) {
            result *= curr--;
        }
        return result;
    }
};
