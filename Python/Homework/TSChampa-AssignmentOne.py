#Problem One.....Temp Converter. 

F = int(input("Please enter the temperature in Fahrenheit: ")) #Input int() is there to make sure it isnt read as a string
E = ((5 / 9) * ( F - 32)) #the conversion just assigned to E no particular reason
print("The input is temperature: ", F , " The temperature now in celcius is:", E ) # The read out

#Problem Two......Area of a trapezoid

print("Enter the following figures to calculate the area of a trapezoid.") #Explanation to user
x1 = int(input("Length of the base: ")) #First input
x2 = int(input("Length of the top: ")) #second input
h = int(input("Height of the trapezoid: ")) #Third input
a = .5 * (x1 + x2) * h #calculation for the area of a trapezoid
print("The area of the trapezoid is: ", a) #Print out of the area