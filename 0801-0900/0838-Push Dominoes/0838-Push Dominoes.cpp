class Solution {
public:
    string pushDominoes(string dominoes) {
        string result(dominoes);
        int last = -1;
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i] == 'L') {
                int j;
                if (last != -1 && dominoes[last] == 'R') {
                    j = (i + last) / 2;
                    if (((i + last) & 1) == 0) {
                        result[j] = '.';
                    }
                }
                else {
                    j = last;
                }
                fill(result.begin() + j + 1, result.begin() + i, 'L');                
            }
            if (dominoes[i] != '.') {
                last = i;
            }
            else if (last != -1 && dominoes[last] == 'R') {
                result[i] = 'R';
            }
        }
        return result;
    }
};
