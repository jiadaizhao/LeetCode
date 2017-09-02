class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int p1 = 0, p2 = 0;
        while (p1 < m && p2 < n)
        {
            if (s[p1] == t[p2])
            {
                ++p1;
            }
            ++p2;
        }
        
        return p1 == m;
    }
};

/* Follow up: Preprocess string t, save each letter with index array,
find target letter in index array with binary search.*/