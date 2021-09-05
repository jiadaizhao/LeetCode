class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        fc = [set(c) for c in favoriteCompanies]
        return [i for i, s1 in enumerate(fc) if all(i == j or not s1.issubset(s2) for j, s2 in enumerate(fc))]
