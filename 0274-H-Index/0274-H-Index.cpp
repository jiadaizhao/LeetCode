class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int result = 0;
        for (int i = citations.size() - 1; i >= 0; --i) {
            if (citations[i] >= i + 1) {
                result = i + 1;
                break;
            }
        }
        
        return result;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(1 + n);
        for (int c : citations) {
            ++count[min(n, c)];
        }
        
        int h = n;
        for (int i = count[n]; i < h; i += count[h]) {
            --h;
        }
        return h;
    }
};
