class Solution {
public:
    string similarRGB(string color) {
        return "#" + similarColor(color.substr(1, 2)) + similarColor(color.substr(3, 2)) + similarColor(color.substr(5, 2));
    }
    
private:
    string similarColor(string col) {
        int val = stoi(col, 0, 16);
        val = val / 17 * 17 + ((val % 17) > 8 ? 17 : 0);
        int h = val / 16, l = val % 16;
        string result;
        if (h > 9) {
            result += 'a' + (h - 10);
        }
        else {
            result += '0' + h;
        }
        if (l > 9) {
            result += 'a' + (l - 10);
        }
        else {
            result += '0' + l;
        }
        return result; 
    }
};
