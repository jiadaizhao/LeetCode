# 1214. Two Sum BSTs

Difficulty: Medium

https://leetcode.com/problems/two-sum-bsts/

Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

**Example 1:**  
![ex1](ex1_1.png) ![ex1](ex1_2.png)
```
Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
```

**Example 2:**  
![ex2](ex2_1.png) ![ex2](ex2_2.png)
```
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false
```

**Constraints:**

* Each tree has at most 5000 nodes.
* -10^9 <= target, node.val <= 10^9
