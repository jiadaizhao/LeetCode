class Solution:
    def uniqueLetterString(self, S: str) -> int:
        last = [-1] * 26
        prev = [-1] * len(S)
        next = [-1] * len(S)
        for i in range(len(S)):
            index = ord(S[i]) - ord('A')
            prev[i] = last[index]
            last[index] = i
        
        last = [-1] * 26
        for i in range(len(S) - 1, -1, -1):
            index = ord(S[i]) - ord('A')
            next[i] = last[index]
            last[index] = i
            
        count = 0
        MOD = 1000000007
        for i in range(len(S)):
            l1 = i - prev[i]
            l2 = len(S) - i if (next[i] == -1) else (next[i] - i)
            count = (count + l1 * l2) % MOD
        return count


import collections
class Solution2:
    def uniqueLetterString(self, S: str) -> int:
        table = collections.defaultdict(list)
        for i, c in enumerate(S):
            table[c].append(i)
            
        count = 0
        MOD = 10**9 + 7
        for index in table.values():
            index = [-1] + index + [len(S)]
            for i in range(1, len(index) - 1):
                count = (count + (index[i] - index[i - 1])*(index[i + 1] - index[i])) % MOD
        return count
