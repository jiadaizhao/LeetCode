class Solution {
public:
    int countArrangement(int N) {
        vector<int> used(N);
        int count = 0;
        dfs(used, 1, N, count);
        return count;
    }
    
private:
    void dfs(vector<int>& used, int start, int N, int& count) {
        if (start == N + 1) {
            ++count;
            return;
        }
        
        for (int i = 1; i <= N; ++i) {
            if (!used[i - 1] && (i % start == 0 || start % i == 0)) {
                used[i - 1] = 1;
                dfs(used, start + 1, N, count);
                used[i - 1] = 0;
            }
        }
    }
};

// Search from back and get better performance
class Solution {
public:
    int countArrangement(int N) {
        vector<int> used(N);
        int count = 0;
        dfs(used, N, N, count);
        return count;
    }
    
private:
    void dfs(vector<int>& used, int start, int N, int& count) {
        if (start == 0) {
            ++count;
            return;
        }
        
        for (int i = N; i >= 1; --i) {
            if (!used[i - 1] && (i % start == 0 || start % i == 0)) {
                used[i - 1] = 1;
                dfs(used, start - 1, N, count);
                used[i - 1] = 0;
            }
        }
    }
};
