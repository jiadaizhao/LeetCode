class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        unordered_map<int, int> count;
        int maxCount = 0;
        for (int i = 0; i < persons.size(); ++i) {
            if (++count[persons[i]] >= maxCount) {
                maxCount = count[persons[i]];
                table.emplace_back(times[i], persons[i]);
            }
        }
    }
    
    int q(int t) {
        auto it = upper_bound(table.begin(), table.end(), make_pair(t, INT_MAX));
        return (--it)->second;
    }
    
private:
    vector<pair<int, int>> table;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
