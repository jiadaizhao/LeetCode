# 1272. Remove Interval

Difficulty: Medium

https://leetcode.com/problems/remove-interval/

Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] represents the set of real numbers x such that a <= x < b.

We remove the intersections between any interval in intervals and the interval toBeRemoved.

Return a sorted list of intervals after all such removals.

**Example 1:**
```
Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
Output: [[0,1],[6,7]]
```

**Example 2:**
```
Input: intervals = [[0,5]], toBeRemoved = [2,3]
Output: [[0,2],[3,5]]
```

**Constraints:**

* 1 <= intervals.length <= 10^4
* -10^9 <= intervals[i][0] < intervals[i][1] <= 10^9
