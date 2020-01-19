class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int index = s.find('6');
        if (index != -1) {
            s[index] = '9';
            return stoi(s);
        }
        return num;
    }
};
