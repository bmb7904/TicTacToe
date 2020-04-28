/*
 * Game.h
 * A game class that will serve as a model for a two-player, turn based, game. 
 * Comes with pure virtual functions that must be overridden. This game has some
 * the possibility of being a tie. 
 */
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <iostream>

class Game {
    public:
        enum who{HUMAN, TIE, COMPUTER}; // enum list represents whose turn it is
        Game(int numMoves = 0);
        /**
         * The main function that controls the game. 
         * Post-condition: Will return an enum(human, computer, neutral) when the
         * game is over. Whoever is return is the winner. If TIE is returned,
         * the game is a tie. 
         */
        who play();
        void virtual displayOpeningMessage()const = 0;
        virtual void computerMove() = 0;
        virtual void humanMove() = 0;
        virtual bool isGameOver() = 0;
        virtual void displayOutgoingMessage()const = 0;
        /**
         * Post-condition: returns true if game is completely 
         */
        virtual bool isTie() = 0;
        int getNumberOfMovesMade()const;
        ~Game();
        
    private:
        int numberOfMoves;

};

#endif /* GAME_H */

