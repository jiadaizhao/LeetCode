class Solution:
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        start, end = 0, len(people) - 1
        total = 0
        while start <= end:
            total += 1
            if people[start] + people[end] <= limit:
                start += 1
            end -= 1
        return total
