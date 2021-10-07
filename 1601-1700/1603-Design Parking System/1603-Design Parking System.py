class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.nums = [None, big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.nums[carType] > 0:
            self.nums[carType] -= 1
            return True
        return False


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
