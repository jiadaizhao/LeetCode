class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freqCounts(12);
        for (string& word : words) {
            int freq = getSmallestChFreq(word);
            ++freqCounts[freq];
        }
        
        for (int i = freqCounts.size() - 2; i >= 0; --i) {
            freqCounts[i] += freqCounts[i + 1];
        }
        
        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int freq = getSmallestChFreq(queries[i]);
            answer[i] = freqCounts[freq + 1];
        }
        
        return answer;
    }
    
private:
    int getSmallestChFreq(string& word) {
        vector<int> count(26);
        for (char c : word) {
            ++count[c - 'a'];
        }
        
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] > 0) {
                return count[i];
            }
        }
        
        return 0;
    }
};
