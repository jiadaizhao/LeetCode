class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        low = total = 0
        high = len(people) - 1
        while low <= high:
            total += 1
            if people[low] + people[high] <= limit:
                low += 1
            high -= 1
        return total
