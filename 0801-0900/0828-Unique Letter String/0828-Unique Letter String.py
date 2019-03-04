class Solution:
    def uniqueLetterString(self, S):
        """
        :type S: str
        :rtype: int
        """
        n = len(S)
        last = [-1] * 26
        prev = [-1] * n
        next = [-1] * n
        for i in range(n):
            index = ord(S[i]) - ord('A')
            prev[i] = last[index]
            last[index] = i
        
        last = [-1] * 26
        for i in range(n - 1, -1, -1):
            index = ord(S[i]) - ord('A')
            next[i] = last[index]
            last[index] = i
            
        count = 0
        MOD = 1000000007
        for i in range(n):
            l1 = i - prev[i]
            l2 = n - i if (next[i] == -1) else (next[i] - i)
            count = (count + l1 * l2) % MOD
        return count
