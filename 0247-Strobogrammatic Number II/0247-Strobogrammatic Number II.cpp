class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        if (n <= 0)
        {
            return result;
        }
        
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
        
        return result;
    }
};
