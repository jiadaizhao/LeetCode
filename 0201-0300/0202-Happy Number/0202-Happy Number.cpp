class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        visited.insert(n);
        while (n != 1) {
            int temp = n;
            n = 0;
            while (temp) {
                int i = temp % 10;
                n += i * i;
                temp /= 10;
            }
            if (visited.count(n)) {
                return false;
            }
            visited.insert(n);
        }
        
        return true;
    }
};
