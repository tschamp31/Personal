import turtle
wn = turtle.Screen()
wn.bgcolor("black")

rectangle = turtle.Turtle()
rectangle.color("white")
rectangle.pensize(3)
rectangle.pen(shown=False)



class Rectangle:
		def __init__(self,initx,inity,initw,inith):
			self.x = initx
			self.y = inity
			self.w = initw
			self.h = inith

		def __str__(self):
			return "Rectangle("+str(self.x)+","+str(self.y)+","+str(self.w)+","+str(self.h)+")"

		def LRS(self):
			W = self.w
			X = self.x
			while W > X:
				rectangle.forward(1)
				W = W - 1
			right = self.x + self.w
			print(right)

		def TBS(self):
			H = self.h
			Y = self.y
			while H > Y:
				rectangle.forward(1)
				H = H - 1
			bottom = self.y + self.h
			print(bottom)

		def size(self):
			print("("+str(self.w)+","+str(self.h)+")")

		def position(self):
			print("("+str(self.x)+","+str(self.y)+")")

		def area(self):
			area = self.w * self.h
			print(area)

		def expand(self,offset):
			self.x = self.x - offset
			self.y = self.y - offset
			self.w = self.w + (offset * 2)
			self.h = self.h + (offset * 2)
			print("Rectangle("+str(self.x)+","+str(self.y)+","+str(self.w)+","+str(self.h)+")")
			return self.x, self.y, self.w, self.h

		def contains_point(self,x,y):
			xposition = False
			yposition = False
			if self.x < x and x < self.w:
				xposition = True
			if self.y < y and y < self.h:
				yposition = True
			if xposition and yposition:
				print("True")
			else:
				print("False")



r = Rectangle(30,40,100,110)
print(r)
r.TBS()
rectangle.left(90)
r.LRS()
rectangle.left(90)
r.TBS()
rectangle.left(90)
r.LRS()
# r.size()
# r.position()
# r.area()
r.expand(offset=3)
r.TBS()
rectangle.left(90)
r.LRS()
rectangle.left(90)
r.TBS()
rectangle.left(90)
r.LRS()
# r.contains_point(0,0)

wn.exitonclick()