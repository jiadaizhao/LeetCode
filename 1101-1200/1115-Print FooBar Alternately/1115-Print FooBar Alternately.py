from threading import Semaphore

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_gate = Semaphore(1)
        self.bar_gate = Semaphore(0)

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.foo_gate.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.bar_gate.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.bar_gate.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.foo_gate.release()
