class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        St = [0]
        for c in S:
            if c == '(':
                St.append(0)
            else:
                v = St.pop()
                St[-1] += max(v*2, 1)
        return St.pop()

class Solution2:
    def scoreOfParentheses(self, S: str) -> int:
        score = bal = 0
        for i in range(len(S)):
            if S[i] == '(':
                bal += 1
            else:
                bal -= 1
                if S[i - 1] == '(':
                    score += (1 << bal)
        return score
