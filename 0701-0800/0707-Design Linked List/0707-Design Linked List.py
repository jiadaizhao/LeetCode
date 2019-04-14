class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

        
class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = self.tail = None
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index < 0:
            return -1
        p = self.head
        for _ in range(index):
            if p is None:
                return -1
            p = p.next
        return p.val if p else -1
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        node = ListNode(val)
        if self.tail is None:
            self.tail = node
        node.next = self.head
        self.head = node

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        node = ListNode(val)
        if self.tail is None:
            self.head = node
        else:
            self.tail.next = node
            
        self.tail = node

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index < 0:
            return
        if index == 0:
            self.addAtHead(val)
        else:
            prev = self.head
            for _ in range(index - 1):
                if prev is None:
                    return
                prev = prev.next
            if prev is None:
                return
            node = ListNode(val)
            next = prev.next
            prev.next = node
            if next is None:
                self.tail = node
            else:
                node.next = next


    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0:
            return
        if index == 0:
            if self.head is None:
                return
            self.head = self.head.next
            if self.head is None:
                self.tail = None
        else:
            prev = self.head
            for _ in range(index - 1):
                if prev is None:
                    return
                prev = prev.next
            if prev is None or prev.next is None:
                return
            next = prev.next
            prev.next = next.next
            if self.tail == next:
                self.tail = prev


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
