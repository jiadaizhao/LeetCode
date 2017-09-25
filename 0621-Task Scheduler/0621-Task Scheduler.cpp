class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> table(26);
        for (char c : tasks)
        {
            ++table[c - 'A'];
        }
        
        sort(table.begin(), table.end());
        int maxNum = table[25] - 1;
        int numIdle = maxNum * n;
        for (int i = 24; i >= 0 && table[i]; --i)
        {
            numIdle -= min(table[i], maxNum);
        }
        
        return (numIdle > 0) ? numIdle + m : m;
    }
};
