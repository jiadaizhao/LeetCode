class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels(J.begin(), J.end());
        int count = 0;
        for (char c : S) {
            if (jewels.count(c)) {
                ++count;
            }
        }
        return count;
    }
};
