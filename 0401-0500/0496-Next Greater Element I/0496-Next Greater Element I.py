class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        St = []
        table = {}
        for num in nums2:
            while St and St[-1] < num:
                table[St.pop()] = num
            St.append(num)
            
        return [table[num] if num in table else -1 for num in nums1]
