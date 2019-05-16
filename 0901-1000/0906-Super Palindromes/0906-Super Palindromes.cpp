class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long long l = stoll(L), r = stoll(R);
        int MAGIC = 100000, count = 0;
        for (int i = 0; i < MAGIC; ++i) {
            string left = to_string(i);
            string rleft = left.substr(0, left.size() - 1);
            reverse(rleft.begin(), rleft.end());
            long long temp = stoll(left + rleft);
            long long candidate = temp * temp;
            if (candidate > r) {
                break;
            }
            string cs = to_string(candidate);
            if (candidate >= l && isPalindrome(cs)) {
                count += 1;
            }     
        }
        
        for (int i = 0; i < MAGIC; ++i) {
            string left = to_string(i);
            string rleft = left;
            reverse(rleft.begin(), rleft.end());
            long long temp = stoll(left + rleft);
            long long candidate = temp * temp;
            if (candidate > r) {
                break;
            }
            string cs = to_string(candidate);
            if (candidate >= l && isPalindrome(cs)) {
                count += 1;
            }     
        }
        return count;
    }
    
private:
    bool isPalindrome(string& s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start += 1;
            end -= 1;
        }
        return true;
    }
};
