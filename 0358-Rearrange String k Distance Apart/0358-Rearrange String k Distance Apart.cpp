class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0 || s.size() == 0)
        {
            return s;
        }
        vector<int> table(26);
        for (char c : s)
        {
            ++table[c - 'a'];
        }
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < table.size(); ++i)
        {
            if (table[i])
            {
                pq.emplace(table[i], 'a' + i);
            }
        }
        
        string result;
        int m = s.size();
        while (!pq.empty())
        {
            int pqs = pq.size();
            int count = min(m, k);
            if (pqs < count)
            {
                return "";
            }
            
            vector<int> tmp(26);
            while (count--)
            {
                auto p = pq.top();
                pq.pop();
                result += p.second;
                --m;
                tmp[p.second - 'a'] = --p.first;
            }
            
            for (int i = 0; i < tmp.size(); ++i)
            {
                if (tmp[i])
                {
                    pq.emplace(tmp[i], 'a' + i);
                }
            }
        }
        
        return result;
    }
};
