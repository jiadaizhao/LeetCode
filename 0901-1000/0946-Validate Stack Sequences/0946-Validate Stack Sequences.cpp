class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> St;
        int j = 0;
        for (int i : pushed) {
            St.push(i);
            while (!St.empty() && St.top() == popped[j]) {
                St.pop();
                ++j;
            }
        }
        return St.empty();
    }
};
