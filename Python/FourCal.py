class FourCal:
    res = 0
    
    def __init__(self, first = 0, second = 0):
        self.first = first
        self.second = second
        FourCal.res = first
        
    def setdata(self, first, second):
        self.first = first
        self.second = second

    def sum(self):
        result = self.first + self.second
        FourCal.res = result
        return result

    def mul(self):
        result = self.first * self.second
        FourCal.res = result
        return result

    def sub(self):
        result = self.first - self.second
        FourCal.res = result
        return result

    def div(self):
        if self.second == 0:
            print("error")
            return None
        else:
            result = self.first / self.second
            FourCal.res = result
            return result
