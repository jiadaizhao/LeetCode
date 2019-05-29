class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {        
        for (int a : A) {
            ++table[a];
        }       
        
        for (auto p : table) {
            for (auto q : table) {
                int temp = sqrt(p.first + q.first);
                if (temp * temp == p.first + q.first) {
                    nextNum[p.first].push_back(q.first);
                }
            }
        }
        
        int count = 0;
        for (auto p : table) {
            dfs(p.first, A.size() - 1, count);
        }
        return count;
    }
    
private:
    unordered_map<int, int> table;
    unordered_map<int, vector<int>> nextNum;
    void dfs(int x, int left, int& count) {
        if (left == 0) {
            ++count;
        }
        else {
            --table[x];
            for (int y : nextNum[x]) {
                if (table[y] > 0) {
                    dfs(y, left - 1, count);
                }
            }
            ++table[x];
        }
    }
};
