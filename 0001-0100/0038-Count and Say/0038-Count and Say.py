class Solution:
    def countAndSay(self, n: int) -> str:
        result = '1'
        for _ in range(n - 1):
            curr, count = '', 1
            for j in range(1, len(result)):
                if result[j] != result[j - 1]:
                    curr += str(count) + result[j - 1]
                    count = 1
                else:
                    count += 1
            curr += str(count) + result[-1]
            result = curr
        return result
