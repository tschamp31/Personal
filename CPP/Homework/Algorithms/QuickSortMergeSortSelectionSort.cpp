#include <iostream> //Declare headers
#include <cmath>
#include <vector>

using namespace std;

class Sort  //Initialize class Sort
{
public: //Declare following as a public
void SelectionSort(vector<int> v);  //Declare function SelectionSort
void QuickSort(int z[],int first,int last); //Declare function QuickSort 
int pivot(int z[],int first,int last);  //Declare function pivot used for funciton QuickSort
void merge(int y[],int first,int mid,int last, vector<int> v);  //Declare function merge used for function MergeSort
void MergeSort(int y[], int first, int last, vector<int> v)  ;   //Declare function MergeSort
void swap(int& a, int& b);  //Declare function swap used for SelectionSort and Quicksort
};

void Sort::SelectionSort(vector<int> v) //Function to sort the values in an array using the Selection Sort method
{
int i, j, first, temp;
int numLength = v.size();

      for (i = numLength - 1; i > 0; i--)   //For loop to determine 
      {
            first = 0;  //Initialize to subscript of first element
            for (j = 1; j <= i; j++)    //Locate smallest between positions 1 and i.
            {
                if (v[j] > v[first])    //If statement to swap values
                first = j;
            }
            swap(v[first], v[i]);   //Calls function swap to assign value of lowest to the next in line element in vector
      }

     for (int i = 0; i < v.size(); i++) //Outputs the newly sorted vector to screen
     {
        cout << v[i] << ' ';
     }

}

void Sort::QuickSort(int z[], int first, int last)  //Function to sort values in an array using the Quick Sort method
{
    int pivotElement;   //Initialize variable pivotElement

    if (first < last)   //If statement to continue running as long as the variable first is less than the variable last, calling itself 
    {
        pivotElement = pivot(z, first, last);   //Calls function pivot and assigns returned value to variable pivotElement
        QuickSort(z, first, pivotElement - 1);  //Calls (itself) function QuickSort to Sort the Left array
        QuickSort(z, pivotElement+1, last); //Calls (itself) function QuickSort to Sort the Right array
    }
}

int Sort::pivot(int z[], int first, int last)   //Function to return value to function QuickSort
{
    int temp, a, b, c, pivotElement;    //Initialize local variables
    c = first;  //Assign local variables
    pivotElement = z[first];
 
    for(int i = first + 1 ; i <= last ; i++)    //For loop to determine the pivot point
    {
        if(z[i] <= pivotElement)    //If statement to continue running as long as the variable in array z is less than the variable pivotElement
        {
            c++;
            swap(z[i], z[c]);   //Calls function swap to swap values
        }
    }
    swap(z[c], z[first]);   //Calls function swap to swap values
    return c;   //Returns value c
}

void Sort::MergeSort(int y[], int first, int last, vector<int> v)   //Function to sort values in an array using the Merge Sort method
{
int mid;    //Initialize local variable mid

    if (first < last)   //If statement to continue as long as variable first is less than variable last
    {
        mid = (first + last) / 2;   //Assigns value to variable mid
        MergeSort(y, first, mid,v); //Calls (itself) function MergeSort
        MergeSort(y, mid + 1, last, v); //Calls (itself) function MergeSort
        merge(y, first, mid, last, v);  //Calls function merge
    }
}

void Sort::merge(int y[], int first, int mid, int last, vector<int> v)
{
int a, b, c, d[10], e;  //Initialize variables and array;

a = first;  //Assign value to variable a
b = first;  //Assign value to variable b
c = mid + 1;    //Assign value to variable c

    while((a <= mid) && (c <= last))    //While statement to assign value to array d
    {
        if(y[a] <= y[c])    //If statement to continue the if variable a in array y is less than variable c in array y
        {
            d[b] = y[a];    //Assign value of variable a in array y to empty array d
            a++;    //Increment variable a
        }
        else
        {
            d[b] = y[c];    //Assign value of variable c in array y to empty array d
            c++;    //Increment variable c
        }
        b++;    //Increment variable b ( for while function ) 
    }

    if(a > mid) //If statement to run if the condition variable a is greater than or less than variable mid
    {
        for(e = c; e <= last; e++)  //For statement to assign value of variable e in array y to array d
        {
            d[b] = y[e];
            b++;    //Increment variable b
        }
    }

    else
    {
        for(e = a; e <= mid; e++)   //For statement to assign value of variable e in array y to array d
        {
            d[b] = y[e];
            b++;    //Increment variable b
        }
    }

    for(e = first; e <= last ;e++)  //For statement to assign values of array d to array y
    { 
        y[e] = d[e];
    }
}

void Sort::swap(int& a, int& b) //Function to swap values
{
    int temp = a;   //Initialize and assign value to local variable
    a = b;  //Swap values and return swapped values
    b = temp;
}

int main()
{
int i, last, last1, last2, last3, last4;    //Initialize variables
vector<int> v(10);  //Initialize vector v
int size;
int answer;

cout<< "Please Enter 1-5 for the array size(10-10000)"<<endl;
cin>>answer;
switch (answer)
{
case 1: size = 10;
    break;
case 2: size = 100;
    break;
case 3: size = 1000;
    break;
case 4: size = 10000;
    break;
case 5: size = 100000;
    break;
}

cout << "Test case of 10 integers: " << endl;

    for (int i = 0; i < v.size(); i++)  //Assign random integer values from 1-10 to vector v
    {
        v[i] = (rand() %size + 1);
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    int z[10];  //Initialize array z, z1, z2, z3, z4

    for (int i = 0; i < v.size(); i++)  //Assign values of vector v into array z
{
z[i] = v[i];

    }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int y[10];  //Initialize test case arrays y
    for (int i = 0; i < v.size(); i++)  //Assign values of vector v into array z
    {
y[i] = v[i];
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout << "The random integers between 1 and 10 are: " << endl;   //Output values of the vector that need to be sorted
    for (int i = 0; i < v.size(); i++)  //For loop to output values to screen
    {
        cout << v[i] << ' ';
    }
last = sizeof(z)/sizeof(int);   //Assign value to last

size = 10;
Sort Sort;  //Initialize Sort class variable Sort
cout << endl;

cout << "The sorted values by the Selection Sort are: " << endl;
Sort.SelectionSort(v);  //Call class function SelectionSort
cout << endl;

cout << "The sorted values by the Quick Sort are: " << endl;
Sort.QuickSort(z,0,last-1);
for (int i = 0; i < v.size(); i++)  //For loop to output values to screen
{
cout << z[i] << ' ';
}
cout << endl;
cout << "The sorted values by the Merge Sort are: " << endl;
Sort.MergeSort(y,0 ,last-1, v); //Call class function MergeSort
for (int i = 0; i < v.size(); i++)  //For loop to output values to screen
{
cout << y[i] << ' ';
}
cout << endl;
cout << endl;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


return 0;
    
}