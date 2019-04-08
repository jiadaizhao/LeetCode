class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        table = {r: i for i, r in enumerate(list1)}
        r = []
        minSum = len(list1) + len(list2)
        for j, r in enumerate(list2):
            if r in table:
                i = table[r]
                if i + j < minSum:
                    minSum = i + j
                    result = [r]
                elif i + j == minSum:
                    result.append(r)
        return result
