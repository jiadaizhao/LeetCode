from threading import Semaphore

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.zero_gate = Semaphore(1)
        self.even_gate = Semaphore(0)
        self.odd_gate = Semaphore(0)
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.zero_gate.acquire()
            printNumber(0)
            if i & 1:
                self.even_gate.release()
            else:
                self.odd_gate.release() 
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n + 1, 2):
            self.even_gate.acquire()
            printNumber(i)
            self.zero_gate.release()
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1, 2):
            self.odd_gate.acquire()
            printNumber(i)
            self.zero_gate.release()
