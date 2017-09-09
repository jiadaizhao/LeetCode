class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        int mask = 0;
        for (int b = 30; b >= 0; --b)
        {
            mask |= (1 << b);
            unordered_set<int> table;
            for (int& num : nums)
            {
                table.insert(num & mask);
            }
            
            int candidate = result | (1 << b);
            for (int i : table)
            {
                if (table.find(candidate ^ i) != table.end())
                {
                    result = candidate;
                    break;
                }
            }
        }
        
        return result;
    }
};

// Trie
class TrieNode {
public:
    TrieNode() {
        next.resize(2);
    }
    vector<TrieNode*> next;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = buildTrie(nums);
        int result = 0;
        for (int& num : nums)
        {
            result = max(result, findMaxXOR(root, num));
        }
        
        return result;
    }
    
    TrieNode* buildTrie(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        TrieNode* node = root;
        for (int& num : nums)
        {
            node = root;
            for (int i = 30; i >= 0; --i)
            {
                int index = (num & (1 << i)) ? 1 : 0;
                if (node->next[index] == nullptr)
                {
                    node->next[index] = new TrieNode();
                }
                node = node->next[index];
            }
        }
        
        return root;
    }
    
    int findMaxXOR(TrieNode* root, int num)
    {
        TrieNode* node = root;
        int result = 0;
        for (int i = 30; i >= 0; --i)
        {
            int mask = 1 << i;
            int index = (num & mask) ? 0 : 1;
            if (node->next[index] != nullptr)
            {
                node = node->next[index];
                result |= mask;
            }
            else
            {
                node = node->next[1 - index];
            }
        }
        return result;
    }
};
