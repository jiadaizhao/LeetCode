class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int island = 0;
        for (auto stone : stones) {
            int pr = findParent(stone[0], island);
            int pc = findParent(~stone[1], island);
            if (pr != pc) {
                parent[pr] = pc;
                --island;
            }
        }

        return stones.size() - island;
    }
    
private:
    unordered_map<int, int> parent;
    int findParent(int x, int& island) {
        if (!parent.count(x)) {
            parent[x] = x;
            ++island;
        }
        else {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }            
        }
        return x;
    }
};
