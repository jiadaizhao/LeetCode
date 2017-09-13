# 469. Convex Polygon

Difficulty: Medium

https://leetcode.com/problems/convex-polygon/description/

Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

1. There are at least 3 and at most 10,000 points.
2. Coordinates are in the range -10,000 to 10,000.
3. You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.

**Example 1:**
```
[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:
```
![alt text](polygon_convex.png)

Example 2:
```
[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:
```
![alt text](polygon_not_convex.png)

Companies: Google

Related Topics: Math
