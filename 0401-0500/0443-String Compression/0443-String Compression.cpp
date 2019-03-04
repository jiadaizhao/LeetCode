class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n <= 1) {
            return n;
        }
        
        int start = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || chars[i + 1] != chars[i]) {
                chars[count++] = chars[start];                
                if (i > start) {
                    string num = to_string(i - start + 1);
                    for (char c : num) {
                        chars[count++] = c;
                    }
                }
                start = i + 1;
            }
        }

        return count;
    }
};
