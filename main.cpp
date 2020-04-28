
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
        cout << "The computer has won the game!\n";
    }
    else if(whoWon==Game::HUMAN)
    {
        cout << "You have won the game!";
    }
    else // this must be Game::Tie
    {
        cout << "The game ended in a tie!";
    }
    
    cout << endl << "Programmer: Brett Bernardi\n";


    return 0;
}

