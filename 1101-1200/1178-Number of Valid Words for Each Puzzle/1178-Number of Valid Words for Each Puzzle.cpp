class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> table;
        for (string word : words) {
            int curr = 0;
            for (char c : word) {
                curr |= (1 << (c - 'a'));
            }
            ++table[curr];
        }
        
        vector<int> answer(puzzles.size());
        for (int i = 0; i < puzzles.size(); ++i) {
            unordered_set<int> candidates({1 << (puzzles[i][0] - 'a')});
            for (int j = 1; j < puzzles[i].size(); ++j) {
                unordered_set<int> temp(candidates);
                for (int cand : candidates) {
                    temp.insert(cand | (1 << (puzzles[i][j] - 'a')));
                }
                swap(candidates, temp);
            }
            
            for (int cand : candidates) {
                answer[i] += table[cand];
            }
        }
        
        return answer;
    }
};
