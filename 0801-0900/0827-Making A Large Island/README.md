# 827. Making A Large Island

Difficulty: Hard

https://leetcode.com/problems/making-a-large-island/

In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

**Example 1:**
```
Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```
**Example 2:**
```
Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
```
**Example 3:**
```
Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 1.
```

**Notes:**

* 1 <= grid.length = grid[0].length <= 50.
* 0 <= grid[i][j] <= 1.

Companies: Uber

Related Topics: Depth-first Search
