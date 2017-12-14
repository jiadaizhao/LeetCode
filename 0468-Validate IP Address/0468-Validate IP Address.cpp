class Solution {
public:
    string validIPAddress(string IP) {
        stringstream ss(IP);
        string s;
        if (IP.substr(0, 4).find('.') != string::npos) {
            for (int i = 0; i < 4; ++i) {
                if (!getline(ss, s, '.') || !isIP4Block(s)) {
                    return "Neither";
                }
            }
            
            return ss.eof() ? "IPv4" : "Neither";
        }
        else if (IP.substr(0, 5).find(':') != string::npos) {
            for (int i = 0; i < 8; ++i) {
                if (!getline(ss, s, ':') || !isIP6Block(s)) {
                    return "Neither";
                }
            }
            
            return ss.eof() ? "IPv6" : "Neither";
        }
        else {
            return "Neither";
        }
    }
    
private:
    bool isIP4Block(string s) {
        if (s.size() == 0 || s.size() > 3) {
            return false;
        }
        
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (!isdigit(c) || (c == '0' && i == 0 && s.size() > 1)) {
                return false;
            }
            
            num = num * 10 + (c - '0');
        }
        
        return num <= 255;
    }
    
    bool isIP6Block(string s) {
        if (s.size() == 0 || s.size() > 4) {
            return false;
        }
        
        for (char c : s) {
            if (!validHex(c)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool validHex(char c) {
        string s = "0123456789abcdefABCDEF";
        return s.find(c) != string::npos;
    }
};
