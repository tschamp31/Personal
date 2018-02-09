class Rectangle:
		def __init__(self,initx,inity,initw,inith): #Function for initial declaration of variables within the class
			self.x = initx
			self.y = inity
			self.w = initw
			self.h = inith

		def __str__(self): #converts the class into a string output as its default output
			return "Rectangle("+str(self.x)+","+str(self.y)+","+str(self.w)+","+str(self.h)+")"

		def right(self): #Finds the right corner
			right = self.x + self.w
			print(right)

		def bottom(self): #Finds the bottom corner
			bottom = self.y + self.h
			print(bottom)

		def size(self): #Reads out the size
			print("("+str(self.w)+","+str(self.h)+")")

		def position(self): #Reads out the position of the rectangle
			print("("+str(self.x)+","+str(self.y)+")")

		def area(self): #Displays the area within the rectangle
			area = self.w * self.h
			print(area)

		def expand(self,offset): #expands the rectangle on each direction
			self.x = self.x - offset
			self.y = self.y - offset
			self.w = self.w + (offset * 2)
			self.h = self.h + (offset * 2)
			print("Rectangle("+str(self.x)+","+str(self.y)+","+str(self.w)+","+str(self.h)+")")

		def contains_point(self,x,y): #Checks to see if the points given are within the rectangle
			xposition = False
			yposition = False
			if self.x <= x and x <= self.w:
				xposition = True
			if self.y <= y and y <= self.h:
				yposition = True
			if xposition and yposition:
				print("True")
			else:
				print("False")



r = Rectangle(30,40,100,110) #Applies the class to a variable
print(r) #Prints the class
r.right()   #All below call upon the functions
r.bottom()
r.size()
r.position()
r.area()
r.expand(offset=3)
r.contains_point(100,110)