import collections
class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        table = collections.Counter(s)
        odd = 0
        mid = ['']
        seed = ''
        for k, v in table.items():
            if v & 1:
                odd += 1                
                if odd > 1:
                    return ''
                mid = [k]
            seed += k * (v // 2)

        path = []
        result = []
        used = [False] * len(seed)
        def dfs():
            if len(path) == len(seed):
                result.append(''.join(path + mid + path[::-1]))
            for i in range(len(seed)):
                if used[i]:
                    continue
                if i > 0 and seed[i] == seed[i - 1] and not used[i - 1]:
                    continue
                used[i] = True
                path.append(seed[i])
                dfs()
                path.pop()
                used[i] = False
        
        dfs()
        return result
