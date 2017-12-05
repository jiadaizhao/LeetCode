// Memoization
class Solution {
public:
    int integerReplacement(int n) {
        table[1] = 0;
        return helper(n);
    }
    
private:
    unordered_map<int, int> table;
    int helper(long n) {
        if (table.find(n) != table.end()) {
            return table[n];
        }
        
        if (n % 2 == 0) {
            return table[n] = 1 + helper(n / 2);
        }
        else {
            return table[n] = 1 + min(helper(n - 1), helper(n + 1));
        }
    }
};

// Greedy
class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) {
            return 32;
        }
        
        int count = 0;
        while (n != 1) {
            ++count;
            if (n % 2 == 0) {
                n /= 2;
            }
            else if (n == 3) {
                --n;
            }
            else if (n & 2) {
                ++n;
            }
            else {
                --n;
            }
        }
        
        return count;
    }
};
