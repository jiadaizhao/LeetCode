const int maxn = 100;
int dp[maxn][maxn][maxn];

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        if (n == 0)
        {
            return 0;
        }
        
        memset(dp, 0, sizeof(dp));

        return dfs(boxes, dp, 0, n - 1, 0);
    }

private:
    int dfs(vector<int>& boxes, int dp[][maxn][maxn], int i, int j, int k) {
        if (i > j)
        {
            return 0;
        }
        
        if (dp[i][j][k])
        {
            return dp[i][j][k];
        }        

        while (i < j && boxes[i] == boxes[i + 1])
        {
            ++i;
            ++k;
        }

        int maxVal = dfs(boxes, dp, i + 1, j, 0) + (k + 1) * (k + 1);
        for (int m = i + 2; m <= j; ++m)
        {
            if (boxes[i] == boxes[m])
            {
                maxVal = max(maxVal, dfs(boxes, dp, i + 1, m - 1, 0) + dfs(boxes, dp, m, j, k + 1));
            }
        }
        return dp[i][j][k] = maxVal;
    }
};
