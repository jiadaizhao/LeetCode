class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bull = 0;
        unordered_map<char, int> secretTable;
        unordered_map<char, int> guessTable;
        for (int i = 0; i < n; ++i)
        {
            if (secret[i] == guess[i])
            {
                ++bull;
            }
            else
            {
                ++secretTable[secret[i]];
                ++guessTable[guess[i]];
            }
        }
        
        int cow = 0;
        for (auto it = secretTable.begin(); it != secretTable.end(); ++it)
        {
            cow += min(it->second, guessTable[it->first]);
        }
        
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bull = 0;
        int cow = 0;
        vector<int> table(10);

        for (int i = 0; i < n; ++i)
        {
            if (secret[i] == guess[i])
            {
                ++bull;
            }
            else
            {
                if (table[secret[i] - '0']++ < 0)
                {
                    ++cow;
                }
                
                if (table[guess[i] - '0']-- > 0)
                {
                    ++cow;
                }
            }
        }
        
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
