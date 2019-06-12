class Solution:
    def removeDuplicates(self, S: str) -> str:
        St = []
        for c in S:
            if St and c == St[-1]:
                St.pop()
            else:
                St.append(c)
        return ''.join(St)
