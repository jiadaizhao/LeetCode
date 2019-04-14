class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        used = 0
        def dfs(used, curr, target):
            if used == 15:
                return abs(curr - target) < 0.001
            for bit in range(4):
                mask = 1 << bit
                if (used & mask) == 0:
                    used |= mask
                    if (dfs(used, curr + nums[bit], target) or dfs(used, curr - nums[bit], target) or
                        dfs(used, nums[bit] - curr, target) or dfs(used, curr*nums[bit], target) or
                        dfs(used, curr / nums[bit], target)):
                        return True
                    if (dfs(used, nums[bit], target - curr) or dfs(used, nums[bit], curr - target) or
                        dfs(used, nums[bit], target + curr)):
                        return True
                    if curr != 0 and (dfs(used, nums[bit], target/curr) or dfs(used, nums[bit], target*curr)):
                        return True
                    if target != 0 and curr != 0 and dfs(used, nums[bit], curr/target):
                        return True                    
                    used &= ~mask
            return False
        
        return any(dfs(1 << bit, nums[bit], 24) for bit in range(4))
