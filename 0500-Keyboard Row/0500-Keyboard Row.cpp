class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (string& word : words)
        {
            if (isAvailable(word))
            {
                result.push_back(word);
            }
        }
        
        return result;
    }
    
private:
    bool isAvailable(string s)
    {
        if (s.size() <= 1)
        {
            return true;
        }
        
        string firstRow = "qwertyuiop";
        string secondRow = "asdfghjkl";
        int row = 0;
        for (char c : s)
        {
            c = tolower(c);
            int curr;
            if (firstRow.find(c) != string::npos)
            {
                curr = 1;
            }
            else if (secondRow.find(c) != string::npos)
            {
                curr = 2;
            }
            else
            {
                curr = 3;
            }
            
            if (row == 0)
            {
                row = curr;
            }
            else if (curr != row)
            {
                return false;
            }
        }
        return true;
    }
};
