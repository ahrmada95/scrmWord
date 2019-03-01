#include "player.h"

/*
@file player.cpp
	Represents the player and the statistics and methods that make up the player.
@author AA*/

#include <iostream>

/*Player Object Constructor
@param None.
@pre None.
@post None
@return Returns a Player object to represent the player stats. By default:
		lifeCount = 5; topLevel =3; correctCount = 0*/
Player::Player(){
	lifeCount = 5;
	topLevel = 3;
	correctCount = 0;
}

/*getLevel method
@param None.
@param None.
@pre None.
@post None.
@return Positive integer of current level the player has reached.*/
unsigned int Player::getLevel(){
	return topLevel;
}

/*getLife method
@param None.
@param None.
@pre None.
@post None
@return Positive integer of life lines the player has left.*/
unsigned int Player::getLife(){
	return lifeCount;
}

/*getCorrect method
@param None.
@param None.
@pre None.
@post None
@return Positive integer of correct guesses the player has made.*/
unsigned int Player::getCorrect(){
	return correctCount;
}

/*levelUp method
@param None.
@param None.
@pre None.
@post None
@return Increase the level of the player by 1.*/
void Player::levelUp(){
	topLevel++;
}

/*useLife method
@param None.
@param None.
@pre Must be greater than or equal to 1.
@post None
@return Reduce the number of life lines the player has.*/
void Player::useLife(){
	if(lifeCount>=1){
		lifeCount=lifeCount-1;
	}
	else{
		lifeCount=0;
	}
}

/*correctUp method
@param None.
@param None.
@pre None.
@post None.
@return Increase the player's correct guess count by 1.*/
void Player::correctUp(){
	correctCount=correctCount+1;
}

/*guessUp method
@param None.
@param None.
@pre None.
@post Will always be set to 0. 
@return Set the correct guess count by 0.*/
void Player::countReset(){
	correctCount=0;
}


