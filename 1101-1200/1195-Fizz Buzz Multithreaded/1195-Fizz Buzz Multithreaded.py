from threading import Semaphore

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.curr = 1
        self.fs = Semaphore(0)
        self.bs = Semaphore(0)
        self.fbs = Semaphore(0)
        self.ns = Semaphore(1)

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
    	for i in range(1, self.n + 1):
            if i % 3 == 0 and i % 5:
                self.fs.acquire()
                printFizz()
                self.curr += 1
                if self.curr % 5 == 0:
                    self.bs.release()
                else:
                    self.ns.release()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for i in range(1, self.n + 1):
            if i % 5 == 0 and i % 3:
                self.bs.acquire()
                printBuzz()
                self.curr += 1
                if self.curr % 3 == 0:
                    self.fs.release()
                else:
                    self.ns.release()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for i in range(1, self.n + 1):
            if i % 3 == 0 and i % 5 == 0:
                self.fbs.acquire()
                printFizzBuzz()
                self.curr += 1
                self.ns.release()
		

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1):
            if i % 3 and i % 5:
                self.ns.acquire()
                printNumber(i)
                self.curr += 1
                if self.curr % 3 == 0 and self.curr % 5 == 0:
                    self.fbs.release()
                elif self.curr % 3 == 0:
                    self.fs.release()
                elif self.curr % 5 == 0:
                    self.bs.release()
                else:
                    self.ns.release()
