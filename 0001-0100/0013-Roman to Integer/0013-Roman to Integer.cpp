class Solution {
public:
    int romanToInt(string s) {
        int result = 0, prev = 1000;
        unordered_map<char, int> romanMap{{'I', 1}, {'V', 5}, {'X', 10}, 
                                          {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (char c : s) {
            int curr = romanMap[c];
            if (curr > prev) {
                result += curr - 2 * prev;
            }
            else {
                result += curr;
            }
            prev = curr;
        }
        
        return result;
    }
};
