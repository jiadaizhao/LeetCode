class Solution:
    def minOperations(self, logs: List[str]) -> int:
        op = 0
        for log in logs:
            if log == "../":
                if op > 0:
                    op -= 1
            elif log != "./":
                op += 1
        return op
