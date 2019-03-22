class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        
        result = [0]*len(nums)
        index = [i for i in range(len(nums))]
        temp = [0]*len(nums)
        def mergeSort(start, end):
            if start < end:
                mid = (start + end) // 2
                mergeSort(start, mid)
                mergeSort(mid + 1, end)
                i = k = start
                j = mid + 1
                count = 0
                while i <= mid:
                    while j <= end and nums[index[j]] < nums[index[i]]:
                        count += 1
                        temp[k] = index[j]
                        k += 1
                        j += 1
                    result[index[i]] += count
                    temp[k] = index[i]
                    k += 1
                    i += 1
                    
                while j <= end:
                    temp[k] = index[j]
                    k += 1
                    j += 1
                
                index[start:end + 1] = temp[start:end + 1]
                
        mergeSort(0, len(nums) - 1)
        return result


class Node:
    
    def __init__(self, v):
        self.left = None
        self.right = None
        self.val = v
        self.leftCount = 0
        self.dup = 1

class Solution2:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        
        def insert(root, index, presum):
            if root is None:
                root = Node(nums[index])
                result[index] = presum
            elif root.val == nums[index]:
                root.dup += 1
                result[index] = presum + root.leftCount
            elif root.val > nums[index]:
                root.leftCount += 1
                root.left = insert(root.left, index, presum)
            else:
                root.right = insert(root.right, index, presum + root.leftCount + root.dup)
            return root
        root = None
        result = [0] * len(nums)
        for i in range(len(nums) - 1, -1, -1):
            root = insert(root, i, 0)
        return result
