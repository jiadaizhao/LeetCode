class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        for (int i = low.size(); i <= high.size(); ++i)
        {
            findStrobogrammatic(i, low, high, count);
        }
        
        return count;
    }
    
private:
    void findStrobogrammatic(int n, string low, string high, int& count) {
        vector<string> result;
        if (n % 2)
        {
            --n;
            result = {"0", "1", "8"};
        }
        else
        {
            result = {""};
        }
        
        while (n)
        {
            vector<string> temp;
            for (string s : result)
            {
                if (n != 2)
                {
                    temp.push_back("0" + s + "0");
                }
                temp.push_back("1" + s + "1");                
                temp.push_back("6" + s + "9");
                temp.push_back("8" + s + "8");
                temp.push_back("9" + s + "6");
            }
            
            n -= 2;
            result = temp;
        }
        
        for (string s : result)
        {
            if (cmp(low, s) && cmp(s, high))
            {
                ++count;
            }
        }
    }
    
    bool cmp(string& s1, string& s2) {
        if (s1.size() == s2.size())
        {
            for (int i = 0; i < s1.size(); ++i)
            {
                if (s1[i] < s2[i])
                {
                    return true;
                }
                else if (s1[i] > s2[i])
                {
                    return false;
                }
            }
            
            return true;
        }
        else
        {
            return s1.size() < s2.size();
        }
    }
};
