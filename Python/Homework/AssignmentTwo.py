import turtle
wn = turtle.Screen()
wn.bgcolor("blue")
######## Declaration of Items for drawing #########
snowman = turtle.Turtle()
snowman.color("black")
snowman.pensize(3)

buttons = turtle.Turtle()
buttons.shape("circle")
buttons.color("black")

arms = turtle.Turtle()
arms.color("brown")
arms.pensize(3)

mouth = turtle.Turtle()
mouth.color("black")
mouth.pensize(2)

nose = turtle.Turtle()
nose.color("orange")
nose.pensize(5)

hat = turtle.Turtle()
hat.color("black")
hat.pensize(5)
###################################################
turtle.tracer(0) #Used to instantly draw the objects. Since drawing these circles take forever.

################ Body #############################
snowman.pen(shown=False) #removes the ugly arrow that would mess up the picture
snowman.begin_fill()  #Used to make the inside of the circle white
for size in range(360):     #Bottom Circle
    snowman.forward(1.7)          
    snowman.right(1)              
    snowman.fillcolor("white")

for size in range(540):      #Middle Circle
    snowman.forward(1.4)       
    snowman.left(1)            
    snowman.fillcolor("white")

for size in range(360):     #Top Circle
    snowman.forward(0.8)          
    snowman.right(1)           
    snowman.fillcolor("white")
snowman.end_fill() #Ends the filling process. So that the other objects drawn would not have a fill effect. (Though they would need to be pointed towards filling)
###################################################

################ Buttons & Eyes ###################
buttons.penup() #Lifts up the pen so it doesnt draws
buttons.left(90) #Next two lines are to get my turtle in position
buttons.forward(10)
for size in range(3):     #Draws the 3 buttons on the torso
    buttons.forward(40)                     
    buttons.stamp()

buttons.forward(90) #Lines are used to make the eyes did not want to waste code lines to create an eye turtle
buttons.left(90)    #  |
buttons.forward(20) #  |
buttons.stamp()     #  |
buttons.forward(-40)#  |
buttons.stamp()     # \|/
####################################################

################ Mouth #############################
mouth.pen(shown=False) #Removes ugly turtle
mouth.penup() #lifts pen
mouth.setpos(30,200) #sets the turtles positions instead of making commands to put the turtle at the location I want it.
mouth.pendown() #sets pen
mouth.left(-90) #Flips the orientation of the turtle
for size in range(180):     #Draws the smile a half circle
    mouth.forward(0.5)          
    mouth.right(1)      
####################################################

################ Nose ##############################
nose.pen(shown=False) #Removes ugly turtle
nose.penup() #lifts pen
nose.setpos(-9,190) #sets position of turtle
nose.pendown() #sets pen
nose.right(180) #flips the orientation of the turtle
nose.begin_fill()
for size in range(3): #Draws the nose
	nose.right(120)
	nose.forward(20)
	nose.fillcolor("orange")
nose.end_fill()
####################################################

################ Arms ##############################
arms.pen(shown=False) #Removes ugly turtle
arms.penup() #lifts pen
arms.setpos(-80.00,90.00) #sets position of turtle
arms.pendown() #sets pen
arms.left(160) #flips the orientation of the turtle
arms.forward(50) #Draws the left arm \/
arms.right(20)

for times in range(3):
	arms.forward(40)
	arms.forward(-40)
	arms.right(-20)

arms.penup() #lifts pen
arms.setpos(80.00,90.00) #sets position of turtle
arms.pendown() #sets pen
arms.left(180) #flips the orientation of the turtle
arms.forward(50) #Draws the right arm \/
arms.right(20)

for times in range(3):
	arms.forward(40)
	arms.forward(-40)
	arms.right(-20)
####################################################

####################### Hat ########################
hat.pen(shown=False)#Removes ugly turtle
hat.penup()#lifts pen
hat.setpos(0,240)#sets position of turtle
hat.pendown()#sets pen
hat.forward(70)#Builds brim of the hat
hat.forward(-30)
hat.begin_fill()
for dimensions in (50,80,50,40): #builds the hat
	hat.left(90)
	hat.forward(dimensions)
	hat.fillcolor("black")
hat.end_fill()
hat.forward(-70)#finish brim of the hat

####################################################
turtle.update() 
turtle.tracer(1) 

measure = turtle.Turtle()
measure.color("black")
measure.pensize(3)

measure.left(-90)
measure.forward(200)

wn.exitonclick()
