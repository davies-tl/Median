/*
Program name: Median.cpp
Programmer: Tyler Davies
Date: 9-11-21
Version: 1.0
Description: This program focuses on a function which accepts an array of integers and an integer indicating
             the number of elements in the array. Assuming that the values are already sorted, the function
             returns the median of the values as a double. The main function's only purpose is to test the 
             Median function; it creates two arrays (one even and one odd), and passes them each with their
             size to the Median function. It then prints out the resulting doubles.
*/

#include<iostream>
#include<iomanip>

using namespace std;

//Function prototype (parameter variable names not required in the prototype).
double Median(int*, int);

//Main function is only included to test the Median function.
int main ()
{
    int evenArray[] = { 2, 4, 6, 8, 10, 12, 14, 16 };
    int oddArray[] = { 1, 3, 5, 7, 9, 11, 13 };
    int evenSize = 8, oddSize = 7;
    double evenResult, oddResult;

    evenResult = Median(evenArray, evenSize);
    oddResult = Median(oddArray, oddSize);

    cout << showpoint << fixed << setprecision(1);
    cout << "The median of the even array is: " << evenResult << endl;
    cout << "The median of the odd array is: " << oddResult << endl;

    exit(0);
}

/*
This function accepts an array and an integer indicating the number of elements in the array.
It returns the median value of the array: For odd number of values, it returns the middle value;
for even number of values, it returns the average of the two middle values. This functions uses
pointer notation instead of array notation.
*/
double Median(int *arr, int size)
{
    int middle = size / 2;
    /*
    Since array indexes start at 0, middle holds the middle index. For an array with even numbers,
    we also need (middle - 1) to get the two middle values. It is important to note that an integer
    is okay here, because odd number sizes will need to be rounded down (Example: for an array size
    of 5, integer division will produce 2 instead of 2.5; and 2 is the actual middle index).
    */
    double median;

    if ((size % 2) == 0)    //even
        median = (static_cast<double>(*(arr + middle)) + static_cast<double>(*(arr + (middle - 1)))) / 2.0;
    else                    //odd
        median = static_cast<double>(*(arr + middle));

    return median;
}