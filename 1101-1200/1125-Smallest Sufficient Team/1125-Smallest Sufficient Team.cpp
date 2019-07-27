class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> table;
        for (int i = 0; i < req_skills.size(); ++i) {
            table[req_skills[i]] = (1 << i);
        }
        
        int n = req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n); // use reserved space to avoid rehashing, otherwise iterrator update in dp can cause wrong result 
        dp[0] = {};
        for (int i = 0; i < people.size(); ++i) {
            int curr = 0;
            for (string s : people[i]) {
                if (table.count(s)) {
                    curr |= table[s];
                }
            }
            
            for (auto p : dp) {
                int newSkills = p.first | curr;
                if (newSkills != p.first) {
                    if (!dp.count(newSkills) || dp[newSkills].size() > p.second.size() + 1) {
                        dp[newSkills] = p.second;
                        dp[newSkills].push_back(i);
                    }
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
