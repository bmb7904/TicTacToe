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

        enum who {HUMAN, TIE, COMPUTER}; // enum list represents whose turn it is
        /*
         * constructor. No arguments.
         */
        Game();
        /**
         * The main function that controls the game. 
         * Post-condition: Will return an enum(human, computer, neutral) when the
         * game is over. Whoever is return is the winner. If TIE is returned,
         * the game is a tie. 
         */
        who play();
        /*
         * Postconditon: a message describes the game has been displayed.
         */
        void virtual displayOpeningMessage()const = 0;
        /*
         *Postcondtition: The computer has made its move
         */
        virtual void computerMove() = 0;
        /*
         * Postcondtion: The human has made his/her move
         */
        virtual void humanMove() = 0;
        /*
         * Postcondtion: true value has been returned if game is over
         *               false is returned otherwise
         */
        virtual bool isGameOver()const = 0;
        /*
         * Postconditon: a message describes the end of the game has been displayed.
         */
        virtual void displayOutgoingMessage()const = 0;
        /**
         * Post-condition: returns true if game results in a tie
         */
        virtual bool isTie()const = 0;
        /*
         * Destructor
         */
        ~Game();

    private:

};

#endif /* GAME_H */

