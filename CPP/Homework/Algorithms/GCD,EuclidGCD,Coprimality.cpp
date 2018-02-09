#include <iostream>
#include <vector>

int GCD(int a, int b, int amount); //declares the functions
int EuclidGCD(int a, int b);//declares the functions
int coprimality(vector<int> numberseries, int amount);//declares the functions
vector<int> congruence(int classs,int modulo, int cutoff);//declares the functions
int CRT(vector<int> moduli,vector<int> remainders,int amount);//declares the functions
void Menu();//declares the functions


int main()
{
Menu(); //runs the menu
return 0;
}


vector<int> congruence(int classs,int modulo, int cutoff)
{
        vector<int> answer(1); //declares the vector
        int i, counter; //declares the variables
        for(i = classs, counter = 0; i <= cutoff; i+=modulo, counter++)
        {
                answer[counter] = i; //puts the number in the vector
                answer.resize(counter+2); //dynamically sizes the vector
        }
        return answer; //returns the vector
}

int GCD(int a, int b, int amount)
{
        int c, i;//declares the variables
        i = 0;//declares the variables

        for (i = 0; i < amount; i++)
        {
                c = EuclidGCD(a, b); //runs the gcd through
        }
        return c; // returns the gcd
}

int EuclidGCD(int a, int b)
{
        int gcd;// Declares the variable(s)
        while(b) //While the variable is unchanged
        {
                gcd = a; //Sets a to the GCD
                a = b; // Sets b as the new A
                b = gcd % b; //B is set as the remainder of B
        }
        return a < 0 ? -a : a; //Returns A as an absolute
}

int coprimality(vector<int> numberseries,int amount)
{
        vector<int> results;//declares the variables
        int coprimality, a, b;//declares the variables

        while(!(a ==amount-1)) //checkes each combinations of numbers without repeating them to check if they are coprime
        {
                for(a = 0; a < amount - 1; a++)
                {
                        for(b = a + 1; b <= amount - 1; b++)
                        {
                                if(GCD(numberseries[a],numberseries[b], amount) > 1) //if any of the combinations end up largers than 1 it sets the coprimality to 0
                                {
                                        return 0;
                                }
                        }
                }
        }
}

int CRT(vector<int> moduli,vector<int> remainders,int amount)
{
        int result, answer, i, m, found, coef;//declares the variables
        vector<int> x(amount);//declares the variables
        result = coprimality(moduli, amount); //Checks whther the input is coprime or not
        found = 0;//declares the variables
        answer = 0;//declares the variables
        switch(result) //Decides what to do based on if its coprime or not
        {
                case 0:
                        cout << "The moduli entered is not coprime." << endl;
                        break;
                case 1:
                        for(m = 0; m < amount; m++)
                        {
                                coef = remainders[m]%moduli[m]; // creates is so that when the remainder is found it equals to a moduli of 1

                                while (found == 0) //runs it until it finds a match
                                    {
                                        i++;
                                        if ((coef * i)%moduli[m] == 1) //keeps checking the number series
                                        {
                                             found = 1; // sets it found ending the while
                                        }
                                    }
                        }
                        answer = i;
                        break;

        }
        return answer;
}


void Menu() // Just the setup for the visual menu
{
        int answer, classs, modulo, cutoff, i, amount, result;//declares the variables
        vector<int> results, inputvect(100),inputvect2(100);//declares the variables
        answer = 0;//declares the variables

        while(answer != 4) // keeps checking for the answer to the menu function
        {
                cout << "1)      Determine whether a list of numbers are pairwise coprime." << endl
                << "2)      List all elements of a congruence class A less than Y modulo n." << endl
                << "3)      Find the number X that solves the Chinese Remainder Theorem for two lists of moduli and remainders." << endl
                << "4)      Quit" << endl
                << "Input: ";
                cin >> answer; // Takes in the input

                switch(answer) //Answer then is split up
                {
                        case 1:
                                cout << endl;
                                cout << "Enter in how many numbers to calculate the coprimality from:" << endl;
                                cin >> amount;//takes in the variable
                                cout << "Enter the numbers to be compared:" << endl;
                                for (i = 0; i < amount; i++)
                                {
                                        cin >> inputvect[i]; //takes in the variable
                                }
                                result = coprimality(inputvect, amount); //Sets the result to true or false
                                switch(result) // Reads out whether its true or false
                                {
                                        case 0:
                                                cout << "The series is not coprime." << endl;
                                                break;
                                        case 1:
                                                cout << "The series is coprime." << endl;
                                                break;
                                }
                                cout << endl;
                                break;

                        case 2:
                                cout << endl;
                                cout << "What is the class?" <<endl;
                                cin >> classs;//takes in the variable
                                cout << "What is the modulo?" <<endl;
                                cin >> modulo;//takes in the variable
                                cout << "What is the cutoff?" <<endl;
                                cin >> cutoff;//takes in the variable

                                results = congruence(classs,modulo,cutoff); // assigns the congruence toa local vector

                                cout << endl;
                                cout <<"{";
                                for(i = 0; i <= results.size() - 2; i++)
                                {
                                cout << results[i] << " ";  // Reads out the result of the congruence vector
                                }
                                cout <<"}";
                                cout << endl;
                                cout << endl;
                                break;
                        case 3:
                                cout << endl;
                                cout << "Enter in how many numbers to calculate the Remainder from:" << endl;
                                cin >> amount;
                                cout << "What is the number series you would like to be the moduli?" << endl;
                                for (i = 0; i < amount; i++)
                                {
                                        cin >> inputvect[i]; //takes in the variable
                                }
                                cout << "What are the remainders you would like to use?(Same order as the moduli entered)" << endl;
                                for(i = 0; i < amount; i++)
                                {
                                        cin >> inputvect2[i]; //takes in the variable
                                }
                                cout << endl;
                                cout << (CRT(inputvect,inputvect2,amount)) << endl; // Reads out the result of the CRT
                                cout << endl;
                                break;
                        case 4:
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