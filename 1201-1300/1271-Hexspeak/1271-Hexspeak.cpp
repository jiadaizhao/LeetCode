class Solution {
public:
    string toHexspeak(string num) {
        long n = stol(num);
        stringstream ss;
        ss << hex << uppercase << n;
        string s(ss.str());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > '1' && s[i] <= '9') return "ERROR";
            if (s[i] == '0') s[i] = 'O';
            if (s[i] == '1') s[i] = 'I';
        }
        return s;
    }
};
