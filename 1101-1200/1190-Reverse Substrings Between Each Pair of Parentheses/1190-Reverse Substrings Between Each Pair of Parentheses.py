class Solution:
    def reverseParentheses(self, s: str) -> str:
        s = list(s)
        St = []
        for i, c in enumerate(s):
            if c == '(':
                St.append(i)
            elif c == ')':
                left = St.pop()
                s[left + 1 : i] = s[left + 1 : i][::-1]
        
        return ''.join(c if c.islower() else '' for c in s)
