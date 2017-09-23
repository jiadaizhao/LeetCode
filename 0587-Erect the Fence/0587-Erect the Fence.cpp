/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        sort(points.begin(), points.end(), cmp());
        int n = points.size();
        vector<Point> hull;

        for (int i = 0; i < n; ++i)
        {
            while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), points[i]) < 0)
            {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        if (hull.size() == n)
        {
            return hull;
        }
        
        for (int i = n - 2; i >= 0; --i)
        {
            while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), points[i]) < 0)
            {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        hull.pop_back();
                
        return hull;
    }
    
private:
    struct cmp {
        bool operator() (Point p1, Point p2) {
            if (p1.x == p2.x)
            {
                return p1.y < p2.y;
            }
            else
            {
                return p1.x < p2.x;
            }
        }
    };
    
    int orientation(Point p, Point q, Point r)
    {
        return (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x);
    }
};
