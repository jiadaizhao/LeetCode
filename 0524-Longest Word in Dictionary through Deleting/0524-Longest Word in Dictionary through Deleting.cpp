class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result;
        for (string str : d)
        {
            if (isSubstring(str, s) && (str.size() > result.size() || str.size() == result.size() && str < result))
            {
                result = str;
            }
        }
        
        return result;
    }
    
private:
    bool isSubstring(string& a, string& b)
    {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                ++i;
            }
            ++j;
        }
        
        return i == a.size();
    }
};
