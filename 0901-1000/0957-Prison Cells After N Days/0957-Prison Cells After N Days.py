class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:    
        table = []
        visited = {}
        def findNext(curr):
            next = [0] * 8
            for i in range(1, 7):
                if not (curr[i - 1] ^ curr[i + 1]):
                    next[i] = 1
            return next
        
        def convert(A):
            num = 0
            for i in range(8):
                num = num * 2 + A[i]
            return num
        
        def numToArray(num):
            result = [0] * 8
            for i in range(7, -1, -1):
                result[i] = num & 1
                num //= 2
                if num == 0:
                    break
            return result

        for i in range(N):
            cells = findNext(cells)
            num = convert(cells)
            if num in visited:
                index = visited[num] + (N - 1 - visited[num]) % (i - visited[num])
                break
            table.append(num)
            visited[num] = i
        else:
            return numToArray(table[-1]) 
        
        return numToArray(table[index])
