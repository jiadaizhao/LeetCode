class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return "";
        }
        vector<string> strs;
        bool allZero = true;
        for (int num : nums)
        {
            if (num)
            {
                allZero = false;
            }
            strs.push_back(to_string(num));
        }
        
        if (allZero)
        {
            return "0";
        }
        
        sort(strs.begin(), strs.end(), cmp());
        string result;
        for (string s : strs)
        {
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
