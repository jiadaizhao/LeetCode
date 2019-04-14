class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        result = [0] * len(T)
        St = []
        for i in range(len(T) - 1, -1, -1):
            while St and T[St[-1]] <= T[i]:
                St.pop()
            if St:
                result[i] = St[-1] - i
            St.append(i)
        return result
