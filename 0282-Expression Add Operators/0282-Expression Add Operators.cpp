class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        long currVal;
        for (int i = 1; i <= num.size(); ++i)
        {
            string path = num.substr(0, i);
            currVal = stol(path);
            if (path != to_string(currVal))
            {
                break;
            }
            dfs(num, i, currVal, currVal, ' ', path, target, result);
        }
        
        return result;
    }
    
private:
    void dfs(string num, int start, long preVal, long currVal, char preOp, string path, int target, vector<string>& result)
    {
        if (start == num.size())
        {
            if (currVal == target)
            {
                result.push_back(path);
            }
            return;
        }
        
        for (int i = start; i < num.size(); ++i)
        {
            string temp = num.substr(start, i - start + 1);
            long cv = stol(temp);
            if (temp != to_string(cv))
            {
                break;
            }
            dfs(num, i + 1, cv, currVal + cv, '+', path + '+' + temp, target, result);
            dfs(num, i + 1, cv, currVal - cv, '-', path + '-' + temp, target, result);
            long val;
            if (preOp == '+')
            {
                val = currVal - preVal + preVal * cv;
            }
            else if (preOp == '-')
            {
                val = currVal + preVal - preVal * cv;
            }
            else
            {
                val = currVal * cv;
            }
            dfs(num, i + 1, preVal * cv, val, preOp, path + '*' + temp, target, result);
        }
    }
};
