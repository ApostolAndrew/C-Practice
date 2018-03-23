#include <iostream>
using namespace std;

/* Write a program that calculates a random number 1 through 100. The program then 
asks the user to guess the number. If the user guesses too high or too low then the 
program should output "too high" or "too low" accordingly. The program must let the 
user continue to guess until the user correctly guesses the number.

★ Modify the program to output how many guesses it took the user to correctly guess 
the right number.

★★ Modify the program so that instead of the user guessing a number the computer 
came up with, the computer guesses the number that the user has secretely decided.
The user must tell the computer whether it guesed too high or too low.

★★★★ Modify the program so that no matter what number the user thinks of (1-100) 
the computer can guess it in 7 or less guesses. */

int main ()
{
    /*srand(time(NULL));
    int Random_Num = rand() % 100 + 1;
    int guess = 0;
    int number_guesses = 0;
    while(guess != Random_Num)
    {
        cout << "Please guess a number between 1 and 100." << endl;
        cin >> guess;
        number_guesses++;
        if(guess < Random_Num)
        {
            cout << "Too low." << endl;
        }
        else if(guess > Random_Num)
        {
            cout << "Too high." << endl;
        }
    }
    cout << "Correct!" << endl;
    cout << "It took " << number_guesses << " guesses to get the answer." << endl; */
    
    //Computer guesses the number
    int Comp_Guess = 50;
    int updater = 25;
    string user_number = "";
    do
    {
        cout << "Is the number " << Comp_Guess << "?" << endl;
        getline(cin,user_number);
        if(user_number == "too low")
        {
            Comp_Guess = updater + Comp_Guess; 
        }
        else if(user_number == "too high")
        {
            Comp_Guess = Comp_Guess - updater;
        }
        updater = updater / 2;
        if(updater == 0)updater++;

    } while(user_number != "correct" && user_number != "Correct");
    return 0;
}