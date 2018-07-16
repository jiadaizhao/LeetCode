# 428. Serialize and Deserialize N-ary Tree

Difficulty: Hard

https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/description/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

![alt text](NaryTreeExample.png) 

as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Note:**

1. N is in the range of [1, 1000]
2. Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Similar Questions: Encode N-ary Tree to Binary Tree
