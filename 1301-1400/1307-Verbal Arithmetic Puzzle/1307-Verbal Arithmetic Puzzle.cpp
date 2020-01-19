class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        for (string word : words) {
            if (word.size() > result.size())
                return false;
        }
        memset(c2i, -1, sizeof(c2i));
        memset(i2c, 0, sizeof(i2c));
        for (auto& s: words)
            reverse(s.begin(), s.end());
        reverse(result.begin(), result.end());
        return dfs(words, result, 0, 0, 0);
    }

private:    
    int c2i[26];
    int i2c[10];
    bool dfs(vector<string>& words, string& result, int idx, int digit, int sum) {
        if (digit == result.size()) return sum == 0;
        
        if (idx == words.size()) {
            if (c2i[result[digit] - 'A'] != -1) {
                if (sum % 10 == c2i[result[digit] - 'A'])
                    return dfs(words, result, 0, digit + 1, sum / 10);
            }
            else if (i2c[sum % 10] == 0) {
                if (digit == result.size() - 1 && sum % 10 == 0)
                    return false;
                c2i[result[digit] - 'A'] = sum % 10;
                i2c[sum % 10] = 1;
                if (dfs(words, result, 0, digit + 1, sum / 10))
                    return true;
                c2i[result[digit] - 'A'] = -1;
                i2c[sum % 10] = 0;
            }
            return false;
        }
        
        if (digit >= words[idx].size()) 
            return dfs(words, result, idx + 1, digit, sum);
        
        if (c2i[words[idx][digit] - 'A'] != -1) {
            if (digit == words[idx].size() - 1 && words[idx].size() > 1 && c2i[words[idx][digit] - 'A'] == 0)
                return false;                
            return dfs(words, result, idx + 1, digit, sum + c2i[words[idx][digit] - 'A']);
        }
        
        for (int i = 0; i < 10; ++i) {
            if (i2c[i] == 1) continue;
            if (i == 0 && digit == words[idx].size() - 1 && words[idx].size() > 1) continue;
            i2c[i] = 1;
            c2i[words[idx][digit] - 'A'] = i;
            if (dfs(words, result, idx + 1, digit, sum + i))
                return true;
            i2c[i] = 0;
            c2i[words[idx][digit] - 'A'] = -1;
        }
        return false;
    }
};
