# 1273. Delete Tree Nodes

Difficulty: Medium

https://leetcode.com/problems/delete-tree-nodes/

A tree rooted at node 0 is given as follows:

* The number of nodes is nodes;
* The value of the i-th node is value[i];
* The parent of the i-th node is parent[i].

Remove every subtree whose sum of values of nodes is zero.

After doing so, return the number of nodes remaining in the tree.

**Example 1:**  
![ex1](ex1.png)
```
Input: nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
Output: 2
```

**Constraints:**

* 1 <= nodes <= 10^4
* -10^5 <= value[i] <= 10^5
* parent.length == nodes
* parent[0] == -1 which indicates that 0 is the root.
