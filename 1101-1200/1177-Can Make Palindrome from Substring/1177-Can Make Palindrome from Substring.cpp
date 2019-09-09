class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> odds(1 + s.size());
        for (int i = 0; i < s.size(); ++i) {
            odds[i + 1] = odds[i] ^ (1 << (s[i] - 'a'));
        }
        
        vector<bool> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int num = odds[queries[i][1] + 1] ^ odds[queries[i][0]];
            int count = 0;
            while (num) {
                if (num & 1) ++count;
                num >>= 1;
            }

            answer[i] = (count / 2 <= queries[i][2]);
        }
        
        return answer;
    }
};
