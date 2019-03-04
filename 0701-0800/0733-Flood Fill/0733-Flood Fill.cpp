class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        if (image[sr][sc] == newColor) {
            return image;
        }
        queue<pair<int, int>> Q;
        int orig = image[sr][sc];
        Q.emplace(sr, sc);
        image[sr][sc] = newColor;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty()) {
            int r = Q.front().first;
            int c = Q.front().second;
            Q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == orig) {
                    Q.emplace(nr, nc);
                    image[nr][nc] = newColor;
                }
            }
        }

        return image;
    }
};
