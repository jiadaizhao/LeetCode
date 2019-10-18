from threading import Semaphore, Lock
class DiningPhilosophers:

    def __init__(self):
        self.sem = Semaphore(4)
        self.locks = [Lock() for _ in range(5)]

    def pickFork(self, id, fun):
        self.locks[id].acquire()
        fun()

    def putFork(self, id, fun):        
        fun()
        self.locks[id].release()
    
    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        
        left = philosopher
        right = (philosopher + 4) % 5
        self.sem.acquire()
        self.pickFork(left, pickLeftFork)
        self.pickFork(right, pickRightFork)
        eat()
        self.putFork(right, putRightFork)
        self.putFork(left, putLeftFork)
        self.sem.release()
