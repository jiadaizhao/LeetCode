class TrieNode {
public:
	TrieNode() {
		memset(next, 0, sizeof(next));
		word = "";
	}
    TrieNode *next[26];
    string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *root, vector<string>& result)
    {
        char c = board[i][j];
        if (c == '#' || root->next[c - 'a'] == nullptr)
        {
            return;
        }
        
        root = root->next[c - 'a'];
        if(root->word != "")
        {
            result.push_back(root->word);
            root->word = "";
        }
        board[i][j] = '#';
        if (i > 0)
        {
            dfs(board, i - 1, j, root, result);
        }
        if (i < board.size() - 1)
        {
            dfs(board, i + 1, j, root, result);
        }
        if (j > 0)
        {
            dfs(board, i, j - 1, root, result);
        }
        if (j < board[0].size() - 1)
        {
            dfs(board, i, j + 1, root, result);
        }
        board[i][j] = c;
    }
    
    TrieNode* buildTrie(vector<string>& words)
    {
        TrieNode *root = new TrieNode();
        for (string w : words)
        {
            TrieNode *p = root;
            for (char c : w)
            {
                int i = c - 'a';
                if (p->next[i] == nullptr)
                {
                    p->next[i] = new TrieNode();
                }
                p = p->next[i];
            }
            
            p->word = w;
        }
        
        return root;
    }
};
