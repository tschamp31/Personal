import random
class Monsters():
    def __init__(self, Health, Midigation, Damage, Speed, Value):
        self.h = Health
        self.m = Midigation
        self.d = Damage
        self.s = Speed
        self.v = Value
    def __str__(self):
    	return "("+str(self.h)+","+str(self.m)+","+str(self.d)+","+str(self.s)+","+str(self.v)+")"
    def Flyer():
        return Monsters(100,0,200,30,20)
    def Runner():
        return Monsters(50,0,100,90,20)
    def Tank():
        return Monsters(500,10,200,20,50)
    def Boss():
        return Monsters(1000,50,200,20,200)
    def Normal():
        return Monsters(100,0,300,30,20)

#Boss 5% 1-5, Normal 30% 5-35, Flyer 30% 35-65, Runner 20% 65-85, Tank 15% 85-100

def MonsterSpawn():
	WaveAmount = 100
	BossC = 0
	NormalC = 0
	FlyerC = 0
	RunnerC = 0
	TankC = 0
	while WaveAmount >= 0:
		x = random.randint(1,100)
		if 1 < x and x < 5:
			BossC += 1
		if 5 < x and x < 35:
			NormalC += 1
		if 35 < x and x < 65:
			FlyerC += 1
		if 65 < x and x < 85:
			RunnerC += 1
		if 85 < x and x < 100:
			TankC += 1
		WaveAmount -= 1
	WaveAmount = 100
	while WaveAmount >= 0:
		c = random.randint(1,5)
		if c == 1 and BossC > 0:
			BossC -= 1
			print (Monsters.Boss())
		if c == 2 and NormalC > 0:
			NormalC -= 1
			print (Monsters.Normal())
		if c == 3 and FlyerC > 0:
			FlyerC -= 1
			print (Monsters.Flyer())
		if c == 4 and RunnerC > 0:
			RunnerC -= 1
			print (Monsters.Runner())
		if c == 5 and TankC > 0:
			TankC -= 1
			print (Monsters.Tank())
	print (BossC)
	print (NormalC)
	print (FlyerC)
	print (RunnerC)
	print (TankC)
MonsterSpawn()