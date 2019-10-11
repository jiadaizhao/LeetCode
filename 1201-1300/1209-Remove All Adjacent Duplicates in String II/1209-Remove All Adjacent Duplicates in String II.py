class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        St = []
        for c in s:
            if St and St[-1][0] == c:
                St[-1][1] += 1
                if St[-1][1] == k:
                    St.pop()
            else:
                St.append([c, 1])

        return ''.join(c * num for c, num in St)
