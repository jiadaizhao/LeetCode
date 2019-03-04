class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        if (n == 0) {
            return true;
        }
        
        int start = 0, end = n - 1;
        while (start <= end) {
            if (convert(num[start]) != num[end]) {
                return false;
            }
            ++start;
            --end;
        }
        
        return true;
    }
    
private:
    char convert(char ch) {
        if (ch == '0' || ch == '1' || ch == '8') {
            return ch;
        }
        else if (ch == '6') {
            return '9';
        }
        else if (ch == '9') {
            return '6';
        }
        else {
            return ' ';
        }
    }
};
