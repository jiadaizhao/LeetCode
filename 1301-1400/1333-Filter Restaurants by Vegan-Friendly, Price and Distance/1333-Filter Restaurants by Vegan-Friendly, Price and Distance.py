class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        candidates = []
        for id, rating, vf, price, distance in restaurants:
            if (veganFriendly == 0 or vf == 1) and price <= maxPrice and distance <= maxDistance:
                candidates.append([rating, id])
        candidates.sort(reverse=True)
        return list(zip(*candidates))[1] if candidates else []
