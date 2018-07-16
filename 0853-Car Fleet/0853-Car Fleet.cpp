class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> table;
        for (int i = 0; i < position.size(); ++i) {
            table[target - position[i]] = (target - position[i]) * 1.0 / speed[i];
        }
        int count = 0;
        double t = 0;
        for (auto p : table) {            
            if (p.second > t) {
                ++count;
                t = p.second;
            }
        }
        return count;
    }
};
