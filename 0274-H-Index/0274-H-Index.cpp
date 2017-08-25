class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int result = 0;
        for (int i = citations.size() - 1; i >= 0; --i)
        {
            if (citations[i] >= i + 1)
            {
                result = i + 1;
                break;
            }
        }
        
        return result;
    }
};
