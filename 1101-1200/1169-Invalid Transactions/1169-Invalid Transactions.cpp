class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<vector<string>>> table;
        unordered_set<string> result;
        
        for(string t : transactions){
            istringstream ss(t);
            vector<string> s(4);
            int i = 0;
            while (getline(ss, s[i++], ','));
            if(stoi(s[2]) > 1000) {
                result.insert(t);
            }
            for (auto& history : table[s[0]]) {
                if (abs(stoi(s[1]) - stoi(history[1])) <= 60 && history[3] != s[3]) {
                    result.insert(history[0] + ',' + history[1] + ',' + history[2] + ',' + history[3]);
                    result.insert(t);
                }
            }

            table[s[0]].push_back({s[0], s[1], s[2], s[3]});
        }
        vector<string> ans;
        for(string s : result) {
            ans.push_back(s);
        }
        return ans;
    }
};
