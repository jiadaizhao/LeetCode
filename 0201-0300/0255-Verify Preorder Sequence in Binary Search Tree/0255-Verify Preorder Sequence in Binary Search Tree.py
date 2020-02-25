import math
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        root = -math.inf
        St = []
        for num in preorder:
            if num < root:
                return False
            while St and St[-1] < num:
                root = St.pop()
            St.append(num)
        return True


class Solution2:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        root = -math.inf
        i = 0
        for num in preorder:
            if num < root:
                return False
            while i and preorder[i - 1] < num:
                root = preorder[i - 1]
                i -= 1
            preorder[i] = num
            i += 1
        return True
