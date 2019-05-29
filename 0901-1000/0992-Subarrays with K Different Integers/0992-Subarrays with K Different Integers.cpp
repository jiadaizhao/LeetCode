class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    
private:
    int atMostK(vector<int>& A, int k) {
        vector<int> table(1 + A.size());
        int num = 0, count = 0, start = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (table[A[i]]++ == 0) {
                ++num;
            }
            while (num > k) {
                if (--table[A[start++]] == 0) {
                    --num;
                }
            }
            count += i - start + 1;
        }
        return count;
    }
};
