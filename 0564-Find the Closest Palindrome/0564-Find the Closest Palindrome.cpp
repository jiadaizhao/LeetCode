class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        vector<long> candidates;
        // biggest, one more digit, 10...01
        candidates.push_back(pow(10, l) + 1LL);
        // smallest, one less digit, 9...9 or 0
        candidates.push_back(pow(10, l - 1) - 1LL);
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for (int i = -1; i <= 1; ++i)
        {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.push_back(stol(pp));
        }
        
        long minDiff = LONG_MAX;
        long minVal;
        long num = stol(n);
        for (long c : candidates)
        {
            if (c != num)
            {
                long diff = abs(num - c);
                if (diff < minDiff)
                {
                    minDiff = diff;
                    minVal = c;

                }
                else if (diff == minDiff && c < minVal)
                {
                    minVal = c;
                }
            }            
        }
        
        return to_string(minVal);
        
    }
};
