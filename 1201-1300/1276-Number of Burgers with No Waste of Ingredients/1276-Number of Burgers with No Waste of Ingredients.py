class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        if (tomatoSlices < cheeseSlices * 2  or
            (tomatoSlices & 1) or tomatoSlices > cheeseSlices * 4):
            return []
        '''
        4 * x  + 2 * y = t
        x + y = c
        '''
        x = tomatoSlices // 2  - cheeseSlices
        y = cheeseSlices * 2 - tomatoSlices // 2
        return [x, y]
