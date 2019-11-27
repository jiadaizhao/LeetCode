class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());
        string curr;
        auto it = products.begin();
        for (char c : searchWord) {
            curr += c;
            vector<string> suggested;
            it = lower_bound(it, products.end(), curr);
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                string s = *(it + i);
                if (s.find(curr) != 0) {
                    break;
                }
                suggested.push_back(s);
            }
            result.push_back(suggested);
        }
        
        return result;
    }
};
