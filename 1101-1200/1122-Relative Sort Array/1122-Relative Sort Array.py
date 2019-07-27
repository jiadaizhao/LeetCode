class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        table = [0] * 1001
        for a in arr1:
            table[a] += 1

        result = [0] * len(arr1)
        i = 0
        for a in arr2:
            while table[a] > 0:
                result[i] = a
                i += 1
                table[a] -= 1

        for a, num in enumerate(table):
            while num > 0:
                result[i] = a
                i += 1
                num -= 1

        return result
