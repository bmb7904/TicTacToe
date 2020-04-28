/*
 *                  Homework 8
 * 
 */
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "TicTacToe.h"

using namespace std;

int main(int argc, char** argv) {

    Game *game = new TicTacToe();
    Game::who whoWon= game->play();
    if(whoWon== Game::COMPUTER)
    {
        cout << "The computer has won the game!\n"
             << "Try again next time!\n";  ;
    }
    else if(whoWon==Game::HUMAN)
    {
        cout << "You have won the game!";
    }
    else // this must be Game::Tie
    {
        cout << "The game ended in a tie!";
    }
    
    cout << endl << endl << "Programmer: Brett Bernardi" << endl;


    return 0;
}

