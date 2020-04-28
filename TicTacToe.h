/*
 * TicTacToe.h
 * A derived class of the Game class, this class will allow a TicTacToe game to 
 * be played. In this game, the computer's moves will be represented by 'O' and
 * the human's moves will be represented by 'X'. Empty Space will be represented
 * internally in the program array by the character 'E'.
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
         * element equal to 'E' for empty space. 
         */
        TicTacToe();
        virtual void displayOpeningMessage()const
        {
            std::cout<< "Welcome to Tic-Tac-Toe!\n\n"
                     << "The game board is arranged in 3 columns and 3 rows,\n" 
                     << "numbered from 0-3, like this: \n"
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
        }
        virtual void displayOutgoingMessage()const
        {
            std::cout << std::endl << std::endl << std::endl;
            std::cout << "FINAL GAME GRID: \n";
            printGameGrid();
            std::cout << std::endl << std::endl;
            std::cout << "Programmer: Brett Bernardi\n\n";
        }
        //virtual void displayMessage()const;
        virtual void computerMove();
        virtual void humanMove();
        virtual bool isGameOver();
        /**
         * Post-condition: returns true if game is completely 
         */
        virtual bool isTie();
        
        
    private:
        int rows;
        int columns;
        char **grid;
        
        bool isSpaceOpen(int x, int y)const
        {
            return grid[x][y] == 'E';
        }
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
        void printGameGrid()const;
};

#endif /* TICTACTOE_H */

