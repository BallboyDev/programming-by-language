class HousePark:
    lastname = "Park"
    def __init__(self, name):
        self.fullname = self.lastname + name
    def travel(self, where):
        print("%s, %s여행을 가다." %(self.fullname, where))
    def love(self, other):
        print("%s, %s 사랑에 빠졌네" %(self.fullname, other.fullname))
    def __add__(self, other):
        print("%s, %s결혼했네" % (self.fullname, other.fullname))
    def fight(self, other):
        print("%s, %s 싸우네" % (self.fullname, other.fullname))
    def __sub__(self, other):
        print("%s, %s 이혼했네" % (self.fullname, other.fullname))

class HouseKim(HousePark):
    lastname = "Kim"
    def travel(self, where, day):
        print("%s, %s여행을 %d일 가다." %(self.fullname, where, day))
