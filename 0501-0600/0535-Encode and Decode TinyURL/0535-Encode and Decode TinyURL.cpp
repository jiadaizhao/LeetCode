class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key;
        do {
            key = getKey();
        } while (table.find(key) != table.end());
        
        table[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return table[shortUrl];
    }
    
    static string seed;
    
private:
    unordered_map<string, string> table;
    
    string getKey() {
        string s;
        for (int i = 0; i < 6; ++i) {
            s += seed[rand() % seed.size()];
        }
        return s;
    }
};

string Solution::seed = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
