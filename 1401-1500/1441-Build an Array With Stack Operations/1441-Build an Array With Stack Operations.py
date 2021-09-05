class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        result = []
        curr = 1
        for i in target:
            while i > curr:
                result.extend(["Push", "Pop"])
                curr += 1
            result.append("Push")
            curr += 1
            
        return result
