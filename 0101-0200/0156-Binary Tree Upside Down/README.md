# 156. Binary Tree Upside Down

Difficulty: Medium

https://leetcode.com/problems/binary-tree-upside-down/description/

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
```
    1
   / \
  2   3
 / \
4   5
```
return the root of the binary tree [4,5,2,#,#,3,1].
```
   4
  / \
 5   2
    / \
   3   1  
```
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Companies: LinkedIn

Related Topics: Tree

Similar Questions: Reverse Linked List
