#include <iostream>
using namespace std;

/* print out a table that goes from the start temperature to the end temperature,
in steps of the step size; you do not actually need to print the final end temperature
if the step size does not exactly match. You should perform input validation:
do not accept start temperatures less tahn a lower limit or higher than an upper limit.
You should not allow a step size greater than the difference in temperatures*/

int main()
{
    int llim, ulim, steps;
    do {
    cout << "Please give in a lower limit, limit >= 0: ";
    cin >> llim;
    cout << endl;
    }
    while (llim < 0);
    do {
    cout << "Please give in a higher limit, limit 10 > limit <= 50000: ";
    cin >> ulim;
    cout << endl; 
    }
    while (ulim <= 10 || ulim > 50000);
    do {
    cout << "Please give in a step, 0 < step <= 10: ";
    cin >> steps;
    cout << endl;
    }
    while (steps <= 0  || steps > 10);
    cout << "Celcius" << endl << "----------" << endl;
   for(int i = llim; i <= ulim; i += steps)
    {
        cout << i << endl;
    }
    
    
    return 0;
}