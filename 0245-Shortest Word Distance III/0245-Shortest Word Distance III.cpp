class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1;
        int result = INT_MAX;
        for (int i = 0; i < words.size(); ++i)
        {
            if (word1 != word2)
            {
                if (words[i] == word1)
                {
                    p1 = i;
                }
                else if (words[i] == word2)
                {
                    p2 = i;
                }
                
                if (p1 != -1 && p2 != -1)
                {
                    result = min(result, abs(p1 - p2));
                }
            }
            else if (words[i] == word1)
            {
                p1 = i;
                if (p2 != -1)
                {
                    result = min(result, abs(p1 - p2));
                }
                p2 = p1;
            }
        }
        
        return result;
    }
};
