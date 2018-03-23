#include <iostream>

/*Write a program that presents the user w/ a choice of your 5 favorite beverages (Coke, Water, Sprite, ... , Whatever).
Then allow the user to choose a beverage by entering a number 1-5.
Output which beverage they chose.

★ If you program uses if statements instead of a switch statement, modify it to use a switch statement.
If instead your program uses a switch statement, modify it to use if/else-if statements.

★★ Modify the program so that if the user enters a choice other than 1-5 then it will output "Error. choice was not valid, here is your money back."*/

int main()
{
    int choice;
    //Output the options 
    std::cout << "Please Choose A Beverage by Inputting a Number." << std::endl << 
    "1. Coke." << std::endl << "2. Sprite." << std::endl <<
    "3. Cherry Coke." << std::endl << "4. Dr. Pepper."<< std::endl <<
    "5. Water." << std::endl;
    std::cin >> choice;
    switch (choice)     //Output the choice of beverage
    {
        case 1:
        std::cout << "Dispensing Coke." << std::endl;
        break;
        case 2:
        std::cout << "Dispensing Sprite." << std::endl;
        break;
        case 3: 
        std::cout << "Dispensing Cherry Coke." << std::endl;
        break;
        case 4:
        std::cout << "Dispensing Dr. Pepper." << std::endl;
        break;
        case 5:
        std::cout << "Dispensing Water." << std::endl;
        break;
        default:
        std::cout << "Error. Choice was not valid, here is your money back." << std::endl;
    }
    return 0;
}