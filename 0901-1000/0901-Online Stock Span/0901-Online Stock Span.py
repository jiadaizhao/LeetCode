class StockSpanner:
    
    def __init__(self):
        self.St = []

    def next(self, price: int) -> int:
        num = 1
        while self.St and price >= self.St[-1][0]:
            num += self.St.pop()[1]
        self.St.append((price, num))
        return num


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
