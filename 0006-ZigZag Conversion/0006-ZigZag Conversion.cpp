class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> str(numRows);
        int T = numRows * 2 - 2;
        for (int i = 0; i < s.size(); ++i)
        {            
            int index = i % T;
            if (index < numRows)
            {
                str[index].push_back(s[i]);
            }
            else
            {
                str[T - index].push_back(s[i]);
            }
        }
        
        string result;
        for (string st : str)
        {
            result += st;
        }
        
        return result;
    }
};
