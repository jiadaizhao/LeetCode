# 1102. Path With Maximum Minimum Value

Difficulty: Medium

https://leetcode.com/problems/path-with-maximum-minimum-value/

Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).


**Example 1:**  
![ex1](ex1.jpg)
```
Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: 
The path with the maximum score is highlighted in yellow. 
```

**Example 2:**  
![ex2](ex2.jpg)
```
Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
```

**Example 3:**  
![ex3](ex3.jpg)
```
Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
```

**Note:**

1. 1 <= R, C <= 100
2. 0 <= A[i][j] <= 10^9
