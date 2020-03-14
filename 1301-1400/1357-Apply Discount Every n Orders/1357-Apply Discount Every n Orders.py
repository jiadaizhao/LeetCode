class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.priceTable = {id : price for id, price in zip(products, prices)}
        self.curr = 0
        self.target = n
        self.discount = discount

    def getBill(self, product: List[int], amount: List[int]) -> float:
        total = sum(self.priceTable[id] * a for id, a in zip(product, amount))
        self.curr += 1
        if self.curr == self.target:
            self.curr = 0
            total *= 1 - self.discount / 100
        return total


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
