#include <iostream>

using namespace std;

/* 
Make a two player tic tac toe game.

★ Modify the program so that it will announce when a player has won the game 
(and which player won, x or o)

★★ Modify the program so that it is a one player game against the computer 
(with the computer making its moves randomly)

★★★★ Modify the program so that anytime the player is about to win 
(aka, they have 2 of 3 x's in a row, the computer will block w/ an o) */


void Output_Board(string board[3][3])                               //Output the game board
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }    
}

string Check_Winner(string board[3][3])                             // Check to see if there is 3 in a row, return x or o if there is a winner
{
    int Hwinner,Vwinner;                                            //two counters for Horizontal and Vertical win conditions
    for(int i = 0; i < 3; i++)                                      //iterate through the game board counting x`s and o`s
    {
        Hwinner = 0,Vwinner = 0;
        for(int j = 0; j < 3; j++)                                  //iterate looking for horizontal win conditions
        {
            if(board[i][j] == "x")                                  //increment Hwinner towards 3 for x`s
            {
                Hwinner++;
            }
            else if(board[i][j] == "o")                             //increment Hwinner towards -3 for o`s
            {
                Hwinner--;
            }
            switch(Hwinner)                                         //if Hwinner == 3 or -3, return x or o respectively
                {
                    case 3: 
                        return "x";
                    case -3:
                        return "o";
                }
        }
        for(int j = 0; j < 3; j++)                                  //iterate looking for vertical win conditions
        {
            if(board[j][i] == "x")                                  //increment Vwinner towards 3 for x`s
            {
                Vwinner++;
            }
            else if(board[j][i] == "o")                             //decrement Vwinner towards -3 for o`s
            {
                Vwinner--;
            }
            switch(Vwinner)                                         //if Vwinner == 3 or -3, return x or o respectively
                {
                    case 3:
                        return "x";
                    case -3:
                        return "o";
                }
        }
    }
    if(board[1][1] == "x")                                          // Check for diagonal win
    {
        if((board[0][0] == "x" && board[2][2] == "x") || (board[0][2] == "x" && 
        board[2][0] == "x"))
        {
            return "x";
        }
    }
    else if(board[1][1] == "o")                                     //Check for diagonal win
    {
        if((board[0][0] == "o" && board[2][2] == "o") || (board[0][2] == "o" && 
        board[2][0] == "o"))
        {
            return "o";
        }        
    }
    
    return ".";
}

void Computer_Turn(string board[3][3], int turn)                //Computer chooses a random open spot
{
    cout << "Computer`s move." << endl;
    srand(time(NULL));
    int comp_row, comp_col;
    do
    {
        comp_row = rand() % 3;                                  //pseudo random row and col 
        comp_col = (rand() * 7) % 3;
        if(board[comp_row][comp_col] == ".")                    //only if the spot is open
        {
            if(turn == 0)                                       //based on player`s choice of x or y
            {
                board[comp_row][comp_col] = "o";
                break;
            }
            else if(turn == 1)
            {
                board[comp_row][comp_col] = "x";
                break;
            }
        }
    } 
    while(board[comp_row][comp_col] != "x" || board[comp_row][comp_col] != "o");
    Output_Board(board);
}

void HComputer_Turn(string board[3][3], int turn);              //iterate through the board looking for 2 pts
                                                                //when 2 points are found, input the x or o into the empty spot
                                                                

void PvP(string board[3][3], int turn)                                 //takes in the play, then updates the game board (PvP)
{
    int row, col;
    do 
    {
        cout << "Player " << turn % 2 + 1 << " please choose the row and column to play."    //take input
        << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        
        if((col <= 0 || col > 3) || (row <= 0 || row > 3)               //the input must be within 1-3 and 
        || board[row - 1][col - 1] == "x" || board[row - 1][col - 1]    //there must not already be an existing play
        == "o")
        {
            cout << "Invalid play." << endl;
        }
    }
    while ((col <= 0 || col > 3) || (row <= 0 || row > 3)
        ||board[row - 1][col - 1] == "x" || board[row - 1][col - 1]
        == "o");
    if(turn % 2 == 0)                                                                        // updates game board depending on the turn
    {
        board[row - 1][col - 1] = "x"; 
    }   
    else
    {
        board[row - 1][col - 1] = "o";
    }
    Output_Board(board);

}


int main()
{
    string tictactoe[3][3] ={{".", ".", "."}, {".", ".", "."}, {".", ".", "."}};                    //empty board
    int human, counter = 0;
    cout << "Press 1 to play against the AI or press 2 to play against a friend." << endl;
    cin >> human;
    if(human == 1) //Play against AI
    {
        do
        {
            cout << "0 for x`s and 1 for o`s" << endl;      //choose x`s or o`s
            cin >> counter;
            if(counter != 0 && counter != 1)
            {
                cout << "Invalid." << endl;
            }
        } while (counter != 0 && counter != 1);
        if(counter == 0)                                    //if x`s chosen
        {
            Output_Board(tictactoe);
            for(int i = 0; i < 5; i++)                      //maximum of 5 turns
            {
                PvP(tictactoe, counter);
                Computer_Turn(tictactoe, counter);
                if(Check_Winner(tictactoe) == "x")
                {
                    cout << "You Win!" << endl;     
                    break;
                }
                else if(Check_Winner(tictactoe) == "o")
                {
                    cout << "You Lose." << endl;
                    break;
                }
            }
        }
        else if(counter == 1)
        {
            for(int i = 0; i < 4; i++)                      //maximum of 4 user turns
            {
                Computer_Turn(tictactoe, counter);
                PvP(tictactoe, counter);
                if(Check_Winner(tictactoe) == "x")
                {
                    cout << "You Lose." << endl;
                    break;
                }
                else if(Check_Winner(tictactoe) == "o")
                {
                    cout << "You Win!" << endl;
                    break;
                }
            }
            Computer_Turn(tictactoe, counter);              //one last computer turn and check for loss
            if(Check_Winner(tictactoe) == "x")
            {
                cout << "You Lose." << endl;
            }
        }
    }
    else if(human == 2)//Play against friend
    {
        Output_Board(tictactoe);
        for(int i = 0; i < 9; i++)                          //maximum of 9 turns
        {
            PvP(tictactoe, counter);
            counter++;
            if(Check_Winner(tictactoe) == "x")
            {
                cout << "Player 1 wins!" << endl;
                break;
            }
            else if(Check_Winner(tictactoe) == "o")
            {
                cout << "Player 2 wins!" << endl;
                break;
            }
        }
    }
    return 0;
}