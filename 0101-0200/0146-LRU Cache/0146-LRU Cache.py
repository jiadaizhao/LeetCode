class Node:
    def __init__(self, k, v):
        self.key = k
        self.val = v
        self.prev = None
        self.next = None

class LRUCache:
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.table = {}

    def get(self, key: int) -> int:
        if key not in self.table:
            return -1
        node = self.table[key]
        self._remove(node)
        self._add(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.table:
            node = self.table[key]
            self._remove(node)
            node.val = value
            self._add(node)
        else:            
            if self.capacity > 0 and len(self.table) == self.capacity:
                last = self.tail.prev
                del self.table[last.key]
                self._remove(last)
                
            node = Node(key, value)
            self._add(node)
            self.table[key] = node

    def _add(self, node):
        next = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = next
        next.prev = node

    def _remove(self, node):
        prev = node.prev
        prev.next = node.next
        node.next.prev = prev

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)