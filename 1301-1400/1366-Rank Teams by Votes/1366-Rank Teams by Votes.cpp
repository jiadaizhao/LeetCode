class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> rank(26, vector<int>(27));
        for (char c : votes[0]) {
            rank[c - 'A'][26] = c;
        }
        for (string& vote : votes) {
            for (int i = 0; i < vote.size(); ++i) {
                --rank[vote[i] - 'A'][i];
            }
        }
        sort(rank.begin(), rank.end());
        string result;
        for (int i = 0; i < votes[0].size(); ++i) {
            result += rank[i][26];
        }
        return result;
    }
};
