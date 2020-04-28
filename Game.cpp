/**
 * A game class that will serve as a model for a two-player, turn based, game. 
 * Comes with pure virtual functions that must be overridden. 
 */

#include "Game.h"


Game::Game()
{
    
}

Game::who Game::play()
{
    /*
     * if turn == 0, it's the computer's turn to move
     * if turn == 1, it's the human's turn to move. 
     */
    displayOpeningMessage();
    srand(time(NULL)); // seeds the rand num generator
    int turn = (rand() % 2); // returns a randomly generated integer [0,1]
    if(turn == 0) //
    {
        std::cout << "The Computer Goes First.\n";
    }
    else 
    {
        std::cout<< "You Go First.\n";
    }
    
    std::cout << std::endl << std::endl;
    
    // the main game loop that runs until the game is over
    while(true)
    {
        while(isTie() == false)
        {
            // First, let whose turn it is to make their move. 
            if(turn == 0)
            {
                computerMove();
            }
            else
            {
                humanMove();
            }

            // After move is made, check if game is won. If game is won, whoever just
            // made the move (whose turn it is) is the winner of the game. Return 
            // the winner of the game.
            if((isGameOver() == true) && (turn == 0))
            {
                return Game::COMPUTER;
            }
            if((isGameOver() == true) && (turn == 1))
            {
                return Game::HUMAN;
            }
            
            // if there are no winners, switch turn back to the other player
            (turn == 0)?(turn = 1):(turn = 0);
        }
        
        // if it gets to this point, the game is a tie.
        displayOutgoingMessage();
        return Game::TIE;
    }
}
// At this point, we don't know what type of game we are playing. So print out
// vague message.
void Game::displayOpeningMessage()const
{
    std::cout << "Welcome to the game!"  << std::endl; 
}

Game::~Game()
{
    
}
