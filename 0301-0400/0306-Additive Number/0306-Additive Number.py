class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        if len(num) < 3:
            return False

        def dfs(start, s1, s2):
            if start == len(num):
                return True

            if (len(s1) > 1 and s1[0] == '0') or (len(s2) > 1 and s2[0] == '0') or ((len(s1) > 1 or len(s2) > 1) and num[start] == '0'):
                return False

            sum = str(int(s1) + int(s2))
            s3 = num[start: start + len(sum)]
            if sum != s3:
                return False

            return dfs(start + len(s3), s2, s3)

        for i in range(1, len(num) // 2 + 1):
            for j in range(1, len(num) // 2 + 1):
                if len(num) - i - j < max(i, j):
                    break

                if dfs(i + j, num[:i], num[i: i + j]):
                    return True

        return False
