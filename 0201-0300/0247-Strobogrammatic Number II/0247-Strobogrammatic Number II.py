class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        if n <= 0:
            return []
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
        return result
