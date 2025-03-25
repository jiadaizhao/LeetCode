class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxes = sorted(boxTypes, key=lambda x:x[1], reverse=True)
        result = 0
        for num, unit in boxes:
            count = min(truckSize, num)
            result += unit * count
            truckSize -= count
            if truckSize == 0:
                break
        return result
