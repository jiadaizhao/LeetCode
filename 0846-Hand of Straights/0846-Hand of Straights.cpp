class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W) {
            return false;
        }
        map<int, int> freq;
        for (int i : hand) {
            ++freq[i];
        }
        int prev = -1, open = 0;
        queue<int> start;
        for (auto it : freq) {
            int curr = it.first;
            int count = it.second;
            if (open > 0 && curr > prev + 1 || open > count) {
                return false;
            }
            start.push(count - open);
            open = count;
            
            if (start.size() == W) {
                open -= start.front();
                start.pop();
            }
            prev = curr;
        }
        return open == 0;
        
    }
};
