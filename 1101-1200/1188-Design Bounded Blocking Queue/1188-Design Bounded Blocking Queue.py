from threading import Condition
import collections
class BoundedBlockingQueue(object):

    def __init__(self, capacity: int):
        self.cap = capacity
        self.queue = collections.deque()
        self.cond = Condition()

    def enqueue(self, element: int) -> None:
        self.cond.acquire()
        while len(self.queue) == self.cap:
            self.cond.wait()
        self.queue.append(element)
        self.cond.notify()
        self.cond.release()

    def dequeue(self) -> int:
        self.cond.acquire()
        while not self.queue:
            self.cond.wait()
        element = self.queue.popleft()
        self.cond.notify()
        self.cond.release()
        return element

    def size(self) -> int:
        return len(self.queue)


class BoundedBlockingQueue(object):

    def __init__(self, capacity: int):
        self.cap = capacity
        self.queue = collections.deque()
        self.cond = Condition()

    def enqueue(self, element: int) -> None:
        with self.cond:
            while len(self.queue) == self.cap:
                self.cond.wait()
            self.queue.append(element)
            self.cond.notify()


    def dequeue(self) -> int:
        with self.cond:
            while not self.queue:
                self.cond.wait()
            element = self.queue.popleft()
            self.cond.notify()

        return element

    def size(self) -> int:
        return len(self.queue)
