class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int sum = 0, sneg = 0, neg = 0, absmin = INT_MAX;
        priority_queue<int> pq;
        for (int a : A) {
            absmin = min(absmin, abs(a));
            if (a >= 0) {
                sum += a;
            }
            else {
                pq.push(-a);
                ++neg;
                sneg += a;
            }
        }

        if (K < neg) {
            while (K--) {
                sum += pq.top();
                pq.pop();
            }

            while (!pq.empty()) {
                sum -= pq.top();
                pq.pop();
            }
        }
        else {
            sum -= sneg;
            if ((K - neg) & 1) {
                sum -= absmin * 2;
            }
        }

        return sum;
    }
};
