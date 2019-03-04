struct pairhash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> Q;
        Q.emplace(0, 1);
        int step = 0;
        unordered_set<pair<int, int>, pairhash> visited;
        visited.insert({ 0, 1 });
        while (!Q.empty()) {
            ++step;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                int position = Q.front().first;
                int speed = Q.front().second;
                Q.pop();
                int np1 = position + speed;
                if (np1 == target) {
                    return step;
                }
                int ns1 = speed * 2;
                Q.emplace(np1, ns1);
                
                int ns2 = speed > 0 ? -1 : 1;
                if (!visited.count({ position, ns2 })) {
                    Q.emplace(position, ns2);
                    visited.insert({ position, ns2 });
                }
            }
        }
        return -1;

    }
};

class Solution {
public:
    int racecar(int target) {
        memo = vector<int>(1 + target);
        return dfs(target);
    }
    
private:
    vector<int> memo;
    int dfs(int target) {
        if (memo[target] > 0) {
            return memo[target];
        }
        
        int n = floor(log2(target)) + 1;
        if (1 << n == target + 1) {
            memo[target] = n;
        }
        else {
            memo[target] = dfs((1 << n) - 1 - target) + n + 1;
            for (int m = 0; m < n - 1; ++m) {
                memo[target] = min(memo[target], dfs(target - (1 << (n - 1)) + (1 << m)) + n + m + 1);
            }                
        }
        return memo[target];
    }
};
