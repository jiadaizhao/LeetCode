import collections
import bisect
class TimeMap:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.table = collections.defaultdict(list) 

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.table[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        keys = self.table.get(key, None)
        if keys is None:
            return ""
        i = bisect.bisect_right(keys, (timestamp, chr(127)))
        return keys[i - 1][1] if i else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
