import bisect
class SnapshotArray:
    
    def __init__(self, length: int):
        self.snap_id = 0
        self.arr = [[] for _ in range(length)]

    def set(self, index: int, val: int) -> None:
        while self.arr[index] and self.arr[index][-1][0] == self.snap_id:
            self.arr[index].pop()
        self.arr[index].append((self.snap_id, val))

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        target = bisect.bisect_left(self.arr[index], (snap_id + 1,)) - 1
        return 0 if target < 0 else self.arr[index][target][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
