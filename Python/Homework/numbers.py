def TotalNumberAverage(NumberList): #Defines the function for total average
	NumListLen1 = len(NumberList) #Sets the length
	NumListLen2 = len(NumberList) #Sets an untouched length
	NumberListStart = 0 #Zeros the variables
	Total = 0           #
	while NumListLen1 > 0:  #Goes through the length
		Total = Total + NumberList[NumberListStart] #Adds up each number in the list
		NumberListStart = NumberListStart + 1 #Counts up
		NumListLen1 = NumListLen1 - 1 #Counts down
	Total = Total / NumListLen2 #Calculate the total average
	return Total #Returns the total


def PositiveNumberAverage(NumberList): #Defines the function for positive average
	NumListLen1 = len(NumberList) #Sets the length
	NumListLen2 = 0     #
	NumberListStart = 0 #Zeros the variables
	Total = 0           #
	while NumListLen1 > 0: #Goes through the length
		if NumberList[NumberListStart] > 0: #Checks to make sure its not 0 or negative
			Total = Total + NumberList[NumberListStart] #Adds to the total
			NumListLen2 = NumListLen2 + 1 #Adds up the amount of numbers added
		NumberListStart = NumberListStart + 1 #Counts up 
		NumListLen1 = NumListLen1 - 1 #Counts Down
	Total = Total / NumListLen2 #Calculate the positive average
	return Total #Returns the Total

def NegNZeroNumberAverage(NumberList):#Defines the function for negative and zero average
	NumListLen1 = len(NumberList) #Sets the length
	NumListLen2 = 0       #
	NumberListStart = 0   #Zeros the variables
	Total = 0             # 
	while NumListLen1 > 0: #Goes through the length
		if (NumberList[NumberListStart] <= 0) and NumberList[NumberListStart] > -9999: #Checks to make sure its below or at 0 and its not the limit
			Total = Total + NumberList[NumberListStart] #Adds to the total
			NumListLen2 = NumListLen2 + 1 #Adds up the amount of numbers added
		NumberListStart = NumberListStart + 1 #Counts up 
		NumListLen1 = NumListLen1 - 1 #Counts Down
	Total = Total / NumListLen2  #Calculate the positive average
	return Total #Returns the Total

Number = 0      #Declares the variables
NumberList = [] #
Limit = -9999 #Sets the limit
while Number > Limit: #While the input isnt -9999 its accepted
	Number = int(input("Enter a number(-9999 to end):")) #Takes the input
	if Number > Limit: #Makes sure the number is greater than the input
		NumberList.append(Number) #Adds the number to the list
Total = TotalNumberAverage(NumberList) #Sets the total average to a variable
PosTotal = PositiveNumberAverage(NumberList) #Sets the positive average to a variable
NegTotal = NegNZeroNumberAverage(NumberList) #Sets the negative average to a variable
print("Average Total:",Total,", Positive Total:",PosTotal,", Negative And Zero Total:",NegTotal) #Reads the averages