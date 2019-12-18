class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        parent = {r : p for p, *rr in regions for r in rr}        
        path = set([region1])
        while region1 in parent:
            region1 = parent[region1]
            path.add(region1)
        
        while region2 not in path:
            region2 = parent[region2]
        return region2
