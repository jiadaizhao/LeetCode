class UndergroundSystem:
    
    def __init__(self):
        self.inMap = {}
        self.outMap = {}
        

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.inMap[id] = (stationName, t)
        

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start = self.inMap[id][1]
        route = self.inMap[id][0] + '-' + stationName
        if route in self.outMap:
            time, count = self.outMap[route]
            self.outMap[route] = (time + t - start, count + 1)
        else:
            self.outMap[route] = (t - start, 1)
        

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        time, count = self.outMap[startStation + '-' + endStation]
        return time / count        


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
