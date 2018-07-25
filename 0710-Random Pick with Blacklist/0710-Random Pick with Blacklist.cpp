class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        wlen = N - blacklist.size();
        for (int b : blacklist) {
            table[b] = -1;
        }
        
        int mapped = N - 1;
        for (int b : blacklist) {
            if (b < wlen) {
                while (table.count(mapped)) {
                    --mapped;
                }
                table[b] = mapped--;
            }
        }
    }
    
    int pick() {
        int index = rand() % wlen;
        return table.count(index) ? table[index] : index;
    }
    
private:
    unordered_map<int, int> table;
    int wlen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
