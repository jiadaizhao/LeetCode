class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> table;
        for (int i : candies) {
            table.insert(i);
        }
        
        return min(table.size(), candies.size() / 2);
    }
};
