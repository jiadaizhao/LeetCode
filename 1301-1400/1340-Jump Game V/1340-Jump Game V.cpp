class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int maxJ = 0;
        vector<int> table(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            maxJ = max(maxJ, dfs(arr, i, d, table));
        }
        return maxJ;
    }
    
private:
    int dfs(vector<int>& arr, int curr, int d, vector<int>& table) {
        if (table[curr] == 0) {
            int currJump = 1;
            for (int next = curr - 1; next >= max(0, curr - d); --next) {
                if (arr[curr] > arr[next]) {
                    currJump = max(currJump, 1 + dfs(arr, next, d, table));
                }
                else {
                    break;
                }
            }
            
            for (int next = curr + 1; next <= min(int(arr.size()) - 1, curr + d); ++next) {
                if (arr[curr] > arr[next]) {
                    currJump = max(currJump, 1 + dfs(arr, next, d, table));
                }
                else {
                    break;
                }
            }
            table[curr] = currJump;
        }
        return table[curr];
    }
};
