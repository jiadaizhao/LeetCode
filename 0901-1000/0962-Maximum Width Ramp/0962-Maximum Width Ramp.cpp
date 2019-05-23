class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> St;
        for (int i = A.size() -1; i >= 0; --i) {
            if (St.empty() || A[i] > A[St.top()]) {
                St.push(i);
            }
        }
        
        int maxWid = 0;
        for (int i = 0; i < A.size(); ++i) {
            while (!St.empty() && A[i] <= A[St.top()]) {
                maxWid = max(maxWid, St.top() - i);
                St.pop();
            }
        }
        return maxWid;
    }
};
