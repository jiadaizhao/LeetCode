class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for (string& str : strs) {
            result += to_string(str.size()) + '@' + str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int len = 0;
            while (i < s.size() && s[i] != '@') {
                len = len * 10 + (s[i] - '0');
                ++i;
            }
            
            ++i;
            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
