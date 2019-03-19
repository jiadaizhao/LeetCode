class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        result = []
        def removeParantheses(s, lastLeft, lastRight, left, right):
            bal = 0
            for i in range(lastLeft, len(s)):
                if s[i] == left:
                    bal += 1
                elif s[i] == right:
                    bal -= 1

                if bal >= 0:
                    continue

                for j in range(lastRight, i + 1):
                    if s[j] == right and (j == lastRight or s[j - 1] != right):
                        removeParantheses(s[:j] + s[j+1:], i, j, left, right)
                
                return

            if left == '(':
                removeParantheses(s[::-1], 0, 0, right, left)
            else:
                result.append(s[::-1])

        removeParantheses(s, 0, 0, '(', ')')
        return result
