class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1;
        int minDist = words.size();
        bool diff = (word1 != word2);
        for (int i = 0; i < words.size(); ++i) {
            if (diff) {
                if (words[i] == word1) {
                    if (p2 != -1) {
                        minDist = min(minDist, i - p2);
                    }
                    p1 = i;
                }
                else if (words[i] == word2) {
                    if (p1 != -1) {
                        minDist = min(minDist, i - p1);
                    }
                    p2 = i;
                }
            }
            else if (words[i] == word1) {
                if (p2 != -1) {
                    minDist = min(minDist, i - p2);
                }
                p2 = i;
            }
        }
        
        return minDist;
    }
};
