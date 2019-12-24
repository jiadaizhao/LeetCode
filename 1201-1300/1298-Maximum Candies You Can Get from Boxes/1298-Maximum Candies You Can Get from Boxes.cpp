class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> Q;
        unordered_set<int> possible;
        for (int box : initialBoxes) {
            if (status[box] == 1) {
                Q.push(box);
            }
            else {
                possible.insert(box);
            }
        }
        
        int num = 0;
        while (!Q.empty()) {
            int box = Q.front();
            Q.pop();
            num += candies[box];
            for (int key : keys[box]) {
                status[key] = 1;
                if (possible.count(key)) {
                    possible.erase(key);
                    Q.push(key);
                }
            }
            
            for (int cb : containedBoxes[box]) {
                if (status[cb] == 1) {
                    Q.push(cb);
                }
                else {
                    possible.insert(cb);
                }
            }
        }
        
        return num;
    }
};
