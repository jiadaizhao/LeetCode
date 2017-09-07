class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> steps;
        steps[0].insert(0);
        for (int stone : stones)
        {
            for (int step : steps[stone])
            {
                if (step > 1)
                {
                    steps[stone + step - 1].insert(step - 1);
                }
                steps[stone + step].insert(step);
                steps[stone + step + 1].insert(step + 1);
            }
        }
        
        return steps[stones.back()].size() > 0;
    }
};
