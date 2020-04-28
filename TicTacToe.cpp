/*
 * TicTacToe.cpp - Implementation of TicTacToe class
 * A derived class of the Game class, this class will allow a TicTacToe game to 
 * be played.
 */

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
    grid = new char*[rows];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            grid[i] = new char[columns];
        }
    }
    
    for(int i = 0; i < rows; i ++)
    {
        for(int j = 0; j < columns; j ++)
        {
            grid[i][j] = 'E'; // E is empty
        }
    }
}

void TicTacToe::printGameGrid()const
{
    char output;
    std::cout << "  0  1  2\n";
    for(int i = 0; i < rows; i ++)
    {
        std::cout << i << " ";
        for(int j = 0; j < columns; j++)
        {            
            if(grid[i][j] == 'E')
            {
                output = '-';
            }
            else
            {
                output = grid[i][j];
            }
            std::cout << output << "  ";
        }
        std::cout << "\n";
    }
}

void TicTacToe::computerMove()
{
    std::cout<<"It's the computer's turn...\n";
    bool moveMade = false;
    while(!moveMade)
    {
        srand(time(NULL));
        int x = rand() % 3;
        int y = rand() % 3; 
        
        if(grid[x][y] == 'E')
        {
            grid[x][y] = 'O';
            moveMade = true;
            std::cout<< "The computer put an 'O' at " << x << ", " << y << std::endl;
        }
        
        if(isGridFull())
        {
            break;
        }
    } 
    std::cout << std::endl;
    printGameGrid();
    std::cout << std::endl;
}

void TicTacToe::humanMove()
{
    std::cout << "It's your turn...\n";
    bool validMove = false;
    
    while(validMove == false)
    {
    
        int x,y;
        std::cout << "Please enter the row for your move: ";
        std::cin >> x;
        std::cout<< "Please enter the column for your move: ";
        std::cin >> y;
        
        if(isSpaceOpen(x,y))
        {
            grid[x][y] = 'X';
            validMove = true;
            break;
        }
        else
        {
            std::cout << "That is not a valid move! Try again!\n";
        }
        
    } 
    
    std::cout << std::endl;
    printGameGrid();
    std::cout << std::endl;
}
/**
 * I really tried to make this more efficient and elegant, but I just couldn't 
 * come up with anything. So I left it like this. This DOES work. It's just ugly.
 */
bool TicTacToe::isGameOver()const
{
    if((grid[0][0] == grid[0][1]) && (grid[0][1] == grid[0][2]) && (grid[0][0] != 'E'))
    {
        return true;
    }
    else if((grid[1][0] == grid[1][1]) &&(grid[1][1] == grid[1][2]) && grid[1][0] != 'E')
    {
        return true;
    }
   
    else if((grid[2][0] == grid[2][1]) && (grid[2][1] == grid[2][2]) && grid[2][0] != 'E')
    {
        return true;
    }
    else if((grid[0][0] == grid[1][0]) && (grid[1][0] == grid[2][0]) && grid[0][0] != 'E')
    {
        return true;
    }
    else if((grid[0][1] == grid[1][1]) && (grid[1][1] == grid[2][1]) && grid[0][1] != 'E')
    {
        return true;
    }
    else if((grid[0][2] == grid[1][2]) && (grid[1][2] == grid[2][2]) && grid[0][2] != 'E')
    {
        return true;
    }
    else if((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) && grid[0][0] != 'E')
    {
        return true;
    }
    else if((grid[2][0] == grid[1][1]) && (grid[1][1] == grid[0][2]) && grid[2][0] != 'E')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::isTie()const
{
    if(isGridFull() && !isGameOver())
    {
        return true;
    }
    return false;
}

