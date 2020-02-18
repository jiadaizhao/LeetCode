class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        table = {'0':'0', '1':'1', '8':'8', '6':'9', '9':'6'}
        start, end = 0, len(num) - 1
        while start <= end:
            if num[start] not in table or table[num[start]] != num[end]:
                return False
            start += 1
            end -= 1
        return True
