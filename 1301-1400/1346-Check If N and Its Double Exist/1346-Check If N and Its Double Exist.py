class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        table = set()
        for a in arr:
            if a * 2 in table or a / 2 in table:
                return True
            table.add(a)
        return False
