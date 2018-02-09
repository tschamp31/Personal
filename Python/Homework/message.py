def encrypt(key, message): #Defined function for encryption
	length = len(message) #Length of the given message in the input
	position = -1 #Starts the position counter at -1
	EncryptedMessage = "" #Declares the variable is a string
	while length > 0: #Run until the length of the message is at 0
		position = position + 1 #Starts the position at 0
		length = length - 1 #Reduces the length by 1
		if((ord(message[position])) + key > 126):                       #given code by the professor
			EncryptedChar = ((ord(message[position]) + key) - 127) + 32 #it processes to see if the message is within ascii range and balances it
		else:                                                           #to a proper number set if its not within the ascii number range
			EncryptedChar = ((ord(message[position])) + key)            #or if its in the range it continues to decrypt it
		EncryptedMessage = EncryptedMessage + chr(EncryptedChar)        #ord(message[position]) reads the ascii value of the letter that message[position] pulls up
	print(EncryptedMessage)                                             #chr(EncryptedChar) converts the integar to a letter. That line also builds the message by string
                                                                        #Addition 
def decrypt(message):         #Defines decrypt function
	for Key in range(101): #Runs it in the range of 0-100
		length = len(message) #Is within the for function otherwise the while function could not reach it
		position = -1         #these 3 are the same use as under the encrypt function
		DecryptedMessage = ""
		while length > 0: #Same as before
			position = position + 1 #same
			length = length - 1 #same
			if((ord(message[position])) - Key < 32):                        #given code by the professor
				DecryptedChar = ((ord(message[position]) - Key) + 127) - 32 #processes once again to make sure its within ASCII range
			else:
				DecryptedChar = ((ord(message[position])) - Key) #same
			DecryptedMessage = DecryptedMessage + chr(DecryptedChar) #Same
		print("Key ", Key,":", DecryptedMessage) #Reads as "Key number: message"



option = int(input("If you would like to encrypt a message type 1. If you would like to decrypt a message press 2: ")) #Takes the input for encryption or decryption

if option == 1: #If encryption it runs this route
	key = int(input("What key would you like to encrypt your message in? (1-100): ")) #gets the key input
	message = str(input("What was the message you wanted to encrypt: ")) #gets the message input
	encrypt(key,message) #runs the encrypt function
elif option == 2: #If decryption it runs this route
	message = str(input("What was the message you wanted to decrypt: ")) #gets the message input
	decrypt(message) #Runs the decrypt function
else: 
	print("Incorrect Input, Run Again") #Here for if someone doesnt press 1 or 2. As in I guess you could say an error.