class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        cp = []
        for num, start, end in trips:
            cp.append((start, 1, num))
            cp.append((end, 0, num))

        cp.sort()
        curr = 0
        for loc, flag, num in cp:
            if flag == 1:
                curr += num
                if curr > capacity:
                    return False
            else:
                curr -= num

        return True
