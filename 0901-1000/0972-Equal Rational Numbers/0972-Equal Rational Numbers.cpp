class Solution {
public:
    bool isRationalEqual(string S, string T) {
        return convert(S) == convert(T);
    }

private:
    double convert(string S) {
        int i = S.find("(");
        if (i != string::npos) {
            string base = S.substr(0, i);
            string rep = S.substr(i + 1, S.size() - i - 2);
            for (int j = 0; j < 20; ++j) {
                base += rep;
            }
            return stod(base);
        }
        return stod(S);
    }
};
