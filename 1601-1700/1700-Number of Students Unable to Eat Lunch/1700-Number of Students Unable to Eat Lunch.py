import collections
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        table = collections.Counter(students)
        count = len(students)
        for s in sandwiches:
            if table[s] > 0:
                table[s] -= 1
                count -= 1
            else:
                break
        return count
