class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int currA = 0, currB = 0, currC = 0;
        string result;
        while (a || b || c) {
            if ((a >= max(b, c) && currA < 2) || (a > 0 && (currB == 2 || currC == 2))) {
                result += 'a';
                --a;
                ++currA;
                currB = currC = 0;
            }
            else if ((b >= max(a, c) && currB < 2) || (b > 0 && (currA == 2 || currC == 2))) {
                result += 'b';
                --b;
                ++currB;
                currA = currC = 0;
            }
            else if ((c >= max(a, b) && currC < 2) || (c > 0 && (currA == 2 || currB == 2))) {
                result += 'c';
                --c;
                ++currC;
                currA = currB = 0;
            }
            else {
                break;
            }
        }

        return result;
    }
};
