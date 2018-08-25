class Solution:
    def decodeAtIndex(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        n = 0
        for i in range(len(S)):
            if S[i].isdigit():
                n *= int(S[i])
            else:
                n += 1
            if n >= K:
                break
        
        for j in range(i, -1, -1):
            K %= n
            if K == 0 and S[j].isalpha():
                return S[j]
            
            if S[j].isdigit():
                n /= int(S[j])
            else:
                n -= 1           
