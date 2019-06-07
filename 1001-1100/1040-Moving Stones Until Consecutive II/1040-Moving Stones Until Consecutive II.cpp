class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int maxMove = max(stones[stones.size() - 2] + 2 - stones[0] - stones.size(),
                          stones.back() + 2 - stones[1] - stones.size());

        int minMove = stones.size();
        int start = 0;
        for (int i = 0; i < stones.size(); ++i) {
            while (stones[i] - stones[start] >= stones.size()) {
                ++start;
            }

            if (i - start + 1 == stones.size() - 1 && stones[i] - stones[start] == stones.size() - 2) {
                minMove = min(minMove, 2);
            }
            else {
                minMove = min(minMove, int(stones.size()) - (i - start + 1));
            }
        }

        return vector<int>{minMove, maxMove};
    }
};
