class Solution:
    def minAbbreviation(self, target: str, dictionary: List[str]) -> str:
        m = len(target)
        table = []
        candidate = 0
        for s in dictionary:
            if len(s) != m:
                continue
            mask = 0
            b = 1
            for i in range(m - 1, -1, -1):
                if s[i] != target[i]:
                    mask |= b
                b <<= 1
            table.append(mask)
            candidate |= mask
        
        bm = 1 << m
        minLen = m
        minAbbr = (1 << m) - 1
        def dfs(start, mask, l):
            nonlocal minLen, minAbbr
            if l >= minLen:
                return
            
            if any(mask & tm == 0 for tm in table):
                b = start
                while b < bm:
                    if (candidate & b):
                        if b == start and (b << 1) == bm:
                            nextLen = l
                        elif b == start or (b << 1) == bm:
                            nextLen = l + 1
                        else:
                            nextLen = l + 2
                        dfs(b << 1, mask | b, nextLen)
                    b <<= 1
            else:
                minLen = l
                minAbbr = mask

        dfs(1, 0, 1)
        result = []
        prev = 0
        b = 1 << (m - 1)
        for i in range(m):
            if minAbbr & b:
                if i - prev > 0:
                    result.append(str(i - prev))
                prev = i + 1
                result.append(target[i])
            elif i == m - 1:
                result.append(str(m - prev))
            b >>= 1

        return ''.join(result)
