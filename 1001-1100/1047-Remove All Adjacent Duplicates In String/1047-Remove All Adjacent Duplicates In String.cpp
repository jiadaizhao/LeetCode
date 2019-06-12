class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        for (char c : S) {
            if (result.size() && c == result.back()) {
                result.pop_back();
            }
            else {
                result += c;
            }
        }

        return result;
    }
};
