struct pairhash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {     
        int maxNum = 0;
        for (int i = 0; i < points.size(); ++i) {
            int same = 0, localMax = 0;
            unordered_map<pair<int, int>, int, pairhash> table;
            for (int j = 0; j < i; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++same;
                }
                else {
                    int a = points[i][0] - points[j][0];
                    int b = points[i][1] - points[j][1];
                    int c = gcd(a, b);
                    a /= c;
                    b /= c;
                    ++table[{a, b}];
                    localMax = max(localMax, table[{a, b}]);
                }
            }
            
            maxNum = max(maxNum, localMax + same + 1);
        }
        
        return maxNum;
    }
    
private:
    int gcd(int a, int b) {
        while (b) {
            int temp = a;
            a = b;
            b = temp % b;
        }        
        return a;
    }
};
