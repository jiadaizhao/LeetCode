class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        result = [0] * num_people
        curr = 1
        while candies > 0:
            for i in range(num_people):
                if candies >= curr + i:
                    result[i] += curr + i
                    candies -= curr + i
                else:
                    result[i] += candies
                    candies = 0
                    break
            curr += num_people

        return result


class Solution2:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        result = [0] * num_people
        curr = 0
        while candies > 0:
            result[curr % num_people] += min(candies, curr + 1)
            curr += 1
            candies -= curr

        return result
