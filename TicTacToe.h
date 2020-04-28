/*
 * TicTacToe.h
 * A derived class of the Game class, this class will allow a TicTacToe game to 
 * be played. In this game, the computer's moves will be represented by 'O' and
 * the human's moves will be represented by 'X'. Empty Space will be represented
 * internally in the program array (Game grid) by the character 'E'. This class 
 * contains methods for making moves, displaying the state of the game, and 
 * checking if the game won or tied. Works in tandem with the Game class.
 * 
 * @author Brett Bernardi
 * 
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Game.h"

class TicTacToe: public Game 
{
    public:
        /*
         * Constructor. Initializes the two dimensional array and sets each 
         * element equal to 'E' for empty space to initialize each element in
         * the array.
         */
        TicTacToe();
        /**
         * Post-condition: displays a message explaining the game.
         */
        virtual void displayOpeningMessage()const
        {
            //Game::displayOpeningMessage();
            std::cout<< "Welcome to Tic-Tac-Toe!\n\n"
                     << "The game board is arranged in 3 columns and 3 rows,\n" 
                     << "numbered from 0-2, like this: \n"
                     << "  0 1 2\n"
                     << "0 X X O\n"
                     << "1 O X O\n"
                     << "2 X O X\n\n\n"
                     << "You will play against the computer. The computer\n"
                     << "is the letter O and you are X. When it is your turn, simply\n"
                     << "type in the row number, followed by the column number of where \n"
                     << "you want to place your X.\n\n\n"
                     << "First one to get three in a row wins! Good luck! \n\n\n";
            
            printGameGrid();
            std::cout<<std::endl;
        }
        /**
         * Displays a message and prints the game grid in case of a tie
         */
        virtual void displayOutgoingMessage()const
        {
            std::cout << std::endl << std::endl << std::endl;
            std::cout << "FINAL GAME GRID: \n";
            printGameGrid();
            std::cout << std::endl << std::endl;
        }
        
        /**
         * Overrides Game function. 
         * Post-condition: The computer place O on the grid, if allowed.
         */
        virtual void computerMove();
        /**
         * overrides Game function
         * Post-condition: Takes input from user and places X on grid, if allowed and
         * legal.
         */
        virtual void humanMove();
        /**
         * overrides Game function
         * Post-condition: checks the game grid (2D array) to see if there are
         * any winning combinations. IF there is a winning combination, return
         * true. returns false otherwise.
         */
        virtual bool isGameOver()const;
        /**
         * Post-condition: returns true if gameGrid is completely full of X's and 
         * O's and there is NOT a winning combination. 
         */
        virtual bool isTie()const;
        
        
    private:
        const static int rows = 3;
        const static int columns = 3;
        // represents the game grid.
        char **grid;
        
        /**
         * Private helper function.
         * Checks the row and column parameters, and returns true if the 
         * (i,j) combination is a valid place in the game grid. 
         */
        bool isSpaceOpen(int i, int j)const
        {
            if( i >= rows || i < 0 || j >= columns || j < 0)
            {
                return false;
            }
            return grid[i][j] == 'E';
        }
        /**
         * Private helper method. 
         * Post-conditions: if grid has no empty spaces, returns true. False 
         * otherwise.
         */
        bool isGridFull()const
        {
            for(int i = 0; i < rows; i ++)
            {
                for(int j = 0; j < columns; j++)
                {
                    if(grid[i][j] == 'E')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        /**
         * Private  helper method
         * Post-condition: prints out state of game grid.
         */
        void printGameGrid()const;
};

#endif /* TICTACTOE_H */

