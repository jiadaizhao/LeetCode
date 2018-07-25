class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        sort(A.begin(), A.end());
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(B[i], i);
        }
        vector<int> result(n);
        int lo = 0, hi = n - 1;
        while (!pq.empty()) {
            int val = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if (A[hi] > val) {
                result[index] = A[hi--];
            }
            else {
                result[index] = A[lo++];
            }
        }
        return result;
    }
};
