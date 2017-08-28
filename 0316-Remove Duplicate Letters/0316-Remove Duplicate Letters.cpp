class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        for (char c : s)
        {
            ++count[c - 'a'];
        }
        
        vector<bool> visited(26);
        string result;
        for (char c : s)
        {
            --count[c - 'a'];
            if (visited[c - 'a'])
            {
                continue;
            }
            
            while (result.size() && c < result.back() && count[result.back() - 'a'])
            {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            visited[c - 'a'] = true;
            result.push_back(c);
        }
        
        return result;
    }
};
