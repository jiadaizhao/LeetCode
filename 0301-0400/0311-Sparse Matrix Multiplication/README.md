# 311. Sparse Matrix Multiplication

Difficulty: Medium

https://leetcode.com/problems/sparse-matrix-multiplication/

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

**Example:**
```
Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
```
