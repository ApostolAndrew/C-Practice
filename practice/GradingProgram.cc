#include <iostream>

/*Write a program that allows the user to enter the grade scored in a programming class (0-100).
If the user scored a 100 then notify the user that they got a perfect score.

★ Modify the program so that if the user scored a 90-100 it informs the user that they scored an A

★★ Modify the program so that it will notify the user of their letter grade
0-59 F 60-69 D 70-79 C 80-89 B 90-100 A*/

//COMPLETED

int main()
{
    int grade;
    std::cout << "Input your grade:";
    std::cin >> grade;
    if(grade == 100)
    {
        std::cout << "Perfect Score!" << std::endl;
    }
    else;
    if(grade >= 90 && grade <= 100)
    {
        std::cout << "You scored an A!" << std::endl;
    }
    else;
    if(grade >= 80 && grade < 90)
    {
        std::cout << "You scored a B!" << std::endl;
    }
    else;
        if(grade >= 70 && grade < 80)
    {
        std::cout << "You scored a C." << std::endl;
    }
    else;
    if(grade >= 60 && grade < 70)
    {
        std::cout << "You scored D." << std::endl;
    }
    else;
    if(grade >= 0 && grade < 60)
    {
        std::cout << "You scored an F." << std::endl;
    }
    else;
    return 0;
}