import collections
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        num = 0
        Q = collections.deque([box for box in initialBoxes if status[box] == 1])
        possible = set([box for box in initialBoxes if status[box] == 0])
        while Q:
            box = Q.popleft()
            num += candies[box]
            for key in keys[box]:
                status[key] = 1
                if key in possible:
                    possible.remove(key)
                    Q.append(key)
            
            for cb in containedBoxes[box]:
                if status[cb] == 1:
                    Q.append(cb)
                else:
                    possible.add(cb)

        return num
