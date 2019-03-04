class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        vector<int> table(26);
        for (char c : S) {
            ++table[c - 'a'];
        }
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (table[i] > 0) {
                pq.emplace(table[i], 'a' + i);
            }
        }
        
        string result;
        char prevChar = ' ';
        int prevCount = -1;
        while (!pq.empty()) {
            int count = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            result += c;
            
            if (prevCount > 0) {
                pq.emplace(prevCount, prevChar);
            }
            
            prevCount = count - 1;
            prevChar = c;
        }
        
        return result.size() == n ? result : "";
    }
};
