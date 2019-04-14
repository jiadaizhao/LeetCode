class Solution:
    def calPoints(self, ops: List[str]) -> int:
        St = []
        for op in ops:
            if op == '+':
                St.append(St[-1] + St[-2])
            elif op == 'D':
                St.append(St[-1]*2)
            elif op == 'C':
                St.pop()
            else:
                St.append(int(op))
        return sum(St)
