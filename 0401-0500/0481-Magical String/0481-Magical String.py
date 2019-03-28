class Solution:
    def magicalString(self, n: int) -> int:
        if n == 0:
            return 0
        seed = list('122')
        count = 1
        i = 2
        while len(seed) < n:
            num = int(seed[i])
            if seed[-1] == '1':
                seed += ['2'] * num
            else:
                seed += ['1'] * num
                count += (num if len(seed) <= n else 1)
            i += 1
        return count
