class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10);
        for (char c : s)
        {
            switch (c)
            {
                case 'z':
                    ++count[0]; // 0
                    break;
                case 'o':
                    ++count[1]; // 0, 1, 2, 4
                    break;
                case 'w':
                    ++count[2]; // 2
                    break;
                case 't':
                    ++count[3]; // 2, 3, 8
                    break;
                case 'u':
                    ++count[4]; // 4
                    break;
                case 'f':
                    ++count[5]; // 4, 5
                    break;
                case 'x':
                    ++count[6]; // 6
                    break;
                case 's':
                    ++count[7]; // 6, 7
                    break;
                case 'g':
                    ++count[8]; // 8
                    break;
                case 'i':
                    ++count[9]; // 5, 6, 8, 9
                    break;
            }
        }
        
        count[1] -= count[0] + count[2] + count[4];
        count[3] -= count[2] + count[8];
        count[5] -= count[4];
        count[7] -= count[6];
        count[9] -= count[5] + count[6] + count[8];
        
        string result;
        for (int i = 0; i < count.size(); ++i)
        {
            while (count[i]--)
            {
                result += '0' + i;
            }
        }
        
        return result;
    }
};
