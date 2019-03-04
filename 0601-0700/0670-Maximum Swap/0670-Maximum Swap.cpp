class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int> last(10);
        for (int i = 0; i < n; ++i) {
            last[str[i] - '0'] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > str[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(str[i], str[last[d]]);
                    return stoi(str);
                }
            }
        }
        
        return num;
    }
};
