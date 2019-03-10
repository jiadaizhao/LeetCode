class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        end1 = m - 1
        end2 = n - 1
        end = m + n - 1
        while end2 >= 0:
            if end1 < 0 or nums1[end1] <= nums2[end2]:
                nums1[end] = nums2[end2]
                end2 -= 1
            else:
                nums1[end] = nums1[end1]
                end1 -= 1
            end -= 1
