class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        visited.insert(n);
        while (n != 1)
        {
            int temp = n;
            int curr = 0;
            while (temp)
            {
                int i = temp % 10;
                curr += i * i;
                temp /= 10;
            }
            if (visited.find(curr) != visited.end())
            {
                return false;
            }
            visited.insert(curr);
            n = curr;
        }
        
        return true;
    }
};
