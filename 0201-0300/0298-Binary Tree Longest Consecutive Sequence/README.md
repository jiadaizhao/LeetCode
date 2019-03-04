# 298. Binary Tree Longest Consecutive Sequence

Difficulty: Medium

https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
```
   1
    \
     3
    / \
   2   4
        \
         5
```
Longest consecutive sequence path is 3-4-5, so return 3.
```
   2
    \
     3
    / 
   2    
  / 
 1
```
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

Companies: Google

Related Topics: Tree

Similar Questions: Longest Consecutive Sequence, Binary Tree Longest Consecutive Sequence II
