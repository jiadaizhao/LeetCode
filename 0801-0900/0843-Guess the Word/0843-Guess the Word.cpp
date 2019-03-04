/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {        
        while (true) {
            int best = INT_MAX, best_i = -1;
            for (int i = 0; i < wordlist.size(); ++i) {
                int maxV = cal(wordlist, wordlist[i]);
                if (maxV < best) {
                    best = maxV;
                    best_i = i;
                }
            }

            int feedback = master.guess(wordlist[best_i]);
            if (feedback == 6) {
                break;
            }
            vector<string> nextWords;
            for (int i = 0; i < wordlist.size(); ++i) {
                if (i != best_i && same(wordlist[i], wordlist[best_i]) == feedback) {
                    nextWords.push_back(wordlist[i]);
                }
            }
            wordlist = move(nextWords);
        }
    }
    
private:
    int cal(vector<string>& wordlist, string s) {
        vector<int> count(7);
        for (string w : wordlist) {
            ++count[same(w, s)];
        }
        return *max_element(count.begin(), count.end());
    }
    int same(string& s1, string& s2) {
        int match = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                ++match;
            }
        }
        return match;
    }
};
