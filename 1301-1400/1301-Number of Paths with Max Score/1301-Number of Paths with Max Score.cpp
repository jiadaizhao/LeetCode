class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        vector<int> maxSum1(n), count1(n);
        count1[n - 1] = 1;
        for (int j = n - 2; j >= 0; --j) {
            if (board[n - 1][j] == 'X') {
                break;
            }
            else {
                maxSum1[j] = maxSum1[j + 1] + board[n - 1][j] - '0';
                count1[j] = 1;
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            vector<int> maxSum2(n), count2(n);
            if (count1[n - 1] > 0 && board[i][n - 1] != 'X') {
                maxSum2[n - 1] = maxSum1[n - 1] + board[i][n - 1] - '0';
                count2[n - 1] = 1;
            }
            for (int j = n - 2; j >= 0; --j) {
                if (board[i][j] != 'X' && (count2[j + 1] || count1[j] || count1[j + 1])) {
                    maxSum2[j] = maxSum2[j + 1];
                    count2[j] = count2[j + 1];
                    if (maxSum1[j] > maxSum2[j]) {
                        maxSum2[j] = maxSum1[j];
                        count2[j] = count1[j];
                    }
                    else if (maxSum1[j] == maxSum2[j])
                        count2[j] = (count2[j] + count1[j]) % MOD;

                    if (maxSum1[j + 1] > maxSum2[j]) {
                        maxSum2[j] = maxSum1[j + 1];
                        count2[j] = count1[j + 1];
                    }
                    else if (maxSum1[j + 1] == maxSum2[j])
                        count2[j] = (count2[j] + count1[j + 1]) % MOD;
                                
                    if (board[i][j] != 'E')
                        maxSum2[j] += board[i][j] - '0';
                }
            }
            
            maxSum1 = move(maxSum2);
            count1 = move(count2);
        }
            
        return {maxSum1[0], count1[0]};
    }
};
