class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> candidates;
        for (auto r : restaurants) {
            if ((veganFriendly == 0 || r[2] == 1) && r[3] <= maxPrice && r[4] <= maxDistance) {
                candidates.emplace_back(r[1], r[0]);
            }
        }
        sort(candidates.begin(), candidates.end(), greater<pair<int, int>>());
        vector<int> result(candidates.size());
        for (int i = 0; i < candidates.size(); ++i) {
            result[i] = candidates[i].second;
        }
        return result;
    }
};
