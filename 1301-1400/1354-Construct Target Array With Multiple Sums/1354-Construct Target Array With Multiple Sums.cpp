class Solution {
public:
    bool isPossible(vector<int>& target) {
        long total = accumulate(target.begin(), target.end(), (long)0);
        priority_queue<int> pq(target.begin(), target.end());
        while (true) {
            int a = pq.top();
            pq.pop();
            total -= a;
            if (a == 1 || total == 1) {
                return true;
            }
            if (total == 0 || a <= total || a % total == 0) {
                return false;
            }
            a %= total;
            total += a;
            pq.push(a);
        }
    }
};
