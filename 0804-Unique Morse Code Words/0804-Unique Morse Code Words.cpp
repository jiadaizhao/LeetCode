class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> counts;
        for (string word : words) {
            string code;
            for (char c : word) {
                code += table[c - 'a'];
            }
            counts.insert(code);
        }
        return counts.size();
    }
};
