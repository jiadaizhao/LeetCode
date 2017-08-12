class Solution {
public:
    string countAndSay(int n) {
        string result = "";
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1)
            {
                result = "1";
            }
            else
            {
                char prev = result[0];
                int count = 1;
                string temp = "";
                for (int j = 1; j < result.size(); ++j)
                {
                    if (result[j] != prev)
                    {
                        temp += to_string(count);
                        temp += prev;
                        count = 1;
                        prev = result[j];
                    }
                    else
                    {
                        ++count;
                    }
                }
                
                temp += to_string(count);
                temp += prev;
                
                result = temp;
            }
        }
        
        return result;
    }
};
