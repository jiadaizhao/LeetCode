class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        table = {r: i for i, r in enumerate(list1)}
        minSum = len(list1) + len(list2)
        result = []
        for i, r in enumerate(list2):
            if r in table:
                if table[r] + i < minSum:
                    minSum = table[r] + i
                    result = [r]
                elif table[r] + i == minSum:
                    result.append(r)
        return result
