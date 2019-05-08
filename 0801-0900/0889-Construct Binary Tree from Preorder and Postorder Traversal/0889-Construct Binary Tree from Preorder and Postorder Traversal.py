# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        if not pre:
            return None
        root = TreeNode(pre[0])
        if len(pre) == 1:
            return root
        i = post.index(pre[1])
        root.left = self.constructFromPrePost(pre[1 : i + 2], post[0 : i + 1])
        root.right = self.constructFromPrePost(pre[i + 2 :], post[i + 1 : -1])
        return root

class Solution2:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        table = {v: i for i, v in enumerate(post)}
        def dfs(preStart, postStart, n):
            if n == 0:
                return None
            root = TreeNode(pre[preStart])
            if n == 1:
                return root

            i = table[pre[preStart + 1]]
            L = i - postStart + 1
            root.left = dfs(preStart + 1, postStart, L)
            root.right = dfs(preStart + L + 1, i + 1, n - L - 1)
            return root
        return dfs(0, 0, len(pre))

class Solution3:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        St = [TreeNode(pre[0])]
        i = 0
        for val in pre[1:]:
            while St[-1].val == post[i]:
                St.pop()
                i += 1
            node = TreeNode(val)
            if St[-1].left:
                St[-1].right = node
            else:
                St[-1].left = node
            St.append(node)
        return St[0]
