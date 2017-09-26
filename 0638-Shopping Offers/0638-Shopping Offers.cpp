class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        base = vector<int>(n);
        base[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            base[i] = base[i + 1] * 10;
        }
        
        int key = 0;
        for (int i = 0; i < n; ++i)
        {
            key = key * 10 + needs[i];
        }
        
        return dfs(price, special, key);
    }
    
private:
    unordered_map<int, int> table;
    vector<int> base;
    int dfs(vector<int>& price, vector<vector<int>>& special, int key)
    {
        if (table.find(key) != table.end())
        {
            return table[key];
        }
        
        int n = price.size();
        int total = 0;
        for (int i = 0; i < n; ++i)
        {
            total += ((key / base[i]) % 10) * price[i];
        }

        for (auto s : special)
        {
            int k = 0;
            int i;
            for (i = 0; i < n; ++i)
            {
                int curr = (key / base[i]) % 10;
                if (curr >= s[i])
                {
                    k = k * 10 + curr - s[i];
                }
                else
                {
                    break;
                }
            }

            if (i == n)
            {
                total = min(total, s[n] + dfs(price, special, k));
            }            
        }
        
        return table[key] = total;
    }
};
