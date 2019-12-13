class Solution {
public:
    int confusingNumberII(int N) {
        table[0] = 0;
        table[1] = 1;
        table[6] = 9;
        table[8] = 8;
        table[9] = 6;
        keys = {0, 1, 6, 8, 9};
        int count = 0;
        dfs(0, 0, 1, N, count);
        return count;
    }
    
private:
    unordered_map<int, int> table;
    vector<int> keys;
    void dfs(long num, long rotation, long base, int N, int& count) {
        if (num != rotation) {
            ++count;
        }
        
        for (int d : keys) {
            if (num == 0 && d == 0) {
                continue;
            }
            if (num * 10 + d > N) {
                break;
            }
            dfs(num * 10 + d, table[d] * base + rotation, base * 10, N, count);
        }
    }
};
