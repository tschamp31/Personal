def find_longest_word(List): #defines the function
	InternalList = List #Creates an internal variable within the function
	ListLen = len(InternalList) #Gets the length
	Location = 0      #Sets the variables up
	WordLength = 0    #
	while ListLen > 0: #Runs the function until the length is at 0
		NewWordLength = len(InternalList[Location]) #Sets the length of the word in the position to a variable
		if NewWordLength > WordLength: #Checks against the old "record" word length. 
			WordLength = NewWordLength            #If the new word length is larger it will set it
			LongestWord = InternalList[Location] #Sets the longest word based on the location
		ListLen = ListLen - 1     #Counts down
		Location = Location + 1   #Counts up
	return LongestWord #Returns the longest word

InputString = input("Enter a sentence or list to find the longest word:") #Input for the sentence
List = InputString.split() #Splits up the sentence into a list
Word = find_longest_word(List) #Output of the function is set to a word
print("\n","The longest word in the section is:", Word) #It reads off the word.

