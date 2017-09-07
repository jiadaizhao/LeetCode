class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp());
        vector<pair<int, int>> result;
        for (auto& p : people)
        {
            result.insert(result.begin() + p.second, p);
        }
        
        return result;
    }
    
private:
    struct cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2)
        {
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            else
            {
                return p1.first > p2.first;
            }
        }
    };
};
