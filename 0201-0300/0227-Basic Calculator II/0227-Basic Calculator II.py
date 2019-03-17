class Solution:
    def calculate(self, s: str) -> int:
        St = []
        num = 0
        preop = '+'
        for i in range(len(s)):
            if s[i].isdigit():
                num = num * 10 + ord(s[i]) - ord('0')
            if i == len(s) - 1 or s[i] in '+-*/':
                if preop == '+':
                    St.append(num)
                elif preop == '-':
                    St.append(-num)
                elif preop == '*':
                    St.append(St.pop() * num)
                else:
                    St.append(int(St.pop() / num))
                preop = s[i]
                num = 0
        return sum(St)
