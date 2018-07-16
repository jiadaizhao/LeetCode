class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(), minLen = n + 1;
        vector<int> presum(1 + n);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + A[i - 1];
        }
        
        deque<int> dq;
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && presum[i] - presum[dq.front()] >= K) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && presum[i] <= presum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return minLen <= n ? minLen : -1;
    }
};
