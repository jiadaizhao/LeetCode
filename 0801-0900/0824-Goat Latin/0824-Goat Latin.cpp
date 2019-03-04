class Solution {
public:
    string toGoatLatin(string S) {
        string result;
        int n = S.size(), i = 0, count = 0;
        while (i < n) {
            ++count;
            string word;
            while (i < n && S[i] != ' ') {
                word += S[i++];
            }
            if (isVowel(word[0])) {
                result += word + "ma";                
            }
            else {
                result += word.substr(1) + word.substr(0, 1) + "ma";                
            }
            int j = count;
            while (j--) {
                result += 'a';
            }
            if (i < n) {
                result += ' ';
            }
            ++i;
        }
        return result;
    }
    
private:
    bool isVowel(char c) {
        string target = "aeiou";
        return target.find(tolower(c)) != string::npos;
    }
};
