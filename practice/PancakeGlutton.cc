#include <iostream>
using namespace std;

/* Write a program that asks the user to enter the number of pancakes eaten for breakfast by
10 different people (Person 1, Person 2, ..., Person 10) Once the data has been entered the 
program must analyze the data and output which person ate the most pancakes for breakfast.

★ Modify the program so that it also outputs which person ate the least number of pancakes
for breakfast.

★★★★ Modify the program so that it outputs a list in order of number of pancakes eaten of
all 10 people.

i.e.
Person 4: ate 10 pancakes
Person 3: ate 7 pancakes
Person 8: ate 4 pancakes
...
Person 5: ate 0 pancakes */

int main ()
{
    int pancakes [10];
    int eaten_pancakes;
    
    for(int i = 0; i < 10; i++)
    {
        cout << "Enter the number of pancakes eaten by person " << i + 1 << "."
        << endl;
        cin >> pancakes[i];
    }
    
    //Who ate the most pancakes?
    int largest = pancakes[0];
    int person = 1;
    for(int i = 1; i < 10; i++)
    {
        if(largest < pancakes[i])
        {
            largest = pancakes[i];
            person = i + 1;
        }
    }
    cout << "Person " << person << " ate the most pancakes!" << endl;
    
    //Who ate the least pancakes??
    int least = pancakes[0];
    int lperson = 1;
    for(int i = 1; i < 10; i++)
    {
        if(least > pancakes[i])
        {
            least = pancakes[i];
            lperson = i + 1;
        }
    }
    cout << "Person " << lperson << " ate the least pancakes!" << endl;
    
    //Output how many pancakes each person ate
    for(int i = 0; i < 10; i++)
    {
        cout << "Person " << i + 1 << " ate " << pancakes[i] << " pancakes!" 
        << endl;
    }
    return 0;
}