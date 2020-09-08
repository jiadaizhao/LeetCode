class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sum = 0, n = s.size();
        for (auto& v : shift) {
            if (v[0] == 0) {
                sum += v[1];
            }
            else {
                sum -= v[1];
            }
        }
        
        sum %= n;
        if (sum < 0) {
            sum += n;
        }
        
        return s.substr(sum) + s.substr(0, sum);
    }
};
