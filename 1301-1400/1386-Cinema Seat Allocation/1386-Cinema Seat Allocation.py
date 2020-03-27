import collections
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        table = collections.defaultdict(list)
        for row, col in reservedSeats:
            table[row].append(col)
        
        count = (n - len(table)) * 2
        for cols in table.values():
            cols.sort()
            
            if len(cols) == 1:
                if cols[0] == 1 or cols[0] == 10:
                    count += 2
                else:
                    count += 1
            else:
                if cols[0] >= 6 or cols[-1] <= 5:
                    count += 1
                else:
                    for i in range(1, len(cols)):
                        d = cols[i] - cols[i - 1] - 1
                        if d >= 4:
                            if d == 8:
                                count += 2
                            elif d > 4 or cols[i - 1] != 2 and cols[i - 1] != 4:
                                count += 1
                            break                       
            
        return count            


# Mask
import collections
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        table = collections.defaultdict(int)
        for row, col in reservedSeats:
            table[row] |= 1 << (col - 1)
        
        count = (n - len(table)) * 2
        for mask in table.values():
            if (mask & 0b0111111110) == 0:
                count += 2
            elif (mask & 0b0111100000) == 0 or (mask & 0b0001111000) == 0 or (mask & 0b0000011110) == 0:
                count += 1                   
            
        return count
