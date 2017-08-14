class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int num = 1 << n;
        for (int i = 0; i < num; ++i)
        {
            result.push_back(i ^ (i / 2));
        }
        
        return result;
    }
};
