class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        count = 0
        table = {'0':'0', '1':'1', '8':'8', '6':'9', '9':'6'}
        low = list(low)
        high = list(high)
        def dfs(s, left, right):
            nonlocal count
            if left > right:
                if not((len(s) == len(low) and s < low) or (len(s) == len(high) and s > high)):
                    count += 1
            else:
                for p1, p2 in table.items():
                    s[left] = p1
                    s[right] = p2
                    if len(s) == 1 or s[0] != '0':
                        if left < right or p1 == p2:
                            dfs(s, left + 1, right - 1)
                    s[left] = s[right] = '0'                    
                    
        for i in range(len(low), len(high) + 1):
            s = ['0'] * i
            dfs(s, 0, i - 1)
        return count


class Solution2:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        count = 0
        table = {'0':'0', '1':'1', '8':'8', '6':'9', '9':'6'}
        def findStrobogrammatic(n):
            nonlocal count
            if n & 1:
                n -= 1
                result = ['0', '1', '8']
            else:
                result = ['']

            while n:
                temp = []
                for s in result:
                    if n != 2:
                        temp.append('0' + s + '0')
                    temp.append('1' + s + '1')
                    temp.append('6' + s + '9')
                    temp.append('8' + s + '8')
                    temp.append('9' + s + '6')
                n -= 2
                result = temp
            
            for s in result:
                if not((len(s) == len(low) and s < low) or (len(s) == len(high) and s > high)):
                    count += 1                    
                    
        for i in range(len(low), len(high) + 1):
            findStrobogrammatic(i)
        return count
