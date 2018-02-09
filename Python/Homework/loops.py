for j in range(10): #Problem 1 - Just reads each range(10) 10 times. Hence the 0,1,etc 10 times.
	for i in range(10):
		print (i, end = " ") 
	print()
print()

i = 0
for j in range(10): #Problem 1 Version 2 - Built so it reads them vertically. In reality it reads 0, 10 times and so on.
	for k in range(10):
		print(i, end =" ")
	i = i + 1
	print()
print()

j = -1
for i in range(10): #Problem 2 - Adds a new number each new line
	for j in range(0, j + 2):
		print(j, end = " ")
	print()
print()

j = 10
for i in range(10): #Problem 3 - Reads one less number each time and adds a space for the missing number
	for k in range(i):
		print (" ", end = " ")
	for j in range(0, j):
		print(j, end = " ")
	print()
print()

j = 10
for i in range(10): #Problem 3 Version 2 - Reads one less number each time
	for j in range(0, j):
		print(j, end = " ")
	print()
print()

m = 10 #Starting range
j = 11 #Ending range
k = 9 #Starting Number
for i in range(9): #Problem 4
	for m in range(m,j): #M is the start range, J is the end range. They are variables so they can scale properly
		j = j + 1 #Increases the ending by 1
		k = k + 1 #Increases the set number to be printed
		print(k, end = " ")
	print()
print()


#Not much explained above since the professor gave away most of the Problem
#end = " " is a string function to add a space between characters instead of a new line each read through