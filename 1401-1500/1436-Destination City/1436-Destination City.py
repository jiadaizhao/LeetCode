class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        source = set()
        for s, d in paths:
            source.add(s)
        for s, d in paths:
            if d not in source:
                return d
