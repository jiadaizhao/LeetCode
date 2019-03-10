class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2):
            return False
        dp = [False] * (1 + len(s2))
        dp[0] = True
        for j in range(1, len(dp)):
            if s2[j - 1] == s3[j - 1]:
                dp[j] = True
            else:
                break
                
        for i in range(1, len(s1) + 1):
            temp = [False] * (1 + len(s2))
            temp[0] = dp[0] and (s1[i - 1] == s3[i - 1])
            for j in range(1, len(s2) + 1):
                temp[j] = (((s1[i - 1] == s3[i + j - 1]) and dp[j]) or
                    ((s2[j - 1] == s3[i + j - 1]) and temp[j - 1]))
            dp = temp
        return dp[-1]
