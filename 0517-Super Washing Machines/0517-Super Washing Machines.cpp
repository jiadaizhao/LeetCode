class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % n)
        {
            return -1;
        }
        
        int avg = sum / n;
        int count = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i)
        {
            int diff = machines[i] - avg;
            curr += diff;
            count = max(count, max(abs(curr), diff));
        }
        
        return count;
    }
};
