#ifndef PLAYER_H
#define PLAYER_H

/*
@file player.h
	Represents the player and the statistics and methods that make up the player.
@author AA*/

#include <iostream>

class Player{
		public:

		/*Player Object Constructor
		@param None..
		@pre None.
		@post None
		@return Returns a Player object to represent the player stats. By 			default:
					lifeCount = 5; topLevel =3; correctCount = 0*/
		Player();

		/*getLevel method
		@param None.
		@pre None.
		@post None.
		@return Positive integer of current level the player has reached.*/
		unsigned int getLevel();

		/*getLife method
		@param None.
		@pre None.
		@post None.
		@return Positive integer of life lines the player has left.*/
		unsigned int getLife();

		/*getCorrect method
		@param None.
		@pre None.
		@post None.
		@return Positive integer of correct guesses the player has made.*/
		unsigned int getCorrect();

		/*levelUp method
		@param None.
		@pre None.
		@post None.
		@return Increase the level of the player by 1.*/
		void levelUp();

		/*useLife method
		@param None.
		@pre Must be greater than or equal to 1.
		@post None.
		@return Reduce the number of life lines the player has.*/
		void useLife();

		/*correctUp method
		@param None.
		@pre None.
		@post None.
		@return Increase the player's correct guess count by 1.*/
		void correctUp();

		/*guessUp method
		@param None.
		@pre None.
		@post Will always be set to 0. 
		@return Set the correct guess count by 0.*/
		void countReset();

	private:
		/*the highest level of difficulty the player has reached, set to 3 when starting a new game*/
		unsigned int topLevel;

		/*the number of lifelines the player has in the current game, set to 5 when starting a new game*/
		unsigned int lifeCount;

		/*the number of correct words the player has made*/
		unsigned int correctCount; 
};

#endif
