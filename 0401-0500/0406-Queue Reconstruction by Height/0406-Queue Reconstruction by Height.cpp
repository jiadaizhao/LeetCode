class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp());
        vector<vector<int>> result;
        for (auto& p : people) {
            result.insert(result.begin() + p[1], p);
        }
        
        return result;
    }

    private:
    struct cmp {
        bool operator() (vector<int>& p1, vector<int>& p2) {
            if (p1[0] == p2[0]) {
                return p1[1] < p2[1];
            }
            else {
                return p1[0] > p2[0];
            }
        }
    };
};
