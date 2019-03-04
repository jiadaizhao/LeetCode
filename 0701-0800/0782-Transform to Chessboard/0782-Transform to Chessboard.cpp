class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size();
        unordered_map<int, int> count;
        for (auto row : board) {
            int code = 0;
            for (int r : row) {
                code = code * 2 + r;
            }
            ++count[code];
        }
        
        int k1 = analyzeCount(count, N);
        if (k1 == -1) return -1;
        
        count.clear();
        for (int c = 0; c < N; ++c) {
            int code = 0;
            for (int r = 0; r < N; ++r) {
                code = code * 2 + board[r][c];
            }
            ++count[code];
        }
        int k2 = analyzeCount(count, N);
        return k2 != -1 ? k1 + k2 : -1;
    }
    
private:
    int analyzeCount(unordered_map<int, int>& count, int N) {
        if (count.size() != 2) return -1;
        auto it1 = count.begin(), it2 = ++count.begin();
        if (!(it1->second == N / 2 && it2->second == (N + 1) / 2) &&
            !(it2->second == N / 2 && it1->second == (N + 1) / 2)) {
            return -1;
        }
        int k1 = it1->first, k2 = it2->first;
        int allOnes = (1 << N) - 1;
        int ones = bitCount(k1 & allOnes);
        int cand = INT_MAX;
        if (N % 2 == 0 || ones * 2 < N) // zero start
            cand = min(cand, bitCount(k1 ^ 0xAAAAAAAA & allOnes) / 2);
        if (N % 2 == 0 || ones * 2 > N) // ones start
            cand = min(cand, bitCount(k1 ^ 0x55555555 & allOnes) / 2);
        return cand;
    }
    
    int bitCount(int num) {
        int count = 0;
        while (num) {
            ++count;
            num &= num - 1;
        }
        return count;
    }
};

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) return -1;
        for (int i = 0; i < N; ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowSwap += board[i][0] == i % 2;
            colSwap += board[0][i] == i % 2;
        }
        if (rowSum != N / 2 + N % 2 && rowSum != N / 2) return -1;
        if (colSum != N / 2 + N % 2 && colSum != N / 2) return -1;
        if (N % 2) {
            if (colSwap % 2) colSwap = N - colSwap;
            if (rowSwap % 2) rowSwap = N - rowSwap;
        }
        else {
            colSwap = min(N - colSwap, colSwap);
            rowSwap = min(N - rowSwap, rowSwap);
        }
        return (colSwap + rowSwap) / 2;
    }
};
