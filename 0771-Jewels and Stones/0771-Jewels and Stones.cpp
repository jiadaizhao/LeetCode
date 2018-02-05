class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (char c : J) {
            jewels.insert(c);
        }
        int count = 0;
        for (char c : S) {
            if (jewels.count(c)) {
                ++count;
            }
        }
        return count;
    }
};
