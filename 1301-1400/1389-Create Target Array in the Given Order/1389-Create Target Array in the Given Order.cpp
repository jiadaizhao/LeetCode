class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> powerValue(hi - lo + 1);
        for (int i = lo; i <= hi; ++i) {
            powerValue[i - lo] = {computeStep(i), i};
        }
        nth_element(powerValue.begin(), powerValue.begin() + k - 1, powerValue.end());
        return powerValue[k - 1].second;
    }
    
private:
    unordered_map<int, int> cache;
    int computeStep(int x) {
        if (!cache.count(x)) {
            int step = 0;
            while (x != 1) {
                if (x & 1) {
                    x = 3 * x + 1;
                }
                else {
                    x >>= 1;
                }
                ++step;
            }
            cache[x] = step;
        }
        return cache[x];
    }
};
