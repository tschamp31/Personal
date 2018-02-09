#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Cards //Declares Card Class
{
private:
        vector<string> deck;
public:
        vector<string> create(vector<string> deck); //Declares function
        vector<string> shuffle(vector<string> deck);//Declares function
        vector<string> draw(vector<string> deck);//Declares function
        string drawM(vector<string> deck);//Declares function
        void print(vector<string> deck);//Declares function
};

void EmpiricalProbability();//Declares function
vector<string> split(string &str, const char &delim);//Declares function

vector<string> Cards::create(vector<string> deck)//Incharge of deleting/creating a new deck. 
{
        deck.erase(deck.begin(),deck.end());//Erases old deck if it exists
        vector<string> newdeck(52);//declares a deck size of 52
        int x,i,z;//declares variables
        z = 0;//declares variables
        string value, suite;//declares variables

        for(x = 1; x <= 4; x++)//Runs through 4 suits
        {
                switch(x)//Applies suit based on if it laid 13 cards
                {
                        case 1:
                                suite = "Spades";
                                break;
                        case 2:
                                suite = "Diamonds";
                                break;
                        case 3:
                                suite = "Clubs";
                                break;
                        case 4:
                                suite = "Hearts";
                                break;
                }
                for(i = 1; i <= 13; i++)//Lays out 13 cards
                {
                        switch(i)
                        {
                                case 1:
                                        value = "Ace";
                                        break;
                                case 2:
                                        value = "Two";
                                        break;
                                case 3:
                                        value = "Three";
                                        break;
                                case 4:
                                        value = "Four";
                                        break;
                                case 5:
                                        value = "Five";
                                        break;
                                case 6:
                                        value = "Six";
                                        break;
                                case 7:
                                        value = "Seven";
                                        break;
                                case 8:
                                        value = "Eight";
                                        break;
                                case 9:
                                        value = "Nine";
                                        break;
                                case 10:
                                        value = "Ten";
                                        break;
                                case 11:
                                        value = "Jack";
                                        break;
                                case 12:
                                        value = "Queen";
                                        break;
                                case 13:
                                        value = "King";
                                        break;
                        }
                        newdeck[z] = value + " of " + suite;//Takes in the string pieces and puts it into a vector
                        z++;
                }
        }
        return newdeck;//Returns the deck
}

vector<string> Cards::shuffle(vector<string> deck)//Shuffles the deck
{
        int i, x, times, max;//declares variables
        string temp, temp2;//declares variables
        times = rand() % 10;//Random number of times it shuffles. Makes it a little less predictable
        for(times; times > 0; times--) //Runs it for the amount of times
        {
                i = deck.size() - 1;//Sets the card count needs to be shuffled
                max = deck.size() - 1; //Max for the random number generator to not exceed.
                while(i >= 0)//Runs through the 52 cards
                {
                        x = rand() % max; //random position
                        temp = deck[i]; //Swaps the card
                        deck[i] = deck[x];//Swaps the card
                        deck[x] = temp;//Swaps the card
                        i--;//Lowers the card count that needs to be shuffled
                }
        }
        return deck;//Returns the deck
}

vector<string> Cards::draw(vector<string> deck)//Draws a card
{
        int size;//declares variables
        size = deck.size() - 1;//Sets the size of the current dec
        cout << "You drew: " << deck[size] << endl;// Reads out the card in the deck
        cout << endl;
        deck.erase(deck.end());//removes the card
        return deck;//Returns the new deck

}

string Cards::drawM(vector<string> deck)//Draw memory instead of displaying the card that was drew
{
        string card;
        int size;//declares variables
        size = deck.size() - 1;//declares the size
        card = deck[size];
        deck.erase(deck.end());
        return card;//Returns the card drew off the top of the deck

}

void Cards::print(vector<string> deck)//Prints the deck
{
        int decksize;//declares variables
        decksize = deck.size() - 1;//Declares the deck size
        while(decksize >= 0)//Reads through the cards in the deck
        {
                cout << deck[decksize] << endl;
                decksize--;
        }
}

void EmpiricalProbability()//Function name expalins itself
{
        Cards card;//declares variables
        int i,x,s,c,size,success;//declares variables
        size_t pos = 0;//declares variables
        i = 0;//declares variables
        x = 0;//declares variables
        success = 0;//declares variables
        s = 0;//declares variables
        string processor, suite, value, output, delimiter, input, token;//declares variables
        vector<string> inputoptions(6);//declares variables
        vector<string> comparestring(6);//declares variables
        delimiter = " ";//declares variables

        cout << "Input the 5 cards you want to check the Probability of. (Format: AH 10D): " << endl; //asks for input
        cin.ignore(); //Closes of the cin stream input (causes infinite loop if not done)
        getline( cin , input ); //Takes in the current line
        input = input + " "; //Adds an extra space to the end so that the spliter does not ignore the last card

        while ((pos = input.find(delimiter)) != std::string::npos) //Cuts up the string into the vector for processing. Removes " "
        {
            token = input.substr(0, pos);
            inputoptions[i] = token;
            input.erase(0, pos + delimiter.length());
            i++;
        }

        while(i>= 0) //Converts the acronyms to readable text
        {
                processor = inputoptions[i]; //Sets the position of the vector to a current string
                if(processor.size() == 3) s = 2;//For 10D
                else if(processor.size() == 2) s = 1;//For any other card combo cept 10D
                switch(processor[s])//Decodes the acronyms
                {
                        case 'S':
                                suite = "Spades";
                                break;
                        case 'D':
                                suite = "Diamonds";
                                break;
                        case 'C':
                                suite = "Clubs";
                                break;
                        case 'H':
                                suite = "Hearts";
                                break;
                }
                if(s == 1)
                {
                        switch(processor[0])
                        {
                                        case 'A':
                                                value = "Ace";
                                                break;
                                        case '2':
                                                value = "Two";
                                                break;
                                        case '3':
                                                value = "Three";
                                                break;
                                        case '4':
                                                value = "Four";
                                                break;
                                        case '5':
                                                value = "Five";
                                                break;
                                        case '6':
                                                value = "Six";
                                                break;
                                        case '7':
                                                value = "Seven";
                                                break;
                                        case '8':
                                                value = "Eight";
                                                break;
                                        case '9':
                                                value = "Nine";
                                                break;
                                        case 'J':
                                                value = "Jack";
                                                break;
                                        case 'Q':
                                                value = "Queen";
                                                break;
                                        case 'K':
                                                value = "King";
                                                break;
                        }
                }
                else if(s == 2)
                {
                        value = "Ten";
                }
                x++;
                i--;
                comparestring[x] = value + " of " + suite; //Turns the acronym into a string spot on the vector
        }
        for(c = 0; c < 1000; c++) //Runs 1000 trials
        {
                vector<string> deck(0);//declares variables
                size = 52;//declares variables
                deck.resize(size); //Makes sure the deck is 52 cards
                deck = card.create(deck); //Creates a new deck for each trial
                deck = card.shuffle(deck);//Shuffles the deck once
                for(i = 0; i < 5; i++)//Draws 5 cards
                {
                        for(s = 2; s < 7; s++)//Checks all 5 cards
                        {
                                output = card.drawM(deck);//Sets draw card to memory
                                if(comparestring[s].compare(output) == 0)//Compares the strings
                                {
                                        success++;//If they match counter goes up
                                }
                        }
                }
                deck.clear();//Errases the deck and restarts.

        }
        cout << success << "/1000" << endl;//Reads out the probability
}

void Menu() // Just the setup for the visual menu
{
        Cards card;//declares variables
        int answer, size;//declares variables
        vector<string> deck(0);//declares variables
        answer = 0;//declares the variables

        while(answer != 6) // keeps checking for the answer to the menu function
        {
                cout << "1)      Create/reset the deck." << endl
                << "2)      Shuffle the deck." << endl
                << "3)      Draw a card." << endl
                << "4)      Display Deck." << endl
                << "5)      Calculate Empirical Probability." << endl
                << "6)      Quit." << endl
                << "Input: ";
                cin >> answer; // Takes in the input
                        switch(answer) //Answer then is split up
                        {
                                case 1:
                                        cout << endl;
                                        size = 52; //Sets deck size
                                        deck.resize(size); //Makes sure the deck is now at 52 cards again
                                        deck = card.create(deck); //Sets the new deck
                                        cout << "Deck was created/reset." << endl;
                                        break;

                                case 2:
                                        cout << endl;
                                        if(deck.empty())//Error if there is no deck to manipulate.
                                        {
                                                cout << "There are no cards to process. Please created a deck." << endl;
                                                cout << endl;
                                                break;
                                        }
                                        cout << "Deck is shuffled." <<endl;
                                        deck = card.shuffle(deck);//Shuffles the deck
                                        break;
                                case 3:
                                        cout << endl;
                                        if(deck.empty())//Error if there is no deck to manipulate.
                                        {
                                                cout << "There are no cards to process. Please created a deck." << endl;
                                                cout << endl;
                                                break;
                                        }
                                        deck = card.draw(deck);//Sets the new deck after the card was drew
                                        deck.resize(size - 1);//Resizes the deck to be one less on this side of the code
                                        size--;//Lowers the size 
                                        break;
                                case 4:
                                        cout << endl;
                                        if(deck.empty())//Error if there is no deck to manipulate.
                                        {
                                                cout << "There are no cards to process. Please created a deck." << endl;
                                                cout << endl;
                                                break;
                                        }
                                        card.print(deck);//Prints out the current deck.
                                        break;
                                case 5:
                                        cout << endl;
                                        EmpiricalProbability();//Does the empirical probability function.
                                        break;
                                case 6:
                                        exit(0); //Quit option on the menu
                                        break;
                                default:
                                        cout << endl;
                                        cout << answer << " Is not a correct input." << endl;// Fail safe if an incorrect input was given (number wise).
                                        cout << endl;
                                        break;
                        }
        }
}

int main()
{
        Menu();
        return 0;
}