class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return "";
        }
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        sort(strs.begin(), strs.end(), cmp());
        if (strs[0] == "0") {
            return "0";
        }
        string result;
        for (string s : strs) {
            result += s;
        }
        
        return result;
    }

private:
    struct cmp {
        bool operator() (string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        }  
    };
};
