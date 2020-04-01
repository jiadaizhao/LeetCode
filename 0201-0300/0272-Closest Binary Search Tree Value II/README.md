# 272. Closest Binary Search Tree Value II

Difficulty: Hard

https://leetcode.com/problems/closest-binary-search-tree-value-ii/

Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

**Note:**

* Given target value is a floating point.
* You may assume k is always valid, that is: k ≤ total nodes.
* You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

**Example:**
```
Input: root = [4,2,5,1,3], target = 3.714286, and k = 2

    4
   / \
  2   5
 / \
1   3

Output: [4,3]
```

**Follow up:**

Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
