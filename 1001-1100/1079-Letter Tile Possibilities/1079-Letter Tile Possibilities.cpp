class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size());
        return dfs(tiles, used);
    }

private:
    int dfs(string& tiles, vector<bool>& used) {
        int total = 0;
        for (int i = 0; i < tiles.size(); ++i) {
            if (used[i]) {
                continue;
            }

            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) {
                continue;
            }

            ++total;
            used[i] = true;
            total += dfs(tiles, used);
            used[i] = false;
        }

        return total;
    }
};
