class Solution {
public:
    string simplifyPath(string path) {
        int start = 0;
        int index;
        vector<string> St;
        while ((index = path.find('/', start)) != string::npos)
        {
            string str = path.substr(start, index - start);
            if (str != "" && str != ".")
            {
                if (str == "..")
                {
                    if (!St.empty())
                    {
                        St.pop_back();
                    }
                }
                else
                {
                    St.push_back(str);
                }
            }
            start = index + 1;
        }
        
        string str = path.substr(start);
        if (str != "" && str != ".")
        {
            if (str == "..")
            {
                if (!St.empty())
                {
                    St.pop_back();
                }
            }
            else
            {
                St.push_back(str);
            }
        }
        
        
        if (St.empty())
        {
            return "/";
        }
        
        string result;
        for (string str : St)
        {
            result += "/" + str;
        }
        
        return result;
    }
};
