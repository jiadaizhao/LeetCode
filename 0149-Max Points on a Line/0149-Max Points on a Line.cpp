/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct pairhash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n <= 2)
        {
            return n;
        }
        
        int maxNum = 0;
        for (int i = 0; i < n; ++i)
        {
            int same = 0, vertical = 0;
            unordered_map<pair<int, int>, int, pairhash> table;
            int localMax = 0;
            for (int j = i + 1; j < n; ++j)
            {
                if (points[j].x == points[i].x && points[j].y == points[i].y)
                {
                    ++same;
                }
                else if (points[j].x == points[i].x)
                {
                    ++vertical;
                }
                else
                {
                    int a = points[j].x - points[i].x;
                    int b = points[j].y - points[i].y;
                    int c = gcd(a, b);
                    a /= c;
                    b /= c;
                    ++table[{a, b}];
                    localMax = max(localMax, table[{a, b}]);
                }
            }
            
            maxNum = max(maxNum, max(localMax, vertical) + same + 1);
        }
        
        return maxNum;
    }
    
private:
    int gcd(int a, int b)
    {
        while (b)
        {
            int temp = a;
            a = b;
            b = temp % b;
        }
        
        return a;
    }
};
